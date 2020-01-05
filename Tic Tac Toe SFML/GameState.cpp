#include "GameState.h"
#include <sstream>
#include "definitions.h"
#include <iostream>
#include "PauseState.h"
#include "GameOverState.h"

namespace stobon
{
	GameState::GameState(gameDataReference data) : data(data)
	{

	}
	void GameState::Initialize()
	{
		//Initialize game player goes first
		gameState = STATE_PLAYING;
		turn = PLAYER_PIECE;

		//Initialize AI
		this->ai = new AI(turn, this->data);

		//Load Textures
		this->data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
		this->data->assets.LoadTexture("Grid Sprite", GRID_FILEPATH);
		this->data->assets.LoadTexture("X Piece", X_FILEPATH);
		this->data->assets.LoadTexture("O Piece", CIRCLE_FILEPATH);

		this->data->assets.LoadTexture("X Winning", X_WINNING);
		this->data->assets.LoadTexture("O Winning", CIRCLE_WINNING);

		//Make sure to load new texture (above) if changing the gamestate background

		//Set The textures
		background.setTexture(this->data->assets.GetTexture("Background"));
		pauseButton.setTexture(this->data->assets.GetTexture("Pause Button"));
		gridSprite.setTexture(this->data->assets.GetTexture("Grid Sprite"));


		//Position
		pauseButton.setPosition(this->data->gameWindow.getSize().x - (pauseButton.getLocalBounds().width), pauseButton.getPosition().y);
		gridSprite.setPosition((SCREEN_WIDTH / 2) - (gridSprite.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (gridSprite.getGlobalBounds().height / 2));

		InitializeGrid();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				gridArray[i][j] = EMPTY_PIECE;
			}
		}
	}
	void GameState::HandleInput()
	{
		sf::Event event;
		while (this->data->gameWindow.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->data->gameWindow.close();
			}

			//Pause button is hit
			if (this->data->input.isSpriteClicked(this->pauseButton, sf::Mouse::Left, this->data->gameWindow))
			{
				//Pause the game
				this->data->stateMachine.AddStates(StateReference(new PauseState(data)), false);
			}
			//Place pieces on grid
			else if (this->data->input.isSpriteClicked(this->gridSprite, sf::Mouse::Left, this->data->gameWindow))
			{
				if (STATE_PLAYING == gameState)
				{
					this->CheckandPlace();
				}
			}
		}
	}
	void GameState::Update(float dt)
	{
		if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
		{
			if (this->sfClock.getElapsedTime().asSeconds() > TIME_BEFORE_SHOWING_GAME_OVER_STATE)
			{
				this->data->stateMachine.AddStates(StateReference(new GameOverState(data)), true);
			}
		}
	}
	void GameState::Draw(float dt)
	{
		this->data->gameWindow.draw(this->background);
		this->data->gameWindow.draw(this->pauseButton);
		this->data->gameWindow.draw(this->gridSprite);

		//Draw grid pieces
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				this->data->gameWindow.draw(this->gridPieces[i][j]);
			}
		}
		//Display window
		this->data->gameWindow.display();
	}
	void GameState::InitializeGrid()
	{
		sf::Vector2u tempSpriteSize = this->data->assets.GetTexture("X Piece").getSize();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				gridPieces[i][j].setTexture(this->data->assets.GetTexture("X Piece"));
				gridPieces[i][j].setPosition(gridSprite.getPosition().x + (tempSpriteSize.x * i) - 7, gridSprite.getPosition().y + (tempSpriteSize.y * j) - 7);
				gridPieces[i][j].setColor(sf::Color(255, 255, 255, 0));
			}
		}
	}
	void GameState::CheckandPlace()
	{
		sf::Vector2i clickedLocation = this->data->input.GetMousePosition(this->data->gameWindow);
		sf::FloatRect gridSize = gridSprite.getGlobalBounds();
		sf::Vector2f spaceOutofGrid = sf::Vector2f((SCREEN_WIDTH - gridSize.width) / 2, (SCREEN_HEIGHT - gridSize.height) / 2);
		
		sf::Vector2f gridLocalPosition = sf::Vector2f(clickedLocation.x - spaceOutofGrid.x, clickedLocation.y - spaceOutofGrid.y);

		sf::Vector2f gridSectionSize = sf::Vector2f(gridSize.width / 3, gridSize.height / 3);
		int column, row;

		if (gridLocalPosition.x < gridSectionSize.x)
		{
			column = 1;
		}
		else if (gridLocalPosition.x < gridSectionSize.x * 2) 
		{
			column = 2;
		}
		else if (gridLocalPosition.x < gridSize.width)
		{
			column = 3;
		}

		if (gridLocalPosition.y < gridSectionSize.y)
		{
			row = 1;
		}
		else if (gridLocalPosition.y < gridSectionSize.y * 2)
		{
			row = 2;
		}
		else if (gridLocalPosition.y < gridSize.height)
		{
			row = 3;
		}

		if (gridArray[column - 1][row - 1] == EMPTY_PIECE)
		{
			gridArray[column - 1][row - 1] = turn;

			if (PLAYER_PIECE == turn)
			{
				gridPieces[column - 1][row - 1].setTexture(this->data->assets.GetTexture("O Piece"));
				//Check if won
				this->CheckWinCondition(turn);
				//turn = AI_PIECE;
			}
		
			gridPieces[column - 1][row - 1].setColor(sf::Color(255, 255, 255, 255));

		}
	}
	void GameState::CheckWinCondition(int turn)
	{
		Check3InARow(0, 0, 1, 0, 2, 0, turn);
		Check3InARow(0, 1, 1, 1, 2, 1, turn);
		Check3InARow(0, 2, 1, 2, 2, 2, turn);
		Check3InARow(0, 0, 0, 1, 0, 2, turn);
		Check3InARow(1, 0, 1, 1, 1, 2, turn);
		Check3InARow(2, 0, 2, 1, 2, 2, turn);
		Check3InARow(0, 0, 1, 1, 2, 2, turn);
		Check3InARow(0, 2, 1, 1, 2, 0, turn);

		if (STATE_WON != gameState)
		{
			gameState = STATE_AI_PLAYING;
			ai->PlacePiece(&gridArray, gridPieces, &gameState);
			Check3InARow(0, 0, 1, 0, 2, 0, AI_PIECE);
			Check3InARow(0, 1, 1, 1, 2, 1, AI_PIECE);
			Check3InARow(0, 2, 1, 2, 2, 2, AI_PIECE);
			Check3InARow(0, 0, 0, 1, 0, 2, AI_PIECE);
			Check3InARow(1, 0, 1, 1, 1, 2, AI_PIECE);
			Check3InARow(2, 0, 2, 1, 2, 2, AI_PIECE);
			Check3InARow(0, 0, 1, 1, 2, 2, AI_PIECE);
			Check3InARow(0, 2, 1, 1, 2, 0, AI_PIECE);
		}

		int emptySpaces = 9;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) 
			{
				if (EMPTY_PIECE != gridArray[i][j])
				{
					emptySpaces--;
				}
			}
		}
		if (0 == emptySpaces && (STATE_WON != gameState) && (STATE_LOSE != gameState))
		{
			gameState = STATE_DRAW;
		}
		if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
		{
			this->sfClock.restart();
		}

		std::cout << gameState << std::endl;
	}
	void GameState::Check3InARow(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int checkedPiece) 
	{
		if (checkedPiece == gridArray[x_1][y_1] && checkedPiece == gridArray[x_2][y_2] && checkedPiece == gridArray[x_3][y_3])
		{
			std::string winningPieceStr;
			if (O_PIECE == checkedPiece)
			{
				winningPieceStr = "O Winning";
			}
			else {
				winningPieceStr = "X Winning";
			}
			gridPieces[x_1][y_1].setTexture(this->data->assets.GetTexture(winningPieceStr));
			gridPieces[x_2][y_2].setTexture(this->data->assets.GetTexture(winningPieceStr));
			gridPieces[x_3][y_3].setTexture(this->data->assets.GetTexture(winningPieceStr));
		
			if (PLAYER_PIECE == checkedPiece) 
			{
				gameState = STATE_WON;
			}
			else
			{
				gameState = STATE_LOSE;
			}
		}
	}
}