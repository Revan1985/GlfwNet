#pragma once

#include "pch.h"
#include "Cursor.h"
#include "Delegates.h"
#include "GamepadState.h"
#include "GammaRamp.h"
#include "Image.h"
#include "Monitor.h"
#include "PlatformHint.h"
#include "VideoMode.h"
#include "Window.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace GlfwNet
{
	public ref struct Glfw abstract sealed /* abstract sealed equals static in .net (c#) */
	{
		static Glfw ();

		static bool Init ();
		static void Terminate ();
		static void InitHint (Hint hint, int value);
		static void GetVersion ([OutAttribute] int% major, [OutAttribute] int% minor, [OutAttribute] int% rev);
		static String^ GetVersionString ();
		static ErrorCode GetError ([OutAttribute] String^% description);
		//static ErrorCallback^ SetErrorCallback(ErrorCallback^ callback);
		static cli::array<Monitor^>^ GetMonitors ([OutAttribute] int% count);
		static Monitor^ GetPrimaryMonitor ();
		static void GetMonitorPosition (Monitor^ monitor, [OutAttribute] int% xpos, [OutAttribute] int% ypos);
		static void GetMonitorWorkarea (Monitor^ monitor, [OutAttribute] int% xpos, [OutAttribute] int% ypos, [OutAttribute] int% width, [OutAttribute] int% height);
		static void GetMonitorPhysicalSize (Monitor^ monitor, [OutAttribute] int% widthMM, [OutAttribute] int% heightMM);
		static void GetMonitorContentScale (Monitor^ monitor, [OutAttribute] float% xscale, [OutAttribute] float% yscale);
		static String^ GetMonitorName (Monitor^ monitor);
		static void SetMonitorUserPointer (Monitor^ monitor, IntPtr pointer);
		static IntPtr GetMonitorUserPointer (Monitor^ monitor);
		static MonitorCallback^ SetMonitorCallback (MonitorCallback^ callback);
		static cli::array<VideoMode>^ GetVideoModes (Monitor^ monitor, [OutAttribute] int% count);
		static VideoMode GetVideoMode (Monitor^ monitor);

		static void SetGamma (Monitor^ monitor, float gamma);
		static GammaRamp GetGammaRamp (Monitor^ monitor);
		static void SetGammaRamp (Monitor^ monitor, GammaRamp ramp);

		static void DefaultWindowHints ();

		static void WindowHint (Hint hint, int value);
		static void WindowHint (Hint hint, bool value);
		static void WindowHint (Hint hint, ClientApi value);
		static void WindowHint (Hint hint, ContextApi value);
		static void WindowHint (Hint hint, Robustness value);
		static void WindowHint (Hint hint, Profile value);
		static void WindowHint (Hint hint, ReleaseBehaviour value);
		static void WindowHintString (Hint hint, String^ value);

		static Window^ CreateWindow (int width, int height, String^ title, Monitor^ monitor, Window^ share);
		static void DestroyWindow (Window^ window);
		static bool WindowShouldClose (Window^ window);
		static void SetWindowShouldClose (Window^ window, bool value);
		static void SetWindowTitle (Window^ window, String^ title);
		static void SetWindowIcon (Window^ window, int count, cli::array<Image>^ images);
		static void GetWindowPos (Window^ window, [OutAttribute] int% xpos, [OutAttribute] int% ypos);
		static void SetWindowPos (Window^ window, int xpos, int ypos);
		static void GetWindowSize (Window^ window, [OutAttribute] int% width, [OutAttribute] int% height);
		static void SetWindowSizeLimits (Window^ window, int minwidth, int minheight, int maxwidth, int maxheight);
		static void SetWindowAspectRatio (Window^ window, int numer, int denom);
		static void SetWindowSize (Window^ window, int width, int height);
		static void GetFramebufferSize (Window^ window, [OutAttribute] int% width, [OutAttribute] int% height);
		static void GetWindowFrameSize (Window^ window, [OutAttribute] int% left, [OutAttribute] int% top, [OutAttribute] int% right, [OutAttribute] int% bottom);
		static void GetWindowContentScale (Window^ window, [OutAttribute] float% xscale, [OutAttribute] float% yscale);
		static float GetWindowOpacity (Window^ window);
		static void SetWindowOpacity (Window^ window, float opacity);
		static void IconifyWindow (Window^ window);
		static void RestoreWindow (Window^ window);
		static void MaximizeWindow (Window^ window);
		static void ShowWindow (Window^ window);
		static void HideWindow (Window^ window);
		static void FocusWindow (Window^ window);
		static void RequestWindowAttention (Window^ window);
		static Monitor^ GetWindowMonitor (Window^ window);
		static void SetWindowMonitor (Window^ window, Monitor^ monitor, int xpos, int ypos, int width, int height, int refreshRate);
		static int GetWindowAttrib (Window^ window, WindowAttribute attrib);
		static void SetWindowAttrib (Window^ window, WindowAttribute attrib, int value);
		static void SetWindowUserPointer (Window^ window, IntPtr pointer);
		static IntPtr GetWindowUserPointer (Window^ window);

		//static WindowposCallback^ SetWindowPosCallback(Window^ window, WindowposCallback^ callback);
		//static WindowsizeCallback^ SetWindowSizeCallback(Window^ window, WindowsizeCallback^ callback);
		//static WindowcloseCallback^ SetWindowCloseCallback(Window^ window, WindowcloseCallback^ callback);
		//static WindowrefreshCallback^ SetWindowRefreshCallback(Window^ window, WindowrefreshCallback^ callback);
		//static WindowfocusCallback^ SetWindowFocusCallback(Window^ window, WindowfocusCallback^ callback);
		//static WindowiconifyCallback^ SetWindowIconifyCallback(Window^ window, WindowiconifyCallback^ callback);
		//static WindowmaximizeCallback^ SetWindowMaximizeCallback(Window^ window, WindowmaximizeCallback^ callback);
		//static FramebuffersizeCallback^ SetFramebufferSizeCallback(Window^ window, FramebuffersizeCallback^ callback);
		//static WindowcontentscaleCallback^ SetWindowContentScaleCallback(Window^ window, WindowcontentscaleCallback^ callback);

		static void PollEvents ();
		static void WaitEvents ();
		static void WaitEventsTimeout (double timeout);
		static void PostEmptyEvent ();
		static int GetInputMode (Window^ window, InputMode mode);
		static void SetInputMode (Window^ window, InputMode mode, int value);
		static int RawMouseMotionSupported ();
		static String^ GetKeyName (Key key, int scancode);
		static int GetKeyScancode (Key key);
		static InputState GetKey (Window^ window, Key key);
		static InputState GetMouseButton (Window^ window, MouseButton button);
		static void GetCursorPos (Window^ window, [OutAttribute] double% xpos, [OutAttribute] double% ypos);
		static void SetCursorPos (Window^ window, double xpos, double ypos);
		static Cursor^ CreateCursor (Image image, int xhot, int yhot);
		static Cursor^ CreateStandardCursor (int shape);
		static void DestroyCursor (Cursor^ cursor);
		static void SetCursor (Window^ window, Cursor^ cursor);

		//static KeyCallback^ SetKeyCallback(Window^ window, KeyCallback^ callback);
		//static CharCallback^ SetCharCallback(Window^ window, CharCallback^ callback);
		//static CharmodsCallback^ SetCharModsCallback(Window^ window, CharmodsCallback^ callback);
		//static MousebuttonCallback^ SetMouseButtonCallback(Window^ window, MousebuttonCallback^ callback);
		//static CursorposCallback^ SetCursorPosCallback(Window^ window, CursorposCallback^ callback);
		//static CursorenterCallback^ SetCursorEnterCallback(Window^ window, CursorenterCallback^ callback);
		//static ScrollCallback^ SetScrollCallback(Window^ window, ScrollCallback^ callback);
		//static DropCallback^ SetDropCallback(Window^ window, DropCallback^ callback);

		static int JoystickPresent (Joystick jid);
		static cli::array<float>^ GetJoystickAxes (Joystick jid, [OutAttribute] int% count);
		static cli::array<InputState>^ GetJoystickButtons (Joystick jid, [OutAttribute] int% count);
		static cli::array<JoystickHatState>^ GetJoystickHats (Joystick jid, [OutAttribute] int% count);
		static String^ GetJoystickName (Joystick jid);
		static String^ GetJoystickGUID (Joystick jid);
		static void SetJoystickUserPointer (Joystick jid, IntPtr pointer);
		static IntPtr GetJoystickUserPointer (Joystick jid);
		static int JoystickIsGamepad (Joystick jid);
		//static JoystickCallback^ SetJoystickCallback(JoystickCallback^ callback);
		static int UpdateGamepadMappings (String^ string);
		static String^ GetGamepadName (Joystick jid);
		static int GetGamepadState (Joystick jid, [OutAttribute] GamepadState% state);
		static void SetClipboardString (Window^ window, String^ string);
		static String^ GetClipboardString (Window^ window);

		static double GetTime ();
		static void SetTime (double time);
		static uint64_t GetTimerValue ();
		static uint64_t GetTimerFrequency ();
		static void MakeContextCurrent (Window^ window);
		static Window^ GetCurrentContext ();
		static void SwapBuffers (Window^ window);
		static void SwapInterval (int interval);
		static int ExtensionSupported (String^ extension);
		static GlCallback^ GetProcAddress (String^ procname);
		generic<class T> static T GetProcAddress (String^ procname);
		static int VulkanSupported (void);
		static cli::array<String^>^ GetRequiredInstanceExtensions ([OutAttribute] uint32_t% count);

		static void SetupWindowEvents (Window^ window);

#if defined(VK_VERSION_1_0)

		//GLFWAPI GLFWvkproc glfwGetInstanceProcAddress(VkInstance instance, const char* procname);
		//GLFWAPI int glfwGetPhysicalDevicePresentationSupport(VkInstance instance, VkPhysicalDevice device, uint32_t queuefamily);
		//GLFWAPI VkResult glfwCreateWindowSurface(VkInstance instance, GLFWwindow* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface);

#endif
		static PlatformHint GetPlatform ();
		static bool PlatformSupported (PlatformHint platform);

		static String^ GetWindowTitle (Window^ window);

	private:
		//static AllocateCallback^ _OnAllocate;
		//static ReallocateCallback^ _OnReallocate;
		//static DeallocateCallback^ _OnDeallocate;
		static ErrorCallback^ _OnError;
		static WindowPositionCallback^ _OnWindowPosition;
		static WindowSizeCallback^ _OnWindowSize;
		static WindowCloseCallback^ _OnWindowClose;
		static WindowRefreshCallback^ _OnWindowRefresh;
		static WindowFocusCallback^ _OnWindowFocus;
		static WindowIconifyCallback^ _OnWindowIconify_;
		static WindowMaximizeCallback^ _OnWindowMaximize;
		static FramebufferSizeCallback^ _OnFramebufferSize;
		static WindowContentScaleCallback^ _OnWindowContentScale;
		static MouseButtonCallback^ _OnMouseButton;
		static CursorPositionCallback^ _OnCursorPosition;
		static CursorEnterCallback^ _OnCursorEnter;
		static ScrollCallback^ _OnScroll;
		static KeyCallback^ _OnKey;
		static CharCallback^ _OnChar;
		static CharmodsCallback^ _OnCharModifier;
		static DropCallback^ _OnDrop;
		static MonitorCallback^ _OnMonitor;
		static JoystickCallback^ _OnJoystick;
	public:
		/*static event AllocateCallback^ OnAllocate
		{
			void add (AllocateCallback^ callback) { _OnAllocate += callback; }
			void remove (AllocateCallback^ callback) { _OnAllocate -= callback; }
		internal:
			void raise (unsigned int size, IntPtr user)
			{
				if (_OnAllocate != nullptr)
				{
					_OnAllocate (size, user);
				}
			}
		}
		static event ReallocateCallback^ OnReallocate
		{
			void add (ReallocateCallback^ callback) { _OnReallocate += callback; }
			void remove (ReallocateCallback^ callback) { _OnReallocate -= callback; }
		internal:
			IntPtr raise (IntPtr block, unsigned int size, IntPtr user)
			{
				if (_OnReallocate != nullptr)
				{
					_OnReallocate (block, size, user);
				}
			}
		}
		static event DeallocateCallback^ OnDeallocate
		{
			void add (DeallocateCallback^ callback) { _OnDeallocate += callback; }
			void remove (DeallocateCallback^ callback) { _OnDeallocate -= callback; }
		internal:
			void raise (IntPtr block, IntPtr user)
			{
				if (_OnDeallocate != nullptr)
				{
					_OnDeallocate (block, user);
				}
			}
		}
		*/
		static event ErrorCallback^ OnError
		{
			void add (ErrorCallback^ callback) { _OnError += callback; }
			void remove (ErrorCallback^ callback) { _OnError -= callback; }
		internal:
			void raise (ErrorCode error_code, String^ description)
			{
				if (_OnError != nullptr)
				{
					_OnError (error_code, description);
				}
			}
		}
		static event WindowPositionCallback^ OnWindowPosition
		{
			void add (WindowPositionCallback^ callback) { _OnWindowPosition += callback; }
			void remove (WindowPositionCallback^ callback) { _OnWindowPosition -= callback; }
		internal:
			void raise (Window^ window, int x, int y)
			{
				if (_OnWindowPosition != nullptr)
				{
					_OnWindowPosition (window, x, y);
				}
			}
		}//(Window^, int, int);
		static event WindowSizeCallback^ OnWindowSize {
			void add (WindowSizeCallback^ callback) { _OnWindowSize += callback; }
			void remove (WindowSizeCallback^ callback) { _OnWindowSize -= callback; }
		internal:
			void raise (Window^ window, int width, int height)
			{
				if (_OnWindowSize != nullptr)
				{
					_OnWindowSize (window, width, height);
				}
			}
		}
		static event WindowCloseCallback^ OnWindowClose {
			void add (WindowCloseCallback^ callback) { _OnWindowClose += callback; }
			void remove (WindowCloseCallback^ callback) { _OnWindowClose -= callback; }
		internal:
			void raise (Window^ window)
			{
				if (_OnWindowClose != nullptr)
				{
					_OnWindowClose (window);
				}
			}
		}
		static event WindowRefreshCallback^ OnWindowRefresh {
			void add (WindowRefreshCallback^ callback) { _OnWindowRefresh += callback; }
			void remove (WindowRefreshCallback^ callback) { _OnWindowRefresh -= callback; }
		internal:
			void raise (Window^ window)
			{
				if (_OnWindowRefresh != nullptr)
				{
					_OnWindowRefresh (window);
				}
			}
		}//(Window^);
		static event WindowFocusCallback^ OnWindowFocus {
			void add (WindowFocusCallback^ callback) { _OnWindowFocus += callback; }
			void remove (WindowFocusCallback^ callback) { _OnWindowFocus -= callback; }
		internal:
			void raise (Window^ window, bool focused)
			{
				if (_OnWindowFocus != nullptr)
				{
					_OnWindowFocus (window, focused);
				}
			}
		} //(Window^, int);
		static event WindowIconifyCallback^ OnWindowIconify {
			void add (WindowIconifyCallback^ callback) { _OnWindowIconify_ += callback; }
			void remove (WindowIconifyCallback^ callback) { _OnWindowIconify_ -= callback; }
		internal:
			void raise (Window^ window, bool iconified)
			{
				if (_OnWindowIconify_ != nullptr)
				{
					_OnWindowIconify_ (window, iconified);
				}
			}
		} //(Window^, int);
		static event WindowMaximizeCallback^ OnWindowMaximize {
			void add (WindowMaximizeCallback^ callback) { _OnWindowMaximize += callback; }
			void remove (WindowMaximizeCallback^ callback) { _OnWindowMaximize -= callback; }
		internal:
			void raise (Window^ window, bool maximized)
			{
				if (_OnWindowMaximize != nullptr)
				{
					_OnWindowMaximize (window, maximized);
				}
			}
		} //(Window^, int);
		static event FramebufferSizeCallback^ OnFramebufferSize {
			void add (FramebufferSizeCallback^ callback) { _OnFramebufferSize += callback; }
			void remove (FramebufferSizeCallback^ callback) { _OnFramebufferSize -= callback; }
		internal:
			void raise (Window^ window, int width, int height)
			{
				if (_OnFramebufferSize != nullptr)
				{
					_OnFramebufferSize (window, width, height);
				}
			}
		} //(Window^, int, int);
		static event WindowContentScaleCallback^ OnWindowContentScale {
			void add (WindowContentScaleCallback^ callback) { _OnWindowContentScale += callback; }
			void remove (WindowContentScaleCallback^ callback) { _OnWindowContentScale -= callback; }
		internal:
			void raise (Window^ window, float x, float y)
			{
				if (_OnWindowContentScale != nullptr)
				{
					_OnWindowContentScale (window, x, y);
				}
			}
		} //(Window^, float, float);
		static event MouseButtonCallback^ OnMouseButton {
			void add (MouseButtonCallback^ callback) { _OnMouseButton += callback; }
			void remove (MouseButtonCallback^ callback) { _OnMouseButton -= callback; }
		internal:
			void raise (Window^ window, MouseButton button, InputState state, KeyModifiers mods)
			{
				if (_OnMouseButton != nullptr)
				{
					_OnMouseButton (window, button, state, mods);
				}
			}
		} //(Window^, MouseButton, InputState, KeyModifiers);
		static event CursorPositionCallback^ OnCursorPosition {
			void add (CursorPositionCallback^ callback) { _OnCursorPosition += callback; }
			void remove (CursorPositionCallback^ callback) { _OnCursorPosition -= callback; }
		internal:
			void raise (Window^ window, double x, double y)
			{
				if (_OnCursorPosition != nullptr)
				{
					_OnCursorPosition (window, x, y);
				}
			}
		} //(Window^, double, double);
		static event CursorEnterCallback^ OnCursorEnter {
			void add (CursorEnterCallback^ callback) { _OnCursorEnter += callback; }
			void remove (CursorEnterCallback^ callback) { _OnCursorEnter -= callback; }
		internal:
			void raise (Window^ window, bool entered)
			{
				if (_OnCursorEnter != nullptr)
				{
					_OnCursorEnter (window, entered);
				}
			}
		} //(Window^, int);
		static event ScrollCallback^ OnScroll {
			void add (ScrollCallback^ callback) { _OnScroll += callback; }
			void remove (ScrollCallback^ callback) { _OnScroll -= callback; }
		internal:
			void raise (Window^ window, double x, double y)
			{
				if (_OnScroll != nullptr)
				{
					_OnScroll (window, x, y);
				}
			}
		} //(Window^, double, double);
		static event KeyCallback^ OnKey {
			void add (KeyCallback^ callback) { _OnKey += callback; }
			void remove (KeyCallback^ callback) { _OnKey -= callback; }
		internal:
			void raise (Window^ window, Key key, int scancode, InputState state, KeyModifiers mods)
			{
				if (_OnKey != nullptr)
				{
					_OnKey (window, key, scancode, state, mods);
				}
			}
		}//(Window^, Key, int, InputState, KeyModifiers);
		static event CharCallback^ OnChar {
			void add (CharCallback^ callback) { _OnChar += callback; }
			void remove (CharCallback^ callback) { _OnChar -= callback; }
		internal:
			void raise (Window^ window, unsigned int codepoint)
			{
				if (_OnChar != nullptr)
				{
					_OnChar (window, codepoint);
				}
			}
		} //(Window^, unsigned int);
		static event CharmodsCallback^ OnCharModifier {
			void add (CharmodsCallback^ callback) { _OnCharModifier += callback; }
			void remove (CharmodsCallback^ callback) { _OnCharModifier -= callback; }
		internal:
			void raise (Window^ window, unsigned int codepoint, KeyModifiers mods)
			{
				if (_OnCharModifier != nullptr)
				{
					_OnCharModifier (window, codepoint, mods);
				}
			}
		} //(Window^, unsigned int, KeyModifiers);
		static event DropCallback^ OnDrop {
			void add (DropCallback^ callback) { _OnDrop += callback; }
			void remove (DropCallback^ callback) { _OnDrop -= callback; }
		internal:
			void raise (Window^ window, cli::array<String^>^ paths)
			{
				if (_OnDrop != nullptr)
				{
					_OnDrop (window, paths);
				}
			}
		} //(Window^, int, cli::array<String^>^);
		static event MonitorCallback^ OnMonitor {
			void add (MonitorCallback^ callback) { _OnMonitor += callback; }
			void remove (MonitorCallback^ callback) { _OnMonitor -= callback; }
		internal:
			void raise (Monitor^ monitor, ConnectionStatus status)
			{
				if (_OnMonitor != nullptr)
				{
					_OnMonitor (monitor, status);
				}
			}
		} //(Monitor^, ConnectionStatus);
		static event JoystickCallback^ OnJoystick {
			void add (JoystickCallback^ callback) { _OnJoystick += callback; }
			void remove (JoystickCallback^ callback) { _OnJoystick -= callback; }
		internal:
			void raise (Joystick jid, ConnectionStatus status)
			{
				if (_OnJoystick != nullptr)
				{
					_OnJoystick (static_cast<Joystick>(jid), status);
				}
			}
		} //(int, ConnectionStatus);
	};

	void Errorfun (int, const char*);
	void* Allocatefun (unsigned int, void*);
	void* Reallocatefun (void*, unsigned int, void*);
	void Deallocatefun (void*, void*);
	void Windowposfun (GLFWwindow*, int, int);
	void Windowsizefun (GLFWwindow*, int, int);
	void Windowclosefun (GLFWwindow*);
	void Windowrefreshfun (GLFWwindow*);
	void Windowfocusfun (GLFWwindow*, int);
	void Windowiconifyfun (GLFWwindow*, int);
	void Windowmaximizefun (GLFWwindow*, int);
	void Framebuffersizefun (GLFWwindow*, int, int);
	void Windowcontentscalefun (GLFWwindow*, float, float);
	void Mousebuttonfun (GLFWwindow*, int, int, int);
	void Cursorposfun (GLFWwindow*, double, double);
	void Cursorenterfun (GLFWwindow*, int);
	void Scrollfun (GLFWwindow*, double, double);
	void Keyfun (GLFWwindow*, int, int, int, int);
	void Charfun (GLFWwindow*, unsigned int);
	void Charmodsfun (GLFWwindow*, unsigned int, int);
	void Dropfun (GLFWwindow*, int, const char* []);
	void Monitorfun (GLFWmonitor*, int);
	void Joystickfun (int, int);
}
