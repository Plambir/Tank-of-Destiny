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
#include "open_window.h"
#include "quit.h"
#include "errors.h"
#include "main_loop.h"

struct context *game;

void
set_up();

void
run_begin_and_end();

void
tear_down();

int
main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  run_test("[main loop] WORK, DONE, END",
           set_up, run_begin_and_end, tear_down);

  return 0;
}

void
set_up()
{
  game = init();
  open_window(game);
}

void
run_begin_and_end()
{
  begin_assertions();

  assert(game->status == WORK);

  game->status = DONE;

  main_loop(game);

  assert(game->status == END);
  assert(game->error == NO_ERROR);

  end_assertions();
}

void
tear_down()
{
  quit(game);
}
