#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public enum class Hint :int32_t
	{
		Focused = GLFW_FOCUSED,
		Resizable = GLFW_RESIZABLE,
		Visible = GLFW_VISIBLE,
		Decorated = GLFW_DECORATED,
		AutoIconify = GLFW_AUTO_ICONIFY,
		Floating = GLFW_FLOATING,
		Maximized = GLFW_MAXIMIZED,
		CenterCursor = GLFW_CENTER_CURSOR,
		TransparentFramebuffer = GLFW_TRANSPARENT_FRAMEBUFFER,
		FocusOnShow = GLFW_FOCUS_ON_SHOW,
		RedBits = GLFW_RED_BITS,
		GreenBits = GLFW_GREEN_BITS,
		BlueBits = GLFW_BLUE_BITS,
		AlphaBits = GLFW_ALPHA_BITS,
		DepthBits = GLFW_DEPTH_BITS,
		StencilBits = GLFW_STENCIL_BITS,
		AccumRedBits = GLFW_ACCUM_RED_BITS,
		AccumGreenBits = GLFW_ACCUM_GREEN_BITS,
		AccumBlueBits = GLFW_ACCUM_BLUE_BITS,
		AccumAlphaBits = GLFW_ACCUM_ALPHA_BITS,
		AuxBuffers = GLFW_AUX_BUFFERS,
		Stereo = GLFW_STEREO,
		Samples = GLFW_SAMPLES,
		SrgbCapable = GLFW_SRGB_CAPABLE,
		RefreshRate = GLFW_REFRESH_RATE,
		Doublebuffer = GLFW_DOUBLEBUFFER,
		ClientApi = GLFW_CLIENT_API,
		ContextVersionMajor = GLFW_CONTEXT_VERSION_MAJOR,
		ContextVersionMinor = GLFW_CONTEXT_VERSION_MINOR,
		ContextRevision = GLFW_CONTEXT_REVISION,
		ContextRobustness = GLFW_CONTEXT_ROBUSTNESS,
		OpenGlForwardCompat = GLFW_OPENGL_FORWARD_COMPAT,
		OpenGlDebugContext = GLFW_OPENGL_DEBUG_CONTEXT,
		OpenGlProfile = GLFW_OPENGL_PROFILE,
		ContextReleaseBehavior = GLFW_CONTEXT_RELEASE_BEHAVIOR,
		ContextNoError = GLFW_CONTEXT_NO_ERROR,
		ContextCreationApi = GLFW_CONTEXT_CREATION_API,
		ScaleToMonitor = GLFW_SCALE_TO_MONITOR,
		CocoaRetinaFramebuffer = GLFW_COCOA_RETINA_FRAMEBUFFER,
		CocoaFrameName = GLFW_COCOA_FRAME_NAME,
		CocoaGraphicsSwitching = GLFW_COCOA_GRAPHICS_SWITCHING,
		X11ClassName = GLFW_X11_CLASS_NAME,
		X11InstanceName = GLFW_X11_INSTANCE_NAME,
		JoystickHatButtons = GLFW_JOYSTICK_HAT_BUTTONS,
		CocoaChDirResources = GLFW_COCOA_CHDIR_RESOURCES,
		CocoaMenuBar = GLFW_COCOA_MENUBAR,

	};
}