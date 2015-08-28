/* $OpenBSD: names.c,v 1.27 2015/08/28 15:51:48 nicm Exp $ */

/*
 * Copyright (c) 2009 Nicholas Marriott <nicm@users.sourceforge.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>

#include <ctype.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>

#include "tmux.h"

void
check_window_name(struct window *w)
{
	char	*name;

	if (w->active == NULL)
		return;

	if (!options_get_number(&w->options, "automatic-rename"))
		return;

	if (~w->active->flags & PANE_CHANGED)
		return;
	w->active->flags &= ~PANE_CHANGED;

	name = format_window_name(w);
	if (strcmp(name, w->name) != 0) {
		log_debug("@%u new name %s (was %s)", w->id, name, w->name);
		window_set_name(w, name);
		server_status_window(w);
	} else
		log_debug("@%u name not changed (still %s)", w->id, w->name);

	free(name);
}

char *
default_window_name(struct window *w)
{
	char    *cmd, *s;

	cmd = cmd_stringify_argv(w->active->argc, w->active->argv);
	if (cmd != NULL && *cmd != '\0')
		s = parse_window_name(cmd);
	else
		s = parse_window_name(w->active->shell);
	free(cmd);
	return (s);
}

char *
format_window_name(struct window *w)
{
	struct format_tree	*ft;
	char			*fmt, *name;

	ft = format_create();
	format_defaults_window(ft, w);
	format_defaults_pane(ft, w->active);

	fmt = options_get_string(&w->options, "automatic-rename-format");
	name = format_expand(ft, fmt);

	format_free(ft);
	return (name);
}

char *
parse_window_name(const char *in)
{
	char	*copy, *name, *ptr;

	name = copy = xstrdup(in);
	if (strncmp(name, "exec ", (sizeof "exec ") - 1) == 0)
		name = name + (sizeof "exec ") - 1;

	while (*name == ' ' || *name == '-')
		name++;
	if ((ptr = strchr(name, ' ')) != NULL)
		*ptr = '\0';

	if (*name != '\0') {
		ptr = name + strlen(name) - 1;
		while (ptr > name && !isalnum((u_char)*ptr))
			*ptr-- = '\0';
	}

	if (*name == '/')
		name = basename(name);
	name = xstrdup(name);
	free(copy);
	return (name);
}
