#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include "game.h"

namespace stobon
{
	class AI
	{
	public:
		AI(int playerPiece, gameDataReference data);

		void PlacePiece(int(*gridArray)[3][3], sf::Sprite gridPieces[3][3], int* gameState);
	private:
		void CheckSection(int x_1, int y_1, int x_2, int y_2, int X, int Y, int checkedPiece, int(*gridArray)[3][3], sf::Sprite gridPieces[3][3]);

		void CheckEmptyPiece(int X, int Y, int(*gridArray)[3][3], sf::Sprite gridPieces[3][3]);
		
		int aiPiece, playerPiece;
		std::vector<std::array<int, 6>> checkMatchVector;
		
		gameDataReference data;
	};
}
