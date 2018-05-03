#pragma once

#include <iostream>
#include <Windows.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace graphics {
	namespace window {

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32

		class Window 
		{
		//private members
		private:

			const char *m_Title;
			int m_Width;
			int m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;

			static bool m_Keys[MAX_KEYS];
			static bool m_MouseButtons[MAX_MOUSE_BUTTONS];
			static double m_MouseX, m_MouseY;

		//public functions.
		public:

			Window(const char *title, int width, int height);
			void update();
			void clear() const;
			bool closed() const;

			inline int getWidth() const { return m_Width; };
			inline int getHeight() const { return m_Height; };

			static bool isKeyDown(unsigned int keycode);
			static bool isMouseButtonDown(unsigned int mouseButton);
			static void getMousePosition(double& mouseX, double& mouseY);

			~Window();

		//private functions.
		private:

			bool init();
			friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

		};

	}
}