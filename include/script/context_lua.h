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

#ifndef CONTEXT_LUA_H__
#define CONTEXT_LUA_H__

#include "core/context.h"

struct context_lua
{
  struct context *ctx;
};

void
context_lua_push(struct context *ctx);

void
context_lua_register(struct context *ctx);

struct context_lua*
context_lua_check(lua_State *lua, int index);

int
context_lua_get_width(lua_State *lua);

int
context_lua_get_height(lua_State *lua);

int
context_lua_get_bpp(lua_State *lua);

int
context_lua_set_width(lua_State *lua);

int
context_lua_set_height(lua_State *lua);

int
context_lua_set_bpp(lua_State *lua);

#endif /* CONTEXT_LUA_H__ */
