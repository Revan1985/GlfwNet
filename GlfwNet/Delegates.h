#pragma once

#include <GLFW/glfw3.h>

#include "Monitor.h"
#include "Window.h"

#include "ConnectionStatus.h"
#include "ErrorCode.h"
#include "InputState.h"
#include "Key.h"
#include "KeyModifiers.h"
#include "MouseButton.h"

using namespace System;

namespace GlfwNet
{
	public delegate void GlCallback();
	public delegate void ErrorCallback(ErrorCode error_code, String^ description);
	public delegate void WindowPositionCallback(Window^ window, int x, int y);
	public delegate void WindowSizeCallback(Window^ window, int width, int height);
	public delegate void WindowCloseCallback(Window^ window);
	public delegate void WindowRefreshCallback(Window^ window);
	public delegate void WindowFocusCallback(Window^ window, bool focused);
	public delegate void WindowIconifyCallback(Window^ window, bool iconified);
	public delegate void WindowMaximizeCallback(Window^ window, bool maximized);
	public delegate void FramebufferSizeCallback(Window^ window, int width, int height);
	public delegate void WindowContentScaleCallback(Window^ window, float x, float y);
	public delegate void MouseButtonCallback(Window^ window, MouseButton button, InputState state, KeyModifiers mods);
	public delegate void CursorPositionCallback(Window^ window, double x, double y);
	public delegate void CursorEnterCallback(Window^ window, bool entered);
	public delegate void ScrollCallback(Window^ window, double x, double y);
	public delegate void KeyCallback(Window^ window, Key key, int scancode, InputState state, KeyModifiers mods);
	public delegate void CharCallback(Window^ window, unsigned int codepoint);
	public delegate void CharmodsCallback(Window^ window, unsigned int codepoint, KeyModifiers mods);
	public delegate void DropCallback(Window^ window, cli::array<String^>^ paths);
	public delegate void MonitorCallback(Monitor^ monitor, ConnectionStatus status);
	public delegate void JoystickCallback(Joystick jid, ConnectionStatus status);
}