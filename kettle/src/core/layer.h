#pragma once

namespace kettle
{
	class Layer
	{
	public:
		virtual ~Layer() = default;

		virtual void start() {}
		virtual void tick() = 0;
		virtual void stop() {}

		virtual bool onWindowHidden() { return false; }
	};	
}
