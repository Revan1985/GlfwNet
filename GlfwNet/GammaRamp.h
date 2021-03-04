#pragma once

#include <GLFW/glfw3.h>

namespace GlfwNet
{
	public value class GammaRamp
	{
        initonly cli::array<unsigned short>^ Red;
        initonly cli::array<unsigned short>^ Green;
        initonly cli::array<unsigned short>^ Blue;
        initonly unsigned int Size;

        GammaRamp(cli::array<unsigned short>^ red, cli::array<unsigned short>^ green, cli::array<unsigned short>^ blue)
        {
            if (red->Length != green->Length && red->Length != blue->Length)
            {
                throw gcnew System::ArgumentException("Red, Green and Blue must all be equal length");
            }

            Red = red;
            Green = green;
            Blue = blue;
            Size = Red->Length;
        }

    internal:
        GammaRamp(GLFWgammaramp ramp)
        {
            Size = ramp.size;
            Red = gcnew cli::array<unsigned short>(ramp.size);
            Green = gcnew cli::array<unsigned short>(ramp.size);
            Blue= gcnew cli::array<unsigned short>(ramp.size);
            for (unsigned int i = 0; i < ramp.size; ++i)
            {
                Red[i] = ramp.red[i];
                Green[i] = ramp.green[i];
                Blue[i] = ramp.blue[i];
            }
        }
        GLFWgammaramp ToNative()
        {
            GLFWgammaramp ramp{};
            if (Size != Red->Length && Size != Green->Length && Size != Blue->Length)
            {
                throw gcnew System::ArgumentException("Red, Green and Blue must all be equal length");
            }
            for (unsigned int i = 0; i < Size; ++i)
            {
                ramp.red[i] = Red[i];
                ramp.green[i] = Green[i];
                ramp.blue[i] = Blue[i];
            }
            ramp.size = Size;
            return ramp;
        }
	};
}