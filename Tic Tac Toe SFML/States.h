#pragma once

namespace stobon
{
	class State
	{
	public: 
		virtual void Initialize() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(float t) = 0;
		virtual void Pause() {}
		virtual void Resume() {}

	};
}