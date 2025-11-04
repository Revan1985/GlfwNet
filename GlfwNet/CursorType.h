#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class CursorType : int32_t
	{
		Arrow = GLFW_ARROW_CURSOR,
		Beam = GLFW_IBEAM_CURSOR,
		Crosshair = GLFW_CROSSHAIR_CURSOR,
		PoitingHand = GLFW_POINTING_HAND_CURSOR,
		ResizeEW = GLFW_RESIZE_EW_CURSOR,
		ResizeNS = GLFW_RESIZE_NS_CURSOR,
		ResizeNWSE = GLFW_RESIZE_NWSE_CURSOR,
		ResizeNESW = GLFW_RESIZE_NESW_CURSOR,
		ResizeAll = GLFW_RESIZE_ALL_CURSOR,
		NotAllowed = GLFW_NOT_ALLOWED_CURSOR,
		HorizontalResize = GLFW_HRESIZE_CURSOR,
		VerticalResize = GLFW_VRESIZE_CURSOR,
		Hand = GLFW_HAND_CURSOR,
	};
}
