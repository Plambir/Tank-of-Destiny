/* Tank of Destiny
 * Copyright (C) 2011-2018  Alexander A. Prusov
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

#include "log.hpp"
#include "window.hpp"
#include <stdlib.h>
#include <GLFW/glfw3.h>

int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  log("Init!");

  game::Window window;
  window.open(640, 480, "My Title");
  while(window.is_open())
  {
    if(window.is_key_press(game::ActionKey::ESC))
      window.close();
    window.swap_buffer();
    window.poll_events();
  }

  log("Terminate!");

  return EXIT_SUCCESS;
}
