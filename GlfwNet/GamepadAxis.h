#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class GamepadAxis :uint8_t
	{
		LeftX = GLFW_GAMEPAD_AXIS_LEFT_X,
		LeftY = GLFW_GAMEPAD_AXIS_LEFT_Y,
		RightX = GLFW_GAMEPAD_AXIS_RIGHT_X,
		RightY = GLFW_GAMEPAD_AXIS_RIGHT_Y,
		LeftTrigger = GLFW_GAMEPAD_AXIS_LEFT_TRIGGER,
		RightTrigger = GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER,
		//Last = GLFW_GAMEPAD_AXIS_LAST,

	};
}