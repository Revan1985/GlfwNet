#pragma once

#include <GLFW/glfw3.h>

using namespace System;

namespace GlfwNet
{
	public value struct Image
	{
		initonly int Width;
		initonly int Height;
		initonly IntPtr Pixels;

	internal:
		Image(GLFWimage image)
		{
			Width = image.width;
			Height = image.height;
			Pixels = IntPtr(image.pixels);
		}
		GLFWimage ToNative()
		{
			GLFWimage image{};
			image.width = Width;
			image.height = Height;
			image.pixels = reinterpret_cast<unsigned char*>(Pixels.ToPointer());
			return image;
		}
	};
}