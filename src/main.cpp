#include "core/app.h"
#include "core/layer.h"

#include "imgui.h"

class DemoLayer : public kettle::Layer
{
	virtual void tick() override
	{
		ImGui::ShowDemoWindow(&b_Show);
	}

private:
	bool b_Show = true;
};

int main()
{
	kettle::App app{"Title", 512, 512};
	app.pushLayer<DemoLayer>();
	app.run();
}
