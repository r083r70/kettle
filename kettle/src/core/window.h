#pragma once

#include <cstdint>

struct GLFWwindow;

namespace kettle
{
	class Window
	{
	public:
		bool init(const char* title, int32_t width, int32_t height);
		void deinit();

		void tick();

		inline GLFWwindow* getNativeWindow() const { return m_NativeWindow; }
		void getSize(int32_t& width, int32_t& height) const;

		void showWindow();

	private:
		void onClose();

	private:
		GLFWwindow* m_NativeWindow;
	};
}