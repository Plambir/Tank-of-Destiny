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

#include "c_just_test_it.h"

#include "context.h"
#include "init.h"
#include "quit.h"
#include "errors.h"

struct context *game;

void
set_up();

void
run();

void
tear_down();

int
main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  run_test("Init video", set_up, run, tear_down);

  return 0;
}

void
set_up()
{
  game = init();
}

void
run()
{
  begin_assertions();

  assert(game->error == NO_ERROR);

  end_assertions();
}

void
tear_down()
{
  quit(game);
}
