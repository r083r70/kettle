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

	private:
		void onClose();
		void onResize(int32_t width, int32_t height);

	private:
		GLFWwindow* m_NativeWindow;
	};
}