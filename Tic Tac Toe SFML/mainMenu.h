#pragma once

#include <SFML/Graphics.hpp>
#include "States.h"
#include "game.h"

namespace stobon
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(gameDataReference data);

		void Initialize();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		gameDataReference data;
		sf::Sprite background, playButton, playButtonOuter, title;



	};
}