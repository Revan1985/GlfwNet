#include "pch.h"
#include "Monitor.h"

namespace GlfwNet
{
	cli::array<Monitor^>^ Monitor::Monitors::get()
	{
		int count = 0;
		GLFWmonitor** monitors = glfwGetMonitors(&count);
		cli::array<Monitor^>^ _monitors = gcnew cli::array<Monitor^>(count);
		for (int i = 0; i < count; ++i)
		{
			_monitors[i] = gcnew Monitor(monitors[i]);
		}
		return _monitors;
	}
	Monitor^ Monitor::PrimaryMonitor::get()
	{
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		return gcnew Monitor(monitor);
	}


	Point Monitor::Position::get()
	{
		int x;
		int y;
		glfwGetMonitorPos(handle, &x, &y);
		return Point(x, y);
	}

	Rectangle Monitor::WorkArea::get()
	{
		int x;
		int y;
		int w;
		int h;
		glfwGetMonitorWorkarea(handle, &x, &y, &w, &h);
		return Rectangle(x, y, w, h);
	}
	Size Monitor::PhysicalSize::get()
	{
		int w;
		int h;
		glfwGetMonitorPhysicalSize(handle, &w, &h);
		return Size(w, h);
	}
	SizeF Monitor::ContentScale::get()
	{
		float x;
		float y;
		glfwGetMonitorContentScale(handle, &x, &y);
		return SizeF(x, y);
	}

	String^ Monitor::Name::get()
	{
		const char* name = glfwGetMonitorName(handle);
		return gcnew String(name);
	}

	IntPtr Monitor::UserPointer::get()
	{
		void* pointer = glfwGetMonitorUserPointer(handle);
		return IntPtr(pointer);
	}
	void Monitor::UserPointer::set(IntPtr value)
	{
		glfwSetMonitorUserPointer(handle, value.ToPointer());
	}

	cli::array<VideoMode>^ Monitor::VideoModes::get()
	{
		int count = 0;
		const GLFWvidmode* modes = glfwGetVideoModes(handle, &count);
		cli::array<VideoMode>^ videoModes = gcnew cli::array<VideoMode>(count);
		for (int i = 0; i < count; ++i)
		{
			videoModes[i] = VideoMode(modes[i]);
		}
		return videoModes;
	}
	VideoMode Monitor::CurrentMode::get()
	{
		const GLFWvidmode* mode = glfwGetVideoMode(handle);
		return VideoMode(*mode);
	}

}