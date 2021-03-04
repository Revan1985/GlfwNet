#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class ContextApi : int32_t
	{
		Native = GLFW_NATIVE_CONTEXT_API,
		Egl = GLFW_EGL_CONTEXT_API,
		Mesa = GLFW_OSMESA_CONTEXT_API,
	};
}