/*	$OpenBSD: privsep.h,v 1.40 2017/06/28 16:31:52 krw Exp $ */

/*
 * Copyright (c) 2004 Henning Brauer <henning@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE, ABUSE OR PERFORMANCE OF THIS SOFTWARE.
 */

enum imsg_code {
	IMSG_NONE,
	IMSG_HUP,
	IMSG_DELETE_ADDRESS,
	IMSG_ADD_ADDRESS,
	IMSG_FLUSH_ROUTES,
	IMSG_ADD_ROUTE,
	IMSG_SET_INTERFACE_MTU,
	IMSG_WRITE_RESOLV_CONF
};

struct imsg_delete_address {
	struct	in_addr addr;
};

struct imsg_add_address {
	struct	in_addr	addr;
	struct	in_addr mask;
};

struct imsg_add_route {
	struct in_addr	dest;
	struct in_addr	netmask;
	struct in_addr	gateway;
	struct in_addr	ifa;
	int		addrs;
	int		flags;
};

struct imsg_set_interface_mtu {
	int	mtu;
};

int	dispatch_imsg(struct interface_info *, struct imsgbuf *);

void	add_direct_route(struct in_addr, struct in_addr, struct in_addr);
void	add_default_route(struct in_addr, struct in_addr);
void	add_static_routes(struct option_data *, struct in_addr);
void	add_classless_static_routes(struct option_data *, struct in_addr);
void	priv_add_route(int, struct imsg_add_route *);
void	priv_flush_routes(char *, int);

char	*resolv_conf_contents(char *, struct option_data *,
    struct option_data *, struct option_data *);
void	write_resolv_conf(u_int8_t *, size_t);
void	priv_write_resolv_conf(int, u_int8_t *, size_t);

void	priv_delete_address(char *, struct imsg_delete_address *);
void	priv_add_address(char *, struct imsg_add_address *);

void	priv_set_interface_mtu(char *, struct imsg_set_interface_mtu *);
