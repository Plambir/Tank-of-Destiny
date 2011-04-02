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
context_lua_register(struct context *ctx)
{
  const luaL_Reg context_methods[] =
    {
      {"get_width",  context_lua_get_width },
      {"get_height", context_lua_get_height},
      {"get_bpp",    context_lua_get_bpp   },
      {"set_width",  context_lua_set_width },
      {"set_height", context_lua_set_height},
      {"set_bpp",    context_lua_set_bpp   },
      {NULL, NULL}
    };

  const luaL_Reg context_meta[] =
    {
      {NULL, NULL}
    };

  luaL_register(ctx->lua, "context", context_methods);
  if (luaL_newmetatable(ctx->lua, "context"))
    {
      luaL_register(ctx->lua, 0, context_meta);
      lua_pushliteral(ctx->lua, "__index");
      lua_pushvalue(ctx->lua, -3);
      lua_rawset(ctx->lua, -3);
      lua_pushliteral(ctx->lua, "__metatable");
      lua_pushvalue(ctx->lua, -3);
      lua_rawset(ctx->lua, -3);
    }
  lua_pop(ctx->lua, 2);
}
