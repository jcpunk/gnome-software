/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2015-2017 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __APPSTREAM_COMMON_H
#define __APPSTREAM_COMMON_H

#include <gnome-software.h>
#include <xmlb.h>

G_BEGIN_DECLS

GsApp		*gs_appstream_create_app		(GsPlugin	*plugin,
							 XbSilo		*silo,
							 XbNode		*component,
							 GError		**error);
gboolean	 gs_appstream_refine_app		(GsPlugin	*plugin,
							 GsApp		*app,
							 XbSilo		*silo,
							 XbNode		*component,
							 GsPluginRefineFlags flags,
							 GError		**error);
gboolean	 gs_appstream_search			(GsPlugin	*plugin,
							 XbSilo		*silo,
							 gchar		**values,
							 GsAppList	*list,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 gs_appstream_add_categories		(GsPlugin	*plugin,
							 XbSilo		*silo,
							 GPtrArray	*list,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 gs_appstream_add_category_apps		(GsPlugin	*plugin,
							 XbSilo		*silo,
							 GsCategory	*category,
							 GsAppList	*list,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 gs_appstream_add_popular		(GsPlugin	*plugin,
							 XbSilo		*silo,
							 GsAppList	*list,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 gs_appstream_add_featured		(GsPlugin	*plugin,
							 XbSilo		*silo,
							 GsAppList	*list,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 gs_appstream_add_alternates		(GsPlugin	*plugin,
							 XbSilo		*silo,
							 GsApp		*app,
							 GsAppList	*list,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 gs_appstream_add_recent		(GsPlugin	*plugin,
							 XbSilo		*silo,
							 GsAppList	*list,
							 guint64	 age,
							 GCancellable	*cancellable,
							 GError		**error);
void		 gs_appstream_component_add_extra_info	(GsPlugin	*plugin,
							 XbBuilderNode	*component);
void		 gs_appstream_component_add_keyword	(XbBuilderNode	*component,
							 const gchar	*str);
void		 gs_appstream_component_add_category	(XbBuilderNode	*component,
							 const gchar	*str);
void		 gs_appstream_component_add_icon	(XbBuilderNode	*component,
							 const gchar	*str);
void		 gs_appstream_component_add_provide	(XbBuilderNode	*component,
							 const gchar	*str);

G_END_DECLS

#endif /* __APPSTREAM_COMMON_H */
