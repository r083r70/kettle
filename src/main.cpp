#include "core/app.h"

int main()
{
	kettle::App app{};
	if (app.init())
		app.run();
}
