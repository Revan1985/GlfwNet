#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class ReleaseBehaviour : int32_t
	{
		Any = GLFW_ANY_RELEASE_BEHAVIOR,
		Flush = GLFW_RELEASE_BEHAVIOR_FLUSH,
		None = GLFW_RELEASE_BEHAVIOR_NONE,
	};
}
