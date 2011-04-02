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

#ifndef SCRIPT_FUNCTION_H__
#define SCRIPT_FUNCTION_H__

#include "core/context.h"

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

void
script_load(struct context *ctx, char *file_name);

void
script_call_function(struct context *ctx, char* function_name);

void
script_check_arg_number(lua_State *lua, int n);

#endif /* SCRIPT_FUNCTION_H__ */
