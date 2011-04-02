/* Tank of Destiny
 * Copyright (C) 2011  Alexander A. Prusov
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "script.h"

void
script_check_arg_number(lua_State *lua, int n)
{
  int top = lua_gettop(lua);
  if (top != n)
    {
      lua_Debug dbg;
      lua_getinfo(lua, "Sl", &dbg);
      lua_pushfstring(lua, "%s:%d: error: got %d, expected %d",
                      dbg.short_src, dbg.currentline, top, n);
      lua_error(lua);
    }
}
