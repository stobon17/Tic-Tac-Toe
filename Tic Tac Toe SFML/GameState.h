#pragma once

#include <SFML/Graphics.hpp>
#include "States.h"
#include "game.h"

#include "Artificial_Intelligence.h"

namespace stobon
{
	class GameState : public State
	{
	public:
		GameState(gameDataReference data);

		void Initialize();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		gameDataReference data;
		sf::Sprite background, pauseButton, gridSprite;

		void InitializeGrid();
		void CheckandPlace();
		void CheckWinCondition(int turn);
		void Check3InARow(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int checkedPiece);

		int turn;
		int gameState;
		//3x3 board
		sf::Sprite gridPieces[3][3];
		//enumeration numbers
		int gridArray[3][3];

		AI* ai;

		sf::Clock sfClock;
	};


}