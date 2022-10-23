#pragma once

#include <cstdint>

namespace kettle
{
	class Window;

	class ImGuiClient
	{
	public:
		bool init(const Window& window);
		void deinit();

		void preTick(int32_t width, int32_t height);
		void postTick();
	};
};