#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class PlatformHint :int32_t
	{
		Any = GLFW_ANY_PLATFORM,
		Win32 = GLFW_PLATFORM_WIN32,
		Cocoa = GLFW_PLATFORM_COCOA,
		Wayland = GLFW_PLATFORM_WAYLAND,
		X11 = GLFW_PLATFORM_X11,
		Null = GLFW_PLATFORM_NULL,
	};
}