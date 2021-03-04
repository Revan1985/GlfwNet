#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public value struct VideoMode
	{
		initonly int Width;
		initonly int Height;
		initonly int RedBits;
		initonly int GreenBits;
		initonly int BlueBits;
		initonly int RefreshRate;

		VideoMode(int width, int height, int red, int green, int blue, int refresh)
		{
			Width = width;
			Height = height;
			RedBits = red;
			GreenBits = green;
			BlueBits = blue;
			RefreshRate = refresh;
		}

	internal:
		VideoMode(GLFWvidmode mode)
		{
			Width = mode.width;
			Height = mode.height;
			RedBits = mode.redBits;
			GreenBits = mode.greenBits;
			BlueBits = mode.blueBits;
			RefreshRate = mode.refreshRate;
		}
		GLFWvidmode ToNative()
		{
			GLFWvidmode mode{};
			mode.width = Width;
			mode.height = Height;
			mode.redBits = RedBits;
			mode.greenBits = GreenBits;
			mode.blueBits = BlueBits;
			mode.refreshRate = RefreshRate;
			return mode;
		}
	};
}