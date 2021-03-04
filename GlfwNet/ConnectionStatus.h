#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class ConnectionStatus : int32_t
	{
		Unknown,
		Connected=GLFW_CONNECTED,
		Disconnected=GLFW_DISCONNECTED,
	};
}
