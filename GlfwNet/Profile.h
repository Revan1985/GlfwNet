#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class Profile : int32_t
	{
		Any = GLFW_OPENGL_ANY_PROFILE,
		Core = GLFW_OPENGL_CORE_PROFILE,
		Compatibility = GLFW_OPENGL_COMPAT_PROFILE,
	};
}