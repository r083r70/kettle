#include "app.h"

#include "imgui.h"
#include <cassert>

namespace kettle
{
	bool App::init()
	{
		if (!m_Window.init("Title", 512, 512))
			return false;
		
		if (!m_ImGuiClient.init(m_Window))
		 	return false;
		
		return true;
	}

	void App::run()
	{
		while(true)
		{
			m_Window.tick();
	
			m_ImGuiClient.preTick(512, 512);
			m_ImGuiClient.tick();

			bool bBoolean = true;
			ImGui::ShowDemoWindow(&bBoolean);

			m_ImGuiClient.postTick();
		}
	}
}
