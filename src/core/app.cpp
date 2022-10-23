#include "app.h"

#include <cassert>
#include <cstdint>

namespace kettle
{
	App* App::s_Instance = nullptr;

    App::App(const std::string& title, int32_t width, int32_t height)
		: m_Title(title)
		, m_Width(width)
		, m_Height(height)
	{}

	void App::run()
	{
		const bool bInited = init();
		assert(bInited);
		
		while (!b_Terminate)
			loop();

		deinit();
	}

	void App::popLayer()
	{
		Layer* layer = m_Layers.back();
		m_Layers.pop_back();
		layer->stop();
		delete layer;
	}

	void App::terminate()
	{
		b_Terminate = true;
	}

	bool App::init()
	{
		if (s_Instance != nullptr)
			return false;

		if (!m_Window.init(m_Title.c_str(), m_Width, m_Height))
			return false;
		
		if (!m_ImGuiClient.init(m_Window))
		 	return false;

		s_Instance = this;

		// App inited > Start layers
		for (auto it = m_Layers.begin(); it != m_Layers.end(); it++)
			(*it)->start();

		return true;
	}

	void App::loop()
	{		
		m_Window.tick();
		m_Window.getSize(m_Width, m_Height);
		m_ImGuiClient.preTick(m_Width, m_Height);

		for (auto it = m_Layers.end(); it != m_Layers.begin();)
			(*--it)->tick();

		m_ImGuiClient.postTick();
	}

	void App::deinit()
	{
		// Pop all Layers
		for (int32_t i = m_Layers.size() - 1; i >= 0; i--)
			popLayer();

		m_ImGuiClient.deinit();
		m_Window.deinit();

		s_Instance = nullptr;
	}
}
