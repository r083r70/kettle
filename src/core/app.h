
#pragma once

#include "window.h"
#include "imguiclient.h"

namespace kettle
{
    class App
    {
    public:
        App() = default;
        bool init();
        void run();

	private:
		Window m_Window;
		ImGuiClient m_ImGuiClient;
    };
}
