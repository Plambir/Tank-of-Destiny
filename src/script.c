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
script(struct context *ctx, char* file_name)
{
  if (luaL_dofile(ctx->lua, file_name))
    {
      fprintf(stderr,
              "%s:%d: %s\n",
              __FILE__, __LINE__, lua_tostring(ctx->lua, 1));
      ctx->error = ERROR_LUA;
    }
}
