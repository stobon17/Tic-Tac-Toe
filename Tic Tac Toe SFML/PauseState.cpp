#include <sstream>
#include "definitions.h"
#include <iostream>
#include  "PauseState.h"
#include "GameState.h"
#include "mainMenu.h"

namespace stobon
{
	PauseState::PauseState(gameDataReference data) : data(data)
	{

	}
	void PauseState::Initialize() 
	{	
		//Load in assets
		this->data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->data->assets.LoadTexture("Resume Button", RESUME_BUTTON);
		this->data->assets.LoadTexture("Home Button", HOME_BUTTON);

		//Set Textures
		this->background.setTexture(this->data->assets.GetTexture("Pause Background"));
		this->resumeButton.setTexture(this->data->assets.GetTexture("Resume Button"));
		this->homeButton.setTexture(this->data->assets.GetTexture("Home Button"));

		//Resume and Home positions

		//Divide by 3 bc for n buttons divide by n+1
		this->resumeButton.setPosition((this->data->gameWindow.getSize().x / 2) - (resumeButton.getLocalBounds().width / 2), (this->data->gameWindow.getSize().y / 3) - (resumeButton.getLocalBounds().height / 2));
		this->homeButton.setPosition((this->data->gameWindow.getSize().x / 2) - (homeButton.getLocalBounds().width / 2), (this->data->gameWindow.getSize().y / 3 * 2) - (homeButton.getLocalBounds().height / 2));
	}
	void PauseState::HandleInput()
	{
		sf::Event event;
		while (this->data->gameWindow.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->data->gameWindow.close();
			}

			//Resume button is hit
			if (this->data->input.isSpriteClicked(this->resumeButton, sf::Mouse::Left, this->data->gameWindow))
			{
				//Resume the game
				this->data->stateMachine.RemoveStates();
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
	void PauseState::Update(float dt)
	{

	}
	void PauseState::Draw(float dt)
	{
		this->data->gameWindow.clear();
		this->data->gameWindow.draw(this->background);
		this->data->gameWindow.draw(this->resumeButton);
		this->data->gameWindow.draw(this->homeButton);
	

		//Display window
		this->data->gameWindow.display();
	}
}