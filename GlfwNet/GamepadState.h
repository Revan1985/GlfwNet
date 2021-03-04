#pragma once

#include <GLFW/glfw3.h>

#include "InputState.h"

namespace GlfwNet
{
	public value class GamepadState
	{
		initonly cli::array<InputState>^ Buttons;		// 15
		initonly cli::array<float>^ Axes;				// 6
	internal:
		static const size_t BUTTONS_COUNT = 15;
		static const size_t AXES_COUNT = 6;
		GamepadState(GLFWgamepadstate state)
		{
			Buttons = gcnew cli::array<InputState>(BUTTONS_COUNT);
			Axes = gcnew cli::array<float>(AXES_COUNT);

			for (int i = 0; i < Buttons->Length; ++i)
			{
				Buttons[i] = static_cast<InputState>(state.buttons[i]);
			}
			for (int i = 0; i < Axes->Length; i++)
			{
				Axes[i] = state.axes[i];
			}
		}
		GLFWgamepadstate ToNative()
		{
			GLFWgamepadstate state{};
			for (int i = 0; i < Axes->Length; i++)
			{
				state.axes[i] = Axes[i];
			}
			for (int i = 0; i < Buttons->Length; i++)
			{
				state.buttons[i] = static_cast<unsigned char>(Buttons[i]);
			}

			return state;
		}

	};
}