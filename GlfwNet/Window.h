#pragma once

#include <GLFW/glfw3.h>

#include "Monitor.h"

using namespace System;
using namespace System::Drawing;

namespace GlfwNet
{
	public ref struct Window
	{
		property bool ShouldClose
		{
			bool get();
			void set(bool value);
		}
		property Point Position
		{
			Point get();
			void set(Point value);
		}
		property Drawing::Size Size
		{
			Drawing::Size get();
			void set(Drawing::Size value);
		}
		property Drawing::Size FramebufferSize
		{
			Drawing::Size get();
		}
		property float Opacity 
		{
			float get();
			void set(float value);
		}
		property Monitor^ WindowMonitor 
		{
			Monitor^ get();
		}
		property SizeF ContentScale 
		{
			SizeF get();
		}
		property Rectangle FrameSize
		{
			Rectangle get();
		}

	public:
		~Window()
		{
			this->!Window();
		}
		!Window()
		{
			glfwDestroyWindow(handle);
		}

	public:
		void Iconify();
		void Restore();
		void Maximize();
		void Show();
		void Hide();
		void Focus();
		void RequestAttention();

		void SetWindowMonitor(Monitor^ monitor, int xpos, int ypos, int width, int height, int refreshRate);

		int GetWindowAttribute(WindowAttribute attribute);
		void SetWindowAttribute(WindowAttribute attribute, int value);

	internal:
		Window(GLFWwindow* window)
		{
			if (window == nullptr) { throw gcnew ArgumentNullException("window"); }
			handle = window;
		}
	internal:
		GLFWwindow* handle;
	};
}