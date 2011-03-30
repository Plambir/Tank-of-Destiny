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

#include "init.h"

struct context*
init()
{
  struct context *ctx;

  ctx = malloc(sizeof(struct context));
  if (!ctx)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      exit(errno);
    }

  ctx->width = 640;
  ctx->height = 480;
  ctx->bpp = 32;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
      ctx->error = ERROR_UNABLE_INIT_VIDEO;
    }
  else
    {
      ctx->error = NO_ERROR;
    }

  ctx->lua = luaL_newstate();
  if (!ctx->lua)
    {
      fprintf(stderr,
              "%s:%d: %s\n",
              __FILE__, __LINE__, strerror(errno));
      exit(errno);
    }

  context_lua_register(ctx);

  return ctx;
}
