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

#include "context.h"
#include "init.h"
#include "open_window.h"
#include "quit.h"
#include "errors.h"

int
main(int argc, char *argv[])
{
  struct context *game;

  (void)argc;
  (void)argv;

  game = init();
  if (game->error)
    {
      quit(game);
      return EXIT_FAILURE;
    }

  open_window(game);
  if (game->error)
    {
      quit(game);
      return EXIT_FAILURE;
    }

  quit(game);

  return EXIT_SUCCESS;
}
