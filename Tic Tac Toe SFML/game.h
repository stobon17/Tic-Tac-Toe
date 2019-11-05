#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include "machine.h"
#include "Assets.h"
#include "ManageInput.h"

namespace stobon 
{
	struct gameData
	{
		StateMachine stateMachine;
		sf::RenderWindow gameWindow;
		AssetManagement assets;
		ManageInput input;
	};
	typedef std::shared_ptr<gameData> gameDataReference;

	class Game
	{
	public:
		Game(int width, int height, std::string appTitle);
	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock clock;
		gameDataReference data = std::make_shared<gameData>();

		void runGame();
	};
}