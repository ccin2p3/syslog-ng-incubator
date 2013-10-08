/*
 * Copyright (c) 2013 BalaBit IT Ltd, Budapest, Hungary
 * Copyright (c) 2013 Gyula Petrovics <pgyula@balabit.hu>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 */

#include "mysql-mod.h"
#include "mysql-mod-parser.h"

#include "plugin.h"
#include "plugin-types.h"

extern CfgParser mysql_dd_parser;

static Plugin mysql_plugins[] =
{
  {
    .type = LL_CONTEXT_DESTINATION,
    .name = "mysql",
    .parser = &mysql_dd_parser,
  },
};

gboolean
mysql_module_init(GlobalConfig *cfg, CfgArgs *args)
{
  plugin_register(cfg, mysql_plugins, G_N_ELEMENTS(mysql_plugins));
  return TRUE;
}

const ModuleInfo module_info =
{
  .canonical_name = "mysql",
  .version = VERSION,
  .description = "The mysql module provides MySQL destination support for syslog-ng",
  .core_revision = VERSION_CURRENT_VER_ONLY,
  .plugins = mysql_plugins,
  .plugins_len = G_N_ELEMENTS(mysql_plugins),
};