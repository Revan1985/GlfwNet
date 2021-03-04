#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class CursorType : int32_t
	{
		Arrow = GLFW_ARROW_CURSOR,
		Beam = GLFW_IBEAM_CURSOR,
		Crosshair = GLFW_CROSSHAIR_CURSOR,
		Hand = GLFW_HAND_CURSOR,
		HorizontalResize = GLFW_HRESIZE_CURSOR,
		VerticalResize = GLFW_VRESIZE_CURSOR,
	};
}
