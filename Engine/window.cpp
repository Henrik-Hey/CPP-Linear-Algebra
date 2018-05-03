#include "window.h"

namespace graphics {
	namespace window {

		bool Window::m_Keys[MAX_KEYS];
		bool Window::m_MouseButtons[MAX_MOUSE_BUTTONS];
		double Window::m_MouseX;
		double Window::m_MouseY;

		Window::Window(const char *title, int width, int height) 
		{
			this->m_Title = title;
			this->m_Width = width;
			this->m_Height = height;
			if (!init())
			{
				glfwTerminate();
				return;
			}

			for (int i = 0; i < MAX_KEYS; i++)
			{
				this->m_Keys[i] = false;
			}

			for (int i = 0; i < MAX_MOUSE_BUTTONS; i++)
			{
				this->m_MouseButtons[i] = false;
			}

		}

		// Attempts to initailize the window.
		bool Window::init() 
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			if (!glfwInit()) 
			{
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "COULD NOT INITIALIZE GLFW!" << std::endl;
				return false;
			}	

			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "GLFW WAS SUCCESSFULLY INITIALIZED!" << std::endl;

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (!m_Window) 
			{
				glfwTerminate();
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "FAILED TO CREATE GLFW WINDOW!" << std::endl;
				return false;
			}
		
			std::cout << "GLFW WINDOW WAS SUCCESSFULLY CREATED!" << std::endl;

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);

			if (glewInit() != GLEW_OK) 
			{
				glfwTerminate();
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "FAILED TO INITIALIZE GLEW!" << std::endl;
				return false;
			}

			std::cout << "GLEW WAS SUCCESSFULLY INITIALIZED!" << std::endl;
			std::cout << "OPENGL version#: " << glGetString(GL_VERSION) << std::endl;

			// Clears the colour of the current window canvas to black.
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		// Updates the window.
		void Window::update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glViewport(0, 0, m_Width, m_Height);
			glfwSwapBuffers(m_Window);
		}

		void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) 
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseX = xpos;
			win->m_MouseY = ypos;
		}

		bool Window::isKeyDown(unsigned int keycode) {
			if (keycode >= MAX_KEYS)
			{
				return false;
			}
			return m_Keys[keycode];
		}

		bool Window::isMouseButtonDown(unsigned int mouseButton)
		{
			if (mouseButton >= MAX_MOUSE_BUTTONS) {
				return false;
			}
			return m_MouseButtons[mouseButton];
		}

		void Window::getMousePosition(double& mouseX, double& mouseY) 
		{
			mouseX = m_MouseX;
			mouseY = m_MouseY;
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}

		// Deconstructs the window.
		Window::~Window()
		{
			glfwTerminate();
		}
	}
}