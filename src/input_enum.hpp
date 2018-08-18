#ifndef INPUT_ENUM_HPP__
#define INPUT_ENUM_HPP__

#include <GLFW/glfw3.h>

namespace game
{

enum class ActionKey
{
  UP = GLFW_KEY_UP,
  DOWN = GLFW_KEY_DOWN,
  LEFT = GLFW_KEY_LEFT,
  RIGHT = GLFW_KEY_RIGHT,
  ACTION_1 = GLFW_KEY_Z,
  ACTION_2 = GLFW_KEY_X,
  ESC = GLFW_KEY_ESCAPE,
  ENTER = GLFW_KEY_ENTER
};

} // end namespace game

#endif /* INPUT_ENUM_HPP__ */
