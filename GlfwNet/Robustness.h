#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class Robustness : int32_t
	{
		None = GLFW_NO_ROBUSTNESS,
		NoResetNotification = GLFW_NO_RESET_NOTIFICATION,
		LoseContextOnReset = GLFW_LOSE_CONTEXT_ON_RESET,
	};
}