#include "window.hpp"
#include <cassert>
#include <functional>
#include <sstream>

namespace game
{

Window::Window()
{
  _window = nullptr;
  _init = false;
}

Window::~Window()
{
  if(_window != nullptr)
    glfwDestroyWindow(_window);

  if(_init)
    glfwTerminate();
}

bool Window::set_error_callback = false;

void Window::open(const int width, const int height, const std::string title)
{
  assert(!_init);
  assert(_window == nullptr);

  _init = glfwInit();
  if(!_init)
    throw new std::runtime_error("Initialization glfw is failed.");

  if(!Window::set_error_callback)
  {
    glfwSetErrorCallback(&Window::error_callback);
    Window::set_error_callback = true;
  }

  _width = width;
  _height = height;
  _title = title;

  _window = glfwCreateWindow(_width, _height, _title.c_str(), NULL /* monitor */, NULL /* share */); //Use NULL because C library don't undestand nullptr
  if(!_window)
    throw new std::runtime_error("Creation glfw window is failed.");

  glfwMakeContextCurrent(_window);
}

bool Window::is_key_press(ActionKey key)
{
  assert(_window != nullptr);
  int state = glfwGetKey(_window, (int)key);
  return state == GLFW_PRESS;
}

bool Window::is_open()
{
  assert(_window != nullptr);
  return !glfwWindowShouldClose(_window);
}

void Window::close()
{
  assert(_window != nullptr);
  glfwSetWindowShouldClose(_window, GLFW_TRUE);
}

void Window::poll_events()
{
  glfwPollEvents();
}

void Window::swap_buffer()
{
  assert(_window != nullptr);
  glfwSwapBuffers(_window);
}

void Window::error_callback(int error, const char *description)
{
  std::ostringstream string_stream;
  string_stream << "Error from glfw: code is " << error << " : " << description;
  throw new std::runtime_error(string_stream.str());
}

} // end namespace game
