#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class WindowAttribute : uint32_t
	{

		Focused = GLFW_FOCUSED,
		Iconified = GLFW_ICONIFIED,
		Resizable = GLFW_RESIZABLE,
		Visible = GLFW_VISIBLE,
		Decorated = GLFW_DECORATED,
		AutoIconify = GLFW_AUTO_ICONIFY,
		Floating = GLFW_FLOATING,
		Maximized = GLFW_MAXIMIZED,
		TransparentFramebuffer = GLFW_TRANSPARENT_FRAMEBUFFER,
		Hovered = GLFW_HOVERED,
		FocusOnShow = GLFW_FOCUS_ON_SHOW,
		MousePassthrough = GLFW_MOUSE_PASSTHROUGH,
		PositionX = GLFW_POSITION_X,
		PositionY = GLFW_POSITION_Y,
	};
}