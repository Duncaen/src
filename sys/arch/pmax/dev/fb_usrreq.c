/*ARGSUSED*/
int
fbopen(dev, flag, mode, p)
	dev_t dev;
	int flag, mode;
	struct proc *p;
{
	register struct fbinfo *fi;

#ifdef fpinitialized
	if (!fp->initialized)
		return (ENXIO);
#endif

	if (minor(dev) >= fbcd.cd_ndevs ||
	    (fi = fbcd.cd_devs[minor(dev)]) == NULL)
	    return(ENXIO);

	if (fi->fi_open)
		return (EBUSY);

	fi->fi_open = 1;

	(*fi->fi_driver->fbd_initcmap)(fi);

	/*
	 * Set up event queue for later
	 */
	pmEventQueueInit(&fi->fi_fbu->scrInfo.qe);
	genConfigMouse();

	return (0);
}

/*ARGSUSED*/
int
fbclose(dev, flag, mode, p)
	dev_t dev;
	int flag, mode;
	struct proc *p;
{
	register struct fbinfo *fi;
	register struct pmax_fbtty *fbtty;

	if (minor(dev) >= fbcd.cd_ndevs ||
	    (fi = fbcd.cd_devs[minor(dev)]) == NULL)
	    return(EBADF);

	if (!fi->fi_open)
		return (EBADF);

	fbtty = fi->fi_glasstty;
	fi->fi_open = 0;
	(*fi->fi_driver->fbd_initcmap)(fi);
	genDeconfigMouse();
	fbScreenInit(fi);

	bzero((caddr_t)fi->fi_pixels, fi->fi_pixelsize);
	(*fi->fi_driver->fbd_poscursor)
		(fi, fbtty->col * 8, fbtty->row * 15);
	return (0);
}

/*ARGSUSED*/
int
fbioctl(dev, cmd, data, flag, p)
	dev_t dev;
	u_long cmd;
	caddr_t data;
	struct proc *p;
{
	register struct fbinfo *fi;
	register struct pmax_fbtty *fbtty;
	char cmap_buf [3];

	if (minor(dev) >= fbcd.cd_ndevs ||
	    (fi = fbcd.cd_devs[minor(dev)]) == NULL)
	    return(EBADF);

	fbtty = fi->fi_glasstty;

	switch (cmd) {

	/*
	 * Ultrix-compatible, pm/qvss-style ioctls(). Mostly
	 * so that X consortium Xservers work.
	 */
	case QIOCGINFO:
		return (fbmmap_fb(fi, dev, data, p));

	case QIOCPMSTATE:
		/*
		 * Set mouse state.
		 */
		fi->fi_fbu->scrInfo.mouse = *(pmCursor *)data;
		(*fi->fi_driver->fbd_poscursor)
			(fi, fi->fi_fbu->scrInfo.mouse.x,
			     fi->fi_fbu->scrInfo.mouse.y);
		break;

	case QIOCINIT:
		/*
		 * Initialize the screen.
		 */
		fbScreenInit(fi);
		break;

	case QIOCKPCMD:
	    {
		pmKpCmd *kpCmdPtr;
		unsigned char *cp;

		kpCmdPtr = (pmKpCmd *)data;
		if (kpCmdPtr->nbytes == 0)
			kpCmdPtr->cmd |= 0x80;
		if (!fi->fi_open)
			kpCmdPtr->cmd |= 1;
		(*fbtty->KBDPutc)(fbtty->kbddev, (int)kpCmdPtr->cmd);
		cp = &kpCmdPtr->par[0];
		for (; kpCmdPtr->nbytes > 0; cp++, kpCmdPtr->nbytes--) {
			if (kpCmdPtr->nbytes == 1)
				*cp |= 0x80;
			(*fbtty->KBDPutc)(fbtty->kbddev, (int)*cp);
		}
		break;
	    }

	case QIOCADDR:
		*(PM_Info **)data = &fi->fi_fbu->scrInfo;
		break;

	case QIOWCURSOR:
		(*fi->fi_driver->fbd_loadcursor)
			(fi, (unsigned short *)data);
		break;

	case QIOWCURSORCOLOR:
		(*fi->fi_driver->fbd_cursorcolor)(fi, (unsigned int *)data);
		break;

	case QIOSETCMAP:
		cmap_buf[0] = ((ColorMap *)data)->Entry.red;
		cmap_buf[1] = ((ColorMap *)data)->Entry.green;
		cmap_buf[2] = ((ColorMap *)data)->Entry.blue;
		(*fi->fi_driver->fbd_putcmap)
			(fi,
			 cmap_buf,
			 ((ColorMap *)data)->index,  1);
		break;

	case QIOKERNLOOP:
		genConfigMouse();
		break;

	case QIOKERNUNLOOP:
		genDeconfigMouse();
		break;

	case QIOVIDEOON:
		(*fi->fi_driver->fbd_unblank) (fi);
		break;

	case QIOVIDEOOFF:
		(*fi->fi_driver->fbd_blank) (fi);
		break;


	/*
	 * Sun-style ioctls, mostly so that screenblank(1) and other
	 * ``native'' NetBSD applications work.
	 */
	case FBIOGTYPE:
		*(struct fbtype *)data = fi->fi_type;
		break;

	case FBIOGETCMAP:
		return ((*(fi->fi_driver -> fbd_getcmap))
			(fi, data, 0, fi->fi_type.fb_cmsize));

	case FBIOPUTCMAP:
		return ((*(fi->fi_driver -> fbd_putcmap))
			(fi, data, 0, fi->fi_type.fb_cmsize));
		break;

	case FBIOGVIDEO:
		*(int *)data = fi->fi_blanked;
		break;

	case FBIOSVIDEO:
		if (*(int *)data)
			return (*(fi->fi_driver->fbd_blank)) (fi);
		else
			return (*(fi->fi_driver->fbd_unblank)) (fi);

	default:
		printf("fb%d: Unknown ioctl command %lx\n", minor(dev), cmd);
		return (EINVAL);
	}
	return (0);
}

/*
 * Select on Digital-OS-compatible in-kernel input-event ringbuffer.
 */
int
fbselect(dev, flag, p)
	dev_t dev;
	int flag;
	struct proc *p;
{
	struct fbinfo *fi = fbcd.cd_devs[minor(dev)];

	switch (flag) {
	case FREAD:
		if (fi->fi_fbu->scrInfo.qe.eHead !=
		    fi->fi_fbu->scrInfo.qe.eTail)
			return (1);
		selrecord(p, &fi->fi_selp);
		break;
	}

	return (0);
}

/*
 * Return the physical page number that corresponds to byte offset 'off'.
 */
/*ARGSUSED*/
int
fbmmap(dev, off, prot)
	dev_t dev;
	int off, prot;
{
	int len;
	register struct fbinfo *fi;

	if (minor(dev) >= fbcd.cd_ndevs ||
	    (fi = fbcd.cd_devs[minor(dev)]) == NULL)
	    return(-1);

	len = mips_round_page(((vm_offset_t)fi->fi_fbu & PGOFSET)
			      + sizeof(*fi->fi_fbu));
	if (off < len)
		return (int)mips_btop(MACH_CACHED_TO_PHYS(fi->fi_fbu) + off);
	off -= len;
	if (off >= fi->fi_type.fb_size)
		return (-1);
	return (int)mips_btop(MACH_UNCACHED_TO_PHYS(fi->fi_pixels) + off);
}
