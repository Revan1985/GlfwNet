#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class CursorMode :int32_t
	{
		Normal = GLFW_CURSOR_NORMAL,
		Hidden = GLFW_CURSOR_HIDDEN,
		Disabled = GLFW_CURSOR_DISABLED,
		Captured = GLFW_CURSOR_CAPTURED,
	};
}