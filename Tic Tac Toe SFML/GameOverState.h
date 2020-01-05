#pragma once

#include <SFML/Graphics.hpp>
#include "States.h"
#include "game.h"

namespace stobon
{
	class GameOverState : public State
	{
	public:
		GameOverState(gameDataReference data);

		void Initialize();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		gameDataReference data;
		sf::Sprite startOverButton, homeButton;


	};
}
