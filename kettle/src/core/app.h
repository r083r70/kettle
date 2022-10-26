#pragma once

#include "imguiclient.h"
#include "layer.h"
#include "window.h"

#include <string>
#include <vector>

namespace kettle
{
	using LayerStack = std::vector<Layer*>;

    class App
    {
    public:
		static App* get() { return s_Instance; }

        App(const std::string& title, int32_t width, int32_t height);
        void run();

		template<class LayerClass, class... Args>
		void pushLayer(Args... args);
		void popLayer();

		void onWindowHidden();
		void showWindow();

		void terminate();

	private:
		bool init();
        void loop();
        void deinit();

	private:
		static App* s_Instance;

		Window m_Window;
		ImGuiClient m_ImGuiClient;
		LayerStack m_Layers;

		std::string m_Title;
		int32_t m_Width, m_Height;
		bool b_Terminate = false;
    };

	template<class LayerClass, class... Args>
	void App::pushLayer(Args... args)
	{
		Layer* layer = new LayerClass(std::forward<Args>(args)...);
		m_Layers.push_back(layer);

		// App is already inited > Start layer now
		if (s_Instance == this)
			layer->start();
	}
}
