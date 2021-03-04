#include "pch.h"
#include "Window.h"

namespace GlfwNet
{
	bool Window::ShouldClose::get()
	{
		return glfwWindowShouldClose(handle) == GLFW_TRUE;
	}
	void Window::ShouldClose::set(bool value)
	{
		glfwSetWindowShouldClose(handle, value ? GLFW_TRUE : GLFW_FALSE);
	}
	Point Window::Position::get()
	{
		int x;
		int y;
		glfwGetWindowPos(handle, &x, &y);
		return Point(x, y);
	}
	void Window::Position::set(Point value)
	{
		glfwSetWindowPos(handle, value.X, value.Y);
	}

	Drawing::Size Window::Size::get()
	{
		int width;
		int height;
		glfwGetWindowSize(handle, &width, &height);
		return Drawing::Size(width, height);
	}

	void Window::Size::set(Drawing::Size value)
	{
		glfwSetWindowSize(handle, value.Width, value.Height);
	}
	Drawing::Size Window::FramebufferSize::get()
	{
		int width;
		int height;
		glfwGetFramebufferSize(handle, &width, &height);
		return Drawing::Size(width, height);
	}
	float Window::Opacity::get()
	{
		return glfwGetWindowOpacity(handle);
	}
	void Window::Opacity::set(float value)
	{
		glfwSetWindowOpacity(handle, value);
	}
	Monitor^ Window::WindowMonitor::get()
	{
		GLFWmonitor* monitor = glfwGetWindowMonitor(handle);
		return gcnew Monitor(monitor);
	}

	SizeF Window::ContentScale::get()
	{
		float x;
		float y;
		glfwGetWindowContentScale(handle, &x, &y);
		return SizeF(x, y);
	}
	Rectangle Window::FrameSize::get()
	{
		int top;
		int left;
		int right;
		int bottom;
		glfwGetWindowFrameSize(handle, &left, &top, &right, &bottom);
		return Rectangle(left, top, right, bottom);
	}

	void Window::Iconify() { glfwIconifyWindow(handle); }
	void Window::Restore() { glfwRestoreWindow(handle); }
	void Window::Maximize() { glfwMaximizeWindow(handle); }
	void Window::Show() { glfwShowWindow(handle); }
	void Window::Hide() { glfwHideWindow(handle); }
	void Window::Focus() { glfwFocusWindow(handle); }
	void Window::RequestAttention() { glfwRequestWindowAttention(handle); }
	void Window::SetWindowMonitor(Monitor^ monitor, int xpos, int ypos, int width, int height, int refreshRate)
	{
		glfwSetWindowMonitor(handle, GLFWNET_SAFEREF(monitor, handle), xpos, ypos, width, height, refreshRate);
	}

	int Window::GetWindowAttribute(WindowAttribute attribute)
	{	
		return glfwGetWindowAttrib(handle, static_cast<int>(attribute));
	}
	void Window::SetWindowAttribute(WindowAttribute attribute, int value)
	{
		glfwSetWindowAttrib(handle, static_cast<int>(attribute), value);
	}

}