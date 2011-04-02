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

#ifndef SYSTEM_H__
#define SYSTEM_H__

#include <SDL/SDL.h>

#include <string.h>
#include <errno.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include "context.h"

struct context*
init_all();

struct context*
create_context();

struct context*
init_sdl(struct context* ctx);

struct context*
init_lua(struct context* ctx);

void
main_loop(struct context *game);

int
open_window(struct context *ctx);

int
quit(struct context *ctx);

#endif /* SYSTEM_H__ */
