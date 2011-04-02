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
context_lua_push(struct context *ctx)
{
  struct context_lua *ctx_lua = (struct context_lua*)lua_newuserdata(ctx->lua, sizeof(struct context_lua));
  luaL_getmetatable(ctx->lua, "context");
  lua_setmetatable(ctx->lua, -2);
  ctx_lua->ctx = ctx;
}