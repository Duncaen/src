#	$OpenBSD: Makefile,v 1.2 2017/06/16 10:25:54 espie Exp $

PROG=	rpc.statd
SRCS=	procs.c sm_inter_svc.c statd.c
MAN=	rpc.statd.8

DPADD=	${LIBRPCSVC}
LDADD=	-lrpcsvc

CFLAGS+= -I.

CLEANFILES=	sm_inter_svc.c sm_inter.h

RPCSRC=	${DESTDIR}/usr/include/rpcsvc/sm_inter.x
RPCGEN=	rpcgen -L -C

sm_inter_svc.c: ${RPCSRC} sm_inter.h
	${RPCGEN} -m -o ${.TARGET} ${RPCSRC}

sm_inter.h: ${RPCSRC}
	${RPCGEN} -h -o ${.TARGET} ${RPCSRC}

BUILDFIRST =	sm_inter.h

test: ${.CURDIR}/test.c
	cc -o test ${.CURDIR}/test.c -lrpcsvc

.include <bsd.prog.mk>
