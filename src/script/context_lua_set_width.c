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

int
context_lua_set_width(lua_State *lua)
{
  int width;
  struct context_lua *ctx_lua;
  script_check_arg_number(lua, 2);
  width = luaL_checkint(lua, 2);
  ctx_lua = context_lua_check(lua, 1);
  ctx_lua->ctx->width = width;
  return 0;
}
