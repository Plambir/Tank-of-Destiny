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

#include "core.h"
#include "script.h"

struct context*
init_all()
{
  struct context *ctx;

  ctx = create_context();

  ctx = init_sdl(ctx);

  if (ctx->error == ERROR_UNABLE_INIT_VIDEO)
    {
      free(ctx);
      exit(ERROR_UNABLE_INIT_VIDEO);
    }

  ctx = init_lua(ctx);

  return ctx;
}
