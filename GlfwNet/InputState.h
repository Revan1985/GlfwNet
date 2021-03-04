#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class InputState : int8_t
	{
		Release = GLFW_RELEASE,
		Press = GLFW_PRESS,
		Repeat = GLFW_REPEAT,
	};
}
