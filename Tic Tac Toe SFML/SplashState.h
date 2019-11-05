#pragma once

#include <SFML/Graphics.hpp>
#include "States.h"
#include "game.h"

namespace stobon
{
	class SplashState : public State
	{
	public:
		SplashState(gameDataReference data);

		void Initialize();
		
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		gameDataReference data;
		sf::Clock clock;
		sf::Sprite background;

	};
}