/* c just test it
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

/* Example:
 * #include "c_just_test_it.h"
 *
 * int i;
 *
 * void
 * set_up()
 * {
 *   i = 1;
 * }
 *
 * void
 * run()
 * {
 *   i++;
 *
 *   begin_assertions();
 *
 *   assert(i == 2);
 *
 *   end_assertions();
 * }
 *
 * void
 * other_run()
 * {
 *   begin_assertions();
 *
 *   assert(0 == 0);
 *
 *   end_assertions();
 * }
 *
 * void
 * tear_down()
 * {
 *   i = 0;
 * }
 *
 * int main(int argc, char** argv)
 * {
 *   run_test("Fail test",       NULL,   run,       tear_down);
 *   run_test("Pass test",       set_up, run,       tear_down);
 *   run_test("Other pass test", NULL,   other_run, NULL);
 *   return 0;
 * }
 */

#ifndef C_JUST_TEST_IT_H__
#define C_JUST_TEST_IT_H__

#include <stdio.h>

typedef void(*function)();

#define assert(expr) do { \
  if (!(expr)) \
    { \
      fprintf(stdout, "%20s",  "FAIL"); \
      fprintf(stdout, "\n%s:%d: %s\n", __FILE__, __LINE__, #expr); \
      ret = 1; \
    } \
  } while(0)

#define begin_assertions() int ret = 0

#define end_assertions() if (!ret) fprintf(stdout, "%20s", "PASS"); \
  fprintf(stdout, "\n")

void
run_test(char *name, function set_up, function run, function tear_down)
{
  fprintf(stdout, ":: %-30s", name);
  if(set_up)
    set_up();
  run();
  if(tear_down)
    tear_down();
}

#endif /* C_JUST_TEST_IT_H__ */
