#include <sstream>
#include "definitions.h"
#include <iostream>
#include  "GameOverState.h"
#include "GameState.h"
#include "mainMenu.h"

namespace stobon
{
	GameOverState::GameOverState(gameDataReference data) : data(data)
	{

	}
	void GameOverState::Initialize()
	{
		//Load in assets
		this->data->assets.LoadTexture("Start Over Button", START_OVER_BUTTON);
		this->data->assets.LoadTexture("Home Button", HOME_BUTTON);

		//Set Textures
		this->startOverButton.setTexture(this->data->assets.GetTexture("Start Over Button"));
		this->homeButton.setTexture(this->data->assets.GetTexture("Home Button"));

		//Resume and Home positions

		//Divide by 3 bc for n buttons divide by n+1
		this->startOverButton.setPosition((this->data->gameWindow.getSize().x / 2) - (startOverButton.getLocalBounds().width / 2), (this->data->gameWindow.getSize().y / 3) - (startOverButton.getLocalBounds().height / 2));
		this->homeButton.setPosition((this->data->gameWindow.getSize().x / 2) - (homeButton.getLocalBounds().width / 2), (this->data->gameWindow.getSize().y / 3 * 2) - (homeButton.getLocalBounds().height / 2));
	}
	void GameOverState::HandleInput()
	{
		sf::Event event;
		while (this->data->gameWindow.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->data->gameWindow.close();
			}

			//Start over button is hit
			if (this->data->input.isSpriteClicked(this->startOverButton, sf::Mouse::Left, this->data->gameWindow))
			{
				//Resume the game
				this->data->stateMachine.AddStates(StateReference(new GameState(data)), true);
			}
			//Home button clicked
			if (this->data->input.isSpriteClicked(this->homeButton, sf::Mouse::Left, this->data->gameWindow))
			{
				//Go to home state
				this->data->stateMachine.RemoveStates(); //Removes pause state

				//Replace with main menu state
				this->data->stateMachine.AddStates(StateReference(new MainMenuState(data)), true);
			}
		}
	}
	void GameOverState::Update(float dt)
	{

	}
	void GameOverState::Draw(float dt)
	{
		//Can set background color in clear(sf::Color::Red)
		this->data->gameWindow.clear();
		this->data->gameWindow.draw(this->startOverButton);
		this->data->gameWindow.draw(this->homeButton);


		//Display window
		this->data->gameWindow.display();
	}
}