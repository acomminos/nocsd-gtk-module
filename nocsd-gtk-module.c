// A GTK3 module to disable styling of client-side decorations
// Copyright (C) 2015 Andrew Comminos
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <gtk/gtk.h>

static const gchar* NOCSD_STYLE = ".window-frame { box-shadow: none; margin: 0 } .titlebar { border-radius: 0 }";

void
gtk_module_init(gint *argc, gchar ***argv[])
{
  GError* error = NULL;
  GtkCssProvider* provider = gtk_css_provider_new();
  gtk_css_provider_load_from_data(provider, NOCSD_STYLE, -1,
                                  &error);
  if (error)
    g_error(error->message);
  gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                            GTK_STYLE_PROVIDER(provider),
                                            GTK_STYLE_PROVIDER_PRIORITY_USER);
}
