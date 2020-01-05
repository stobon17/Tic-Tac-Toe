#pragma once

#include <SFML/Graphics.hpp>
#include "States.h"
#include "game.h"

namespace stobon
{
	class PauseState : public State
	{
	public:
		PauseState(gameDataReference data);

		void Initialize();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		gameDataReference data;
		sf::Sprite background, resumeButton, homeButton;

	};
}