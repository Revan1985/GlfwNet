using System;
using System.Drawing;

namespace GlfwNet.Test
{
	class Program
	{
		private const int GL_COLOR_BUFFER_BIT = 0x00004000;

		delegate void glClearColorHandler(float r, float g, float b, float a);
		delegate void glClearHandler(int mask);


		static glClearColorHandler glClearColor;
		static glClearHandler glClear;

		static readonly Random rnd = new Random();

		static void Main(string[] _)
		{
			//Console.WriteLine("Hello World!");

			//Glfw.Init();
			Glfw.WindowHint(Hint.ClientApi, ClientApi.OpenGl);
			Glfw.WindowHint(Hint.ContextVersionMajor, 3);
			Glfw.WindowHint(Hint.ContextVersionMinor, 3);
			Glfw.WindowHint(Hint.OpenGlProfile, Profile.Core);
			Glfw.WindowHint(Hint.Doublebuffer, true);
			Glfw.WindowHint(Hint.Decorated, true);
			Glfw.WindowHint(Hint.OpenGlForwardCompat, false);


			using (Window window = Glfw.CreateWindow(1280, 720, "Test", null, null))
			{
				Glfw.MakeContextCurrent(window);

				Glfw.SwapInterval(1);

				Monitor[] monitors = Monitor.Monitors;
				foreach (Monitor monitor in monitors)
				{
					Console.Out.WriteLine($"Monitor {monitor.Name}:");
					Console.Out.WriteLine($"Current VideoMode: {monitor.CurrentMode.Width}x{monitor.CurrentMode.Height}");
					foreach (VideoMode mode in monitor.VideoModes)
					{
						Console.Out.WriteLine($"\t{mode.Width}x{mode.Height}");
					}
				}

				Size size = window.Size;
				Rectangle workArea = Monitor.PrimaryMonitor.WorkArea;
				int x = (workArea.Width - size.Width) / 2;
				int y = (workArea.Height - size.Height) / 2;
				window.Position = new Point(x, y);

				glClearColor = Glfw.GetProcAddress<glClearColorHandler>("glClearColor");
				glClear = Glfw.GetProcAddress<glClearHandler>("glClear");

				Glfw.OnKey += keyCallback;

				long tick = 0L;
				ChangeClearColor();
				while (!Glfw.WindowShouldClose(window))
				{
					glClear(GL_COLOR_BUFFER_BIT);

					Glfw.SwapBuffers(window);
					Glfw.PollEvents();
					if (++tick % 60 == 0) { ChangeClearColor(); }
				}
			}
			//Glfw.DestroyWindow(window);
			Glfw.Terminate();
		}

		static void ChangeClearColor()
		{
			float r = (float)rnd.NextDouble();
			float g = (float)rnd.NextDouble();
			float b = (float)rnd.NextDouble();
			glClearColor(r, g, b, 1.0f);
		}

		static void keyCallback(Window window, Key key, int scanCode, InputState inputState, KeyModifiers modifiers)
		{
			switch (key)
			{
				case Key.Escape:
					Glfw.SetWindowShouldClose(window, true);
					break;
			}
		}
	}
}
