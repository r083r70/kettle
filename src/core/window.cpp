#include "window.h"

#include "app.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace kettle
{
#define GET_WINDOW_USER(window) static_cast<Window*>(glfwGetWindowUserPointer(window))

#define GLFW_CALLBACK(method) [](GLFWwindow* window) { GET_WINDOW_USER(window)->method(); }
#define GLFW_CALLBACK_ONE_ARG(method) [](GLFWwindow* window, auto arg) { GET_WINDOW_USER(window)->method(arg); }
#define GLFW_CALLBACK_TWO_ARGS(method) [](GLFWwindow* window, auto arg1, auto arg2) { GET_WINDOW_USER(window)->method(arg1, arg2); }

	bool Window::init(const char* title, int32_t width, int32_t height)
	{
		glfwInit();

		m_NativeWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
		if (m_NativeWindow == nullptr)
		return false;

		// Setup user
		glfwSetWindowUserPointer(m_NativeWindow, this);
		glfwMakeContextCurrent(m_NativeWindow);

		// Setup callback
		glfwSetWindowCloseCallback(m_NativeWindow, GLFW_CALLBACK(onClose));

		const int32_t status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		return status;
	}

	void Window::deinit()
	{
		// Remove callbacks
		glfwSetWindowCloseCallback(m_NativeWindow, nullptr);

		glfwDestroyWindow(m_NativeWindow);
		m_NativeWindow = nullptr;

		glfwTerminate();
	}

	void Window::tick()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_NativeWindow);
	}

	void Window::getSize(int32_t& width, int32_t& height) const
	{
		glfwGetWindowSize(m_NativeWindow, &width, &height);
	}

	void Window::onClose()
	{
		App::get()->terminate();
	}
}