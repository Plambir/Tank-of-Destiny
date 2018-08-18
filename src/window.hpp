#ifndef WINDOW_HPP__
#define WINDOW_HPP__

#include <string>
#include <GLFW/glfw3.h>
#include <map>
#include "input_enum.hpp"

namespace game
{

class Window
{
public:
  Window();
  ~Window();

  void open(const int width, const int height, const std::string title);
  void poll_events();
  void swap_buffer();
  bool is_open();
  bool is_key_press(ActionKey key);
  void close();

protected:
  static void error_callback(int error, const char *description);
  static bool set_error_callback;

  GLFWwindow *_window;
  int _width;
  int _height;
  std::string _title;
  bool _init;
};

} // end namespace game

#endif /* WINDOW_HPP__ */
