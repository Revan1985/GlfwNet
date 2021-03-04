#pragma once

#include <GLFW/glfw3.h>

#include "VideoMode.h"
using namespace System;
using namespace System::Drawing;

namespace GlfwNet
{
	public ref struct Monitor
	{
		static property cli::array<Monitor^>^ Monitors { cli::array<Monitor^>^ get(); }
		static property Monitor^ PrimaryMonitor { Monitor^ get(); }

		property Point Position { Point get(); }
		property Rectangle WorkArea { Rectangle get(); }
		property Size PhysicalSize { Size get(); }
		property SizeF ContentScale {SizeF get(); }

		property String^ Name { String^ get(); }
		property IntPtr UserPointer
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property cli::array<VideoMode>^ VideoModes { cli::array<VideoMode>^ get(); }
		property VideoMode CurrentMode {VideoMode get(); }

	internal:
		Monitor(GLFWmonitor* monitor)
		{
			if (monitor == nullptr) { throw gcnew ArgumentNullException("monitor"); }
			handle = monitor;
		}
	internal:
		GLFWmonitor* handle;
	};
}