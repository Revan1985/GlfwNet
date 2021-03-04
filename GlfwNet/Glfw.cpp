#include "pch.h"
#include "Glfw.h"

using namespace System::Runtime::InteropServices;

namespace GlfwNet
{


	Glfw::Glfw()
	{
		glfwInit();

		glfwSetErrorCallback((GLFWerrorfun)Errorfun);
		glfwSetMonitorCallback((GLFWmonitorfun)Monitorfun);
		glfwSetJoystickCallback((GLFWjoystickfun)Joystickfun);
	}

	bool Glfw::Init()
	{
		return glfwInit() == GLFW_TRUE;
	}
	void Glfw::Terminate()
	{
		glfwTerminate();
	}
	void Glfw::InitHint(Hint hint, int value)
	{
		glfwInitHint(static_cast<int>(hint), value);
	}
	void Glfw::GetVersion([OutAttribute] int% major, [OutAttribute] int% minor, [OutAttribute] int% rev)
	{
		pin_ptr<int> _major = &major;
		pin_ptr<int> _minor = &minor;
		pin_ptr<int> _rev = &rev;
		glfwGetVersion(_major, _minor, _rev);
	}
	String^ Glfw::GetVersionString()
	{
		const char* version = glfwGetVersionString();
		return gcnew String(version);
	}
	ErrorCode Glfw::GetError([OutAttribute] String^% description)
	{
		const char* _desc = nullptr;
		int code = glfwGetError(&_desc);
		description = _desc == nullptr ? nullptr : gcnew String(_desc);
		return static_cast<ErrorCode>(code);
	}
	//ErrorCallback^ Glfw::SetErrorCallback(ErrorCallback^ callback)
	//{
	//	GLFWerrorfun errorFun = callback == nullptr ? nullptr : (GLFWerrorfun)Marshal::GetFunctionPointerForDelegate(callback).ToPointer();
	//	errorFun = glfwSetErrorCallback(errorFun);
	//	return errorFun == nullptr ? nullptr : Marshal::GetDelegateForFunctionPointer<ErrorCallback^>(IntPtr(errorFun));
	//}
	cli::array<Monitor^>^ Glfw::GetMonitors([OutAttribute] int% count)
	{
		pin_ptr<int> c = &count;
		GLFWmonitor** monitors = glfwGetMonitors(c);
		cli::array<Monitor^>^ res = gcnew cli::array<Monitor^>(*c);
		for (int i = 0; i < res->Length; ++i)
		{
			res[i] = gcnew Monitor(monitors[i]);
		}
		return res;
	}
	Monitor^ Glfw::GetPrimaryMonitor()
	{
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		return gcnew Monitor(monitor);
	}
	void Glfw::GetMonitorPosition(Monitor^ monitor, [OutAttribute] int% xpos, [OutAttribute] int% ypos)
	{
		pin_ptr<int> x = &xpos;
		pin_ptr<int> y = &ypos;
		glfwGetMonitorPos(monitor->handle, x, y);
	}
	void Glfw::GetMonitorWorkarea(Monitor^ monitor, [OutAttribute] int% xpos, [OutAttribute] int% ypos, [OutAttribute] int% width, [OutAttribute] int% height)
	{
		pin_ptr<int> x = &xpos;
		pin_ptr<int> y = &ypos;
		pin_ptr<int> w = &width;
		pin_ptr<int> h = &height;
		glfwGetMonitorWorkarea(monitor->handle, x, y, w, h);
	}
	void Glfw::GetMonitorPhysicalSize(Monitor^ monitor, [OutAttribute] int% widthMM, [OutAttribute] int% heightMM)
	{
		pin_ptr<int> w = &widthMM;
		pin_ptr<int> h = &heightMM;
		glfwGetMonitorPhysicalSize(monitor->handle, w, h);
	}
	void Glfw::GetMonitorContentScale(Monitor^ monitor, [OutAttribute] float% xscale, [OutAttribute] float% yscale)
	{
		pin_ptr<float> x = &xscale;
		pin_ptr<float> y = &yscale;
		glfwGetMonitorContentScale(monitor->handle, x, y);

	}
	String^ Glfw::GetMonitorName(Monitor^ monitor)
	{
		const char* name = glfwGetMonitorName(monitor->handle);
		return gcnew String(name);
	}
	void Glfw::SetMonitorUserPointer(Monitor^ monitor, IntPtr pointer)
	{
		glfwSetMonitorUserPointer(monitor->handle, pointer.ToPointer());
	}
	IntPtr Glfw::GetMonitorUserPointer(Monitor^ monitor)
	{
		void* data = glfwGetMonitorUserPointer(monitor->handle);
		return IntPtr(data);
	}
	MonitorCallback^ Glfw::SetMonitorCallback(MonitorCallback^ callback)
	{
		// todo
		return nullptr;
	}
	cli::array<VideoMode>^ Glfw::GetVideoModes(Monitor^ monitor, [OutAttribute] int% count)
	{
		pin_ptr<int> c = &count;
		const GLFWvidmode* modes = glfwGetVideoModes(monitor->handle, c);
		cli::array<VideoMode>^ res = gcnew cli::array<VideoMode>(*c);
		for (int i = 0; i < res->Length; ++i)
		{
			res[i] = VideoMode(modes[i]);
		}
		return res;
	}
	VideoMode Glfw::GetVideoMode(Monitor^ monitor)
	{
		const GLFWvidmode* mode = glfwGetVideoMode(monitor->handle);
		return VideoMode(*mode);
	}
	void Glfw::SetGamma(Monitor^ monitor, float gamma)
	{
		glfwSetGamma(monitor->handle, gamma);
	}
	GammaRamp Glfw::GetGammaRamp(Monitor^ monitor)
	{
		const GLFWgammaramp* ramp = glfwGetGammaRamp(monitor->handle);
		return GammaRamp(*ramp);
	}
	void Glfw::SetGammaRamp(Monitor^ monitor, GammaRamp ramp)
	{
		GLFWgammaramp r = ramp.ToNative();
		glfwSetGammaRamp(monitor->handle, &r);
	}
	void Glfw::DefaultWindowHints()
	{
		glfwDefaultWindowHints();
	}
	void Glfw::WindowHint(Hint hint, int value)
	{
		glfwWindowHint(static_cast<int>(hint), value);
	}
	void Glfw::WindowHint(Hint hint, bool value) { WindowHint(hint, value ? GLFW_TRUE : GLFW_FALSE); }
	void Glfw::WindowHint(Hint hint, ClientApi value) { WindowHint(hint, static_cast<int>(value)); }
	void Glfw::WindowHint(Hint hint, ContextApi value) { WindowHint(hint, static_cast<int>(value)); }
	void Glfw::WindowHint(Hint hint, Robustness value) { WindowHint(hint, static_cast<int>(value)); }
	void Glfw::WindowHint(Hint hint, Profile value) { WindowHint(hint, static_cast<int>(value)); }
	void Glfw::WindowHint(Hint hint, ReleaseBehaviour value) { WindowHint(hint, static_cast<int>(value)); }
	void Glfw::WindowHintString(Hint hint, String^ value)
	{
		glfwWindowHintString(static_cast<int>(hint), GLFWNET_SAFESTRINGTOSTRINGC_C_STR(value));
	}
	Window^ Glfw::CreateWindow(int width, int height, String^ title, Monitor^ monitor, Window^ share)
	{
		GLFWmonitor* m = GLFWNET_SAFEREF(monitor, handle);
		GLFWwindow* s = GLFWNET_SAFEREF(share, handle);
		GLFWwindow* w = glfwCreateWindow(width, height, GLFWNET_SAFESTRINGTOSTRINGC_C_STR(title), m, s);
		Window^ window = gcnew Window(w);
		SetupWindowEvents(window);
		return window;
	}
	void Glfw::DestroyWindow(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwDestroyWindow(window->handle);
	}
	bool Glfw::WindowShouldClose(Window^ window)
	{

		GLFWNET_ASSERT(window != nullptr);
		return	glfwWindowShouldClose(window->handle) == GLFW_TRUE;
	}
	void Glfw::SetWindowShouldClose(Window^ window, bool value)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetWindowShouldClose(window->handle, value ? GLFW_TRUE : GLFW_FALSE);
	}
	void Glfw::SetWindowTitle(Window^ window, String^ title)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetWindowTitle(window->handle, GLFWNET_SAFESTRINGTOSTRINGC_C_STR(title));
	}
	void Glfw::SetWindowIcon(Window^ window, int count, cli::array< Image>^ images)
	{
		GLFWNET_ASSERT(window != nullptr);
		GLFWimage* _images = count == 0 ? nullptr : new GLFWimage[count];
		for (int i = 0; i < count; ++i)
		{
			_images[i] = images[i].ToNative();
		}

		glfwSetWindowIcon(window->handle, count, _images);
		delete[] _images;
	}
	void Glfw::GetWindowPos(Window^ window, [OutAttribute] int% xpos, [OutAttribute] int% ypos)
	{
		GLFWNET_ASSERT(window != nullptr);
		pin_ptr<int> x = &xpos;
		pin_ptr<int> y = &ypos;
		glfwGetWindowPos(window->handle, x, y);
	}
	void Glfw::SetWindowPos(Window^ window, int xpos, int ypos)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetWindowPos(window->handle, xpos, ypos);
	}
	void Glfw::GetWindowSize(Window^ window, [OutAttribute] int% width, [OutAttribute] int% height)
	{
		GLFWNET_ASSERT(window != nullptr);
		pin_ptr<int> w = &width;
		pin_ptr<int> h = &height;
		glfwGetWindowSize(window->handle, w, h);
	}
	void Glfw::SetWindowSizeLimits(Window^ window, int minwidth, int minheight, int maxwidth, int maxheight)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetWindowSizeLimits(window->handle, minwidth, minheight, maxwidth, maxheight);
	}
	void Glfw::SetWindowAspectRatio(Window^ window, int numer, int denom)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetWindowAspectRatio(window->handle, numer, denom);
	}
	void Glfw::SetWindowSize(Window^ window, int width, int height)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetWindowSize(window->handle, width, height);
	}
	void Glfw::GetFramebufferSize(Window^ window, [OutAttribute] int% width, [OutAttribute] int% height)
	{
		GLFWNET_ASSERT(window != nullptr);
		pin_ptr<int> w = &width;
		pin_ptr<int> h = &height;
		glfwGetFramebufferSize(window->handle, w, h);
	}
	void Glfw::GetWindowFrameSize(Window^ window, [OutAttribute] int% left, [OutAttribute] int% top, [OutAttribute] int% right, [OutAttribute] int% bottom)
	{
		GLFWNET_ASSERT(window != nullptr);
		pin_ptr<int> l = &left;
		pin_ptr<int> t = &top;
		pin_ptr<int> r = &right;
		pin_ptr<int> b = &bottom;
		glfwGetWindowFrameSize(window->handle, l, t, r, b);
	}
	void Glfw::GetWindowContentScale(Window^ window, [OutAttribute] float% xscale, [OutAttribute] float% yscale)
	{
		GLFWNET_ASSERT(window != nullptr);
		pin_ptr<float> x = &xscale;
		pin_ptr<float> y = &yscale;
		glfwGetWindowContentScale(window->handle, x, y);
	}
	float Glfw::GetWindowOpacity(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		return glfwGetWindowOpacity(window->handle);
	}
	void Glfw::SetWindowOpacity(Window^ window, float opacity)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetWindowOpacity(window->handle, opacity);
	}
	void Glfw::IconifyWindow(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwIconifyWindow(window->handle);
	}
	void Glfw::RestoreWindow(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwRestoreWindow(window->handle);
	}
	void Glfw::MaximizeWindow(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwMaximizeWindow(window->handle);
	}
	void Glfw::ShowWindow(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwShowWindow(window->handle);
	}
	void Glfw::HideWindow(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwHideWindow(window->handle);
	}
	void Glfw::FocusWindow(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwFocusWindow(window->handle);
	}
	void Glfw::RequestWindowAttention(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwRequestWindowAttention(window->handle);
	}
	Monitor^ Glfw::GetWindowMonitor(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		GLFWmonitor* monitor = glfwGetWindowMonitor(window->handle);
		return gcnew Monitor(monitor);
	}
	void Glfw::SetWindowMonitor(Window^ window, Monitor^ monitor, int xpos, int ypos, int width, int height, int refreshRate)
	{
		GLFWNET_ASSERT(window != nullptr);
		GLFWmonitor* _monitor = GLFWNET_SAFEREF(monitor, handle);
		glfwSetWindowMonitor(window->handle, _monitor, xpos, ypos, width, height, refreshRate);
	}
	int Glfw::GetWindowAttrib(Window^ window, WindowAttribute attrib)
	{
		GLFWNET_ASSERT(window != nullptr);
		return glfwGetWindowAttrib(window->handle, static_cast<int>(attrib));
	}
	void Glfw::SetWindowAttrib(Window^ window, WindowAttribute attrib, int value)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetWindowAttrib(window->handle, static_cast<int>(attrib), value);
	}
	void Glfw::SetWindowUserPointer(Window^ window, IntPtr pointer)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetWindowUserPointer(window->handle, pointer.ToPointer());
	}
	IntPtr Glfw::GetWindowUserPointer(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		void* pointer = glfwGetWindowUserPointer(window->handle);
		return IntPtr(pointer);
	}
	//WindowposCallback^ Glfw::SetWindowPosCallback(Window^ window, WindowposCallback^ callback) { return nullptr; }
	//WindowsizeCallback^ Glfw::SetWindowSizeCallback(Window^ window, WindowsizeCallback^ callback) { return nullptr; }
	//WindowcloseCallback^ Glfw::SetWindowCloseCallback(Window^ window, WindowcloseCallback^ callback) { return nullptr; }
	//WindowrefreshCallback^ Glfw::SetWindowRefreshCallback(Window^ window, WindowrefreshCallback^ callback) { return nullptr; }
	//WindowfocusCallback^ Glfw::SetWindowFocusCallback(Window^ window, WindowfocusCallback^ callback) { return nullptr; }
	//WindowiconifyCallback^ Glfw::SetWindowIconifyCallback(Window^ window, WindowiconifyCallback^ callback) { return nullptr; }
	//WindowmaximizeCallback^ Glfw::SetWindowMaximizeCallback(Window^ window, WindowmaximizeCallback^ callback) { return nullptr; }
	//FramebuffersizeCallback^ Glfw::SetFramebufferSizeCallback(Window^ window, FramebuffersizeCallback^ callback) { return nullptr; }
	//WindowcontentscaleCallback^ Glfw::SetWindowContentScaleCallback(Window^ window, WindowcontentscaleCallback^ callback) { return nullptr; }
	void Glfw::PollEvents()
	{
		glfwPollEvents();
	}
	void Glfw::WaitEvents()
	{
		glfwWaitEvents();
	}
	void Glfw::WaitEventsTimeout(double timeout)
	{
		glfwWaitEventsTimeout(timeout);
	}
	void Glfw::PostEmptyEvent()
	{
		glfwPostEmptyEvent();
	}
	int Glfw::GetInputMode(Window^ window, InputMode mode)
	{
		GLFWNET_ASSERT(window != nullptr);
		return glfwGetInputMode(window->handle, static_cast<int>(mode));
	}
	void Glfw::SetInputMode(Window^ window, InputMode mode, int value)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetInputMode(window->handle, static_cast<int>(mode), value);
	}
	int Glfw::RawMouseMotionSupported()
	{
		return glfwRawMouseMotionSupported();
	}
	String^ Glfw::GetKeyName(Key key, int scancode)
	{
		const char* name = glfwGetKeyName(static_cast<int>(key), scancode);
		return gcnew String(name);
	}
	int Glfw::GetKeyScancode(Key key)
	{
		return glfwGetKeyScancode(static_cast<int>(key));
	}
	InputState Glfw::GetKey(Window^ window, Key key)
	{
		GLFWNET_ASSERT(window != nullptr);
		return static_cast<InputState>(glfwGetKey(window->handle, static_cast<int>(key)));
	}
	InputState Glfw::GetMouseButton(Window^ window, MouseButton button)
	{
		GLFWNET_ASSERT(window != nullptr);
		return static_cast<InputState>(glfwGetMouseButton(window->handle, static_cast<int>(button)));
	}
	void Glfw::GetCursorPos(Window^ window, [OutAttribute] double% xpos, [OutAttribute] double% ypos)
	{
		GLFWNET_ASSERT(window != nullptr);
		pin_ptr<double> x = &xpos;
		pin_ptr<double>y = &ypos;
		glfwGetCursorPos(window->handle, x, y);
	}
	void Glfw::SetCursorPos(Window^ window, double xpos, double ypos)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetCursorPos(window->handle, xpos, ypos);
	}
	Cursor^ Glfw::CreateCursor(Image image, int xhot, int yhot)
	{
		GLFWimage _image = image.ToNative();
		GLFWcursor* cursor = glfwCreateCursor(&_image, xhot, yhot);
		return gcnew Cursor(cursor);
	}
	Cursor^ Glfw::CreateStandardCursor(int shape)
	{
		GLFWcursor* cursor = glfwCreateStandardCursor(shape);
		return gcnew Cursor(cursor);
	}
	void Glfw::DestroyCursor(Cursor^ cursor)
	{
		GLFWNET_ASSERT(cursor != nullptr);
		glfwDestroyCursor(cursor->handle);
	}
	void Glfw::SetCursor(Window^ window, Cursor^ cursor)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetCursor(window->handle, GLFWNET_SAFEREF(cursor, handle));
	}
	//KeyCallback^ Glfw::SetKeyCallback(Window^ window, KeyCallback^ callback)
	//{
	//	return nullptr;
	//	GLFWNET_ASSERT(window != nullptr);
	//	GLFWkeyfun keyFun = nullptr;
	//	if (callback == nullptr)
	//	{
	//		keyFun = glfwSetKeyCallback(window->handle, nullptr);
	//		if (keyFun == nullptr) { return nullptr; }
	//		return Marshal::GetDelegateForFunctionPointer<KeyCallback^>(IntPtr(keyFun));
	//	}
	//
	//	GCHandle handle= GCHandle::Alloc(callback);
	//	IntPtr ip = Marshal::GetFunctionPointerForDelegate(callback);
	//	keyFun = static_cast<GLFWkeyfun>(ip.ToPointer());
	//	GC::Collect();
	//
	//	keyFun = glfwSetKeyCallback(window->handle, keyFun);
	//	handle.Free();
	//
	//	if (keyFun == nullptr) { return nullptr; }
	//	return Marshal::GetDelegateForFunctionPointer<KeyCallback^>(IntPtr(keyFun));
	//}
	//CharCallback^ Glfw::SetCharCallback(Window^ window, CharCallback^ callback) { return nullptr; }
	//CharmodsCallback^ Glfw::SetCharModsCallback(Window^ window, CharmodsCallback^ callback) { return nullptr; }
	//MousebuttonCallback^ Glfw::SetMouseButtonCallback(Window^ window, MousebuttonCallback^ callback) { return nullptr; }
	//CursorposCallback^ Glfw::SetCursorPosCallback(Window^ window, CursorposCallback^ callback) { return nullptr; }
	//CursorenterCallback^ Glfw::SetCursorEnterCallback(Window^ window, CursorenterCallback^ callback) { return nullptr; }
	//ScrollCallback^ Glfw::SetScrollCallback(Window^ window, ScrollCallback^ callback) { return nullptr; }
	//DropCallback^ Glfw::SetDropCallback(Window^ window, DropCallback^ callback) { return nullptr; }
	int Glfw::JoystickPresent(Joystick jid)
	{
		return glfwJoystickPresent(static_cast<int>(jid));
	}
	cli::array<float>^ Glfw::GetJoystickAxes(Joystick jid, [OutAttribute] int% count)
	{
		pin_ptr<int> c = &count;
		const float* axes = glfwGetJoystickAxes(static_cast<int>(jid), c);
		cli::array<float>^ arr = gcnew cli::array<float>(*c);
		for (int i = 0; i < *c; i++)
		{
			arr[i] = axes[i];
		}
		return arr;
	}
	cli::array<InputState>^ Glfw::GetJoystickButtons(Joystick jid, [OutAttribute] int% count)
	{
		pin_ptr<int> c = &count;
		const unsigned char* buttons = glfwGetJoystickButtons(static_cast<int>(jid), c);
		cli::array<InputState>^ arr = gcnew cli::array<InputState>(*c);
		for (int i = 0; i < *c; i++)
		{
			arr[i] = static_cast<InputState>(buttons[i]);
		}
		return arr;
	}
	cli::array<JoystickHatState>^ Glfw::GetJoystickHats(Joystick jid, [OutAttribute] int% count)
	{
		pin_ptr<int> c = &count;
		const unsigned char* hats = glfwGetJoystickHats(static_cast<int>(jid), c);
		cli::array<JoystickHatState>^ arr = gcnew cli::array<JoystickHatState>(*c);
		for (int i = 0; i < *c; i++)
		{
			arr[i] = static_cast<JoystickHatState>(hats[i]);
		}
		return arr;
	}
	String^ Glfw::GetJoystickName(Joystick jid)
	{
		const char* name = glfwGetJoystickName(static_cast<int>(jid));
		return gcnew String(name);
	}
	String^ Glfw::GetJoystickGUID(Joystick jid)
	{
		const char* guid = glfwGetJoystickGUID(static_cast<int>(jid));
		return gcnew String(guid);
	}
	void Glfw::SetJoystickUserPointer(Joystick jid, IntPtr pointer)
	{
		glfwSetJoystickUserPointer(static_cast<int>(jid), pointer.ToPointer());
	}
	IntPtr Glfw::GetJoystickUserPointer(Joystick jid)
	{
		void* pointer = glfwGetJoystickUserPointer(static_cast<int>(jid));
		return IntPtr(pointer);
	}
	int Glfw::JoystickIsGamepad(Joystick jid)
	{
		return glfwJoystickIsGamepad(static_cast<int>(jid));
	}
	//JoystickCallback^ Glfw::SetJoystickCallback(JoystickCallback^ callback) { return nullptr; }
	int Glfw::UpdateGamepadMappings(String^ string)
	{
		return glfwUpdateGamepadMappings(GLFWNET_SAFESTRINGTOSTRINGC_C_STR(string));
	}
	String^ Glfw::GetGamepadName(Joystick jid)
	{
		const char* name = glfwGetGamepadName(static_cast<int>(jid));
		return gcnew String(name);
	}
	int Glfw::GetGamepadState(Joystick jid, [OutAttribute] GamepadState% state)
	{
		GLFWgamepadstate _state{};
		int ret = glfwGetGamepadState(static_cast<int>(jid), &_state);
		state = GamepadState(_state);
		return ret;
	}
	void Glfw::SetClipboardString(Window^ window, String^ string)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSetClipboardString(window->handle, GLFWNET_SAFESTRINGTOSTRINGC_C_STR(string));
	}
	String^ Glfw::GetClipboardString(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		const char* string = glfwGetClipboardString(window->handle);
		return gcnew String(string);
	}
	double Glfw::GetTime()
	{
		return glfwGetTime();
	}
	void Glfw::SetTime(double time)
	{
		glfwSetTime(time);
	}
	uint64_t Glfw::GetTimerValue()
	{
		return glfwGetTimerValue();
	}
	uint64_t Glfw::GetTimerFrequency()
	{
		return glfwGetTimerFrequency();
	}
	void Glfw::MakeContextCurrent(Window^ window)
	{
		glfwMakeContextCurrent(GLFWNET_SAFEREF(window, handle));
	}
	Window^ Glfw::GetCurrentContext()
	{
		GLFWwindow* window = glfwGetCurrentContext();
		return gcnew Window(window);
	}
	void Glfw::SwapBuffers(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		glfwSwapBuffers(window->handle);
	}
	void Glfw::SwapInterval(int interval)
	{
		glfwSwapInterval(interval);
	}
	int Glfw::ExtensionSupported(String^ extension)
	{
		return glfwExtensionSupported(GLFWNET_SAFESTRINGTOSTRINGC_C_STR(extension));
	}
	GlCallback^ Glfw::GetProcAddress(String^ procname)
	{
		GLFWglproc proc = glfwGetProcAddress(GLFWNET_SAFESTRINGTOSTRINGC_C_STR(procname));
		GlCallback^ callback = Marshal::GetDelegateForFunctionPointer<GlCallback^>(IntPtr(proc));
		return callback;
	}
	generic<class T> T Glfw::GetProcAddress(String^ procname)
	{
		GLFWglproc proc = glfwGetProcAddress(GLFWNET_SAFESTRINGTOSTRINGC_C_STR(procname));
		T callback = Marshal::GetDelegateForFunctionPointer<T>(IntPtr(proc));
		return callback;
	}
	int Glfw::VulkanSupported(void)
	{
		return glfwVulkanSupported();
	}
	cli::array<String^>^ Glfw::GetRequiredInstanceExtensions([OutAttribute] uint32_t% count)
	{
		pin_ptr<uint32_t> c = &count;
		const char** extensions = glfwGetRequiredInstanceExtensions(c);
		cli::array<String^>^ arr = gcnew cli::array<String^>(*c);
		for (uint32_t i = 0; i < *c; i++)
		{
			arr[i] = gcnew String(extensions[i]);
		}
		return arr;
	}

	void Glfw::SetupWindowEvents(Window^ window)
	{
		GLFWNET_ASSERT(window != nullptr);
		GLFWwindow* _window = window->handle;

		glfwSetWindowPosCallback(_window, Windowposfun);
		glfwSetWindowSizeCallback(_window, Windowsizefun);
		glfwSetWindowCloseCallback(_window, Windowclosefun);
		glfwSetWindowRefreshCallback(_window, Windowrefreshfun);
		glfwSetWindowFocusCallback(_window, Windowfocusfun);
		glfwSetWindowIconifyCallback(_window, Windowiconifyfun);
		glfwSetWindowMaximizeCallback(_window, Windowmaximizefun);
		glfwSetFramebufferSizeCallback(_window, Framebuffersizefun);
		glfwSetWindowContentScaleCallback(_window, Windowcontentscalefun);
		glfwSetMouseButtonCallback(_window, Mousebuttonfun);
		glfwSetCursorPosCallback(_window, Cursorposfun);
		glfwSetCursorEnterCallback(_window, Cursorenterfun);
		glfwSetScrollCallback(_window, Scrollfun);
		glfwSetKeyCallback(_window, Keyfun);
		glfwSetCharCallback(_window, Charfun);
		glfwSetCharModsCallback(_window, Charmodsfun);
		glfwSetDropCallback(_window, Dropfun);

	}



	void Errorfun(int error_code, const char* description)
	{
		Glfw::OnError(static_cast<ErrorCode>(error_code), gcnew String(description));
	}
	void Windowposfun(GLFWwindow* window, int xpos, int ypos)
	{
		Glfw::OnWindowPosition(gcnew Window(window), xpos, ypos);
	}
	void Windowsizefun(GLFWwindow* window, int width, int height)
	{
		Glfw::OnWindowSize(gcnew Window(window), width, height);
	}
	void Windowclosefun(GLFWwindow* window)
	{
		Glfw::OnWindowClose(gcnew Window(window));
	}
	void Windowrefreshfun(GLFWwindow* window)
	{
		Glfw::OnWindowRefresh(gcnew Window(window));
	}
	void Windowfocusfun(GLFWwindow* window, int focused)
	{
		Glfw::OnWindowFocus(gcnew Window(window), focused == GLFW_TRUE);
	}
	void Windowiconifyfun(GLFWwindow* window, int iconified)
	{
		Glfw::OnWindowIconify(gcnew Window(window), iconified == GLFW_TRUE);
	}
	void Windowmaximizefun(GLFWwindow* window, int maximized)
	{
		Glfw::OnWindowMaximize(gcnew Window(window), maximized == GLFW_TRUE);
	}
	void Framebuffersizefun(GLFWwindow* window, int width, int height)
	{
		Glfw::OnFramebufferSize(gcnew Window(window), width, height);
	}
	void Windowcontentscalefun(GLFWwindow* window, float xscale, float yscale)
	{
		Glfw::OnWindowContentScale(gcnew Window(window), xscale, yscale);
	}
	void Mousebuttonfun(GLFWwindow* window, int button, int action, int mods)
	{
		Glfw::OnMouseButton(gcnew Window(window), static_cast<MouseButton>(button), static_cast<InputState>(action), static_cast<KeyModifiers>(mods));
	}
	void Cursorposfun(GLFWwindow* window, double xpos, double ypos)
	{
		Glfw::OnCursorPosition(gcnew Window(window), xpos, ypos);
	}
	void Cursorenterfun(GLFWwindow* window, int entered)
	{
		Glfw::OnCursorEnter(gcnew Window(window), entered == GLFW_TRUE);
	}
	void Scrollfun(GLFWwindow* window, double xoffset, double yoffset)
	{
		Glfw::OnScroll(gcnew Window(window), xoffset, yoffset);
	}
	void Keyfun(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Glfw::OnKey(gcnew Window(window), static_cast<Key>(key), scancode, static_cast<InputState>(action), static_cast<KeyModifiers>(mods));
	}
	void Charfun(GLFWwindow* window, unsigned int codepoint)
	{
		Glfw::OnChar(gcnew Window(window), codepoint);
	}
	void Charmodsfun(GLFWwindow* window, unsigned int codepoint, int mods)
	{
		Glfw::OnCharModifier(gcnew Window(window), codepoint, static_cast<KeyModifiers>(mods));
	}
	void Dropfun(GLFWwindow* window, int path_count, const char* paths[])
	{
		cli::array<String^>^ _paths = gcnew cli::array<String^>(path_count);
		for (int i = 0; i < path_count; ++i)
		{
			_paths[i] = gcnew String(paths[i]);
		}
		Glfw::OnDrop(gcnew Window(window), _paths);
	}
	void Monitorfun(GLFWmonitor* monitor, int evt)
	{
		Glfw::OnMonitor(gcnew Monitor(monitor), static_cast<ConnectionStatus>(evt));
	}
	void Joystickfun(int jid, int evt)
	{
		Glfw::OnJoystick(static_cast<Joystick>(jid), static_cast<ConnectionStatus>(evt));
	}
}