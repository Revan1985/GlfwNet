#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class ClientApi : int32_t
	{
		None = GLFW_NO_API,
		OpenGl = GLFW_OPENGL_API,
		OpenGlES =GLFW_OPENGL_ES_API,
	};
}