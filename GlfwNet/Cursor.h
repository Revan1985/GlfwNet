#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public ref class Cursor
	{
	internal:
		Cursor(GLFWcursor* cursor)
		{
			handle = cursor;
		}
	internal:
		GLFWcursor* handle;
	};
}