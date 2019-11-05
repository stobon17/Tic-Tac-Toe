#include "mainMenu.h"
#include <sstream>
#include "definitions.h"
#include <iostream>

namespace stobon
{
	MainMenuState::MainMenuState(gameDataReference data) : data(data)
	{

	}
	void MainMenuState::Initialize() {

		//Bring in Textures
		this->data->assets.LoadTexture("Background", MAINMENU_BACKGROUND_FILEPATH);
		this->data->assets.LoadTexture("Play Button", MAINMENU_MENU_PLAY_BUTTON);
		this->data->assets.LoadTexture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER);
		this->data->assets.LoadTexture("Game Title", MAINMENU_TITLE_PATH);

		//Set Sprites
		this->background.setTexture(this->data->assets.GetTexture("Background"));
		this->playButton.setTexture(this->data->assets.GetTexture("Play Button"));
		this->playButtonOuter.setTexture(this->data->assets.GetTexture("Play Button Outer"));
		this->title.setTexture(this->data->assets.GetTexture("Game Title"));

		//Positioning
		this->playButton.setPosition((SCREEN_WIDTH / 2) - (this->playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->playButton.getGlobalBounds().height / 2));
		this->playButtonOuter.setPosition((SCREEN_WIDTH / 2) - this->playButtonOuter.getGlobalBounds().width / 2, (SCREEN_HEIGHT / 2) - this->playButtonOuter.getGlobalBounds().height / 2);
		this->title.setPosition((SCREEN_WIDTH / 2) - this->title.getGlobalBounds().width / 2, this->title.getGlobalBounds().height * 0.1);

	}
	void MainMenuState::HandleInput()
	{
		sf::Event event;
		while (this->data->gameWindow.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->data->gameWindow.close();
			}

			//Play button is hit
			if (this->data->input.isSpriteClicked(this->playButton, sf::Mouse::Left, this->data->gameWindow))
			{
				std::cout << "Go to Game screen" << std::endl;
			}
		}
	}
	void MainMenuState::Update(float dt)
	{

	}
	void MainMenuState::Draw(float dt)
	{
		this->data->gameWindow.clear();
		this->data->gameWindow.draw(this->background);
		this->data->gameWindow.draw(this->playButton);
		this->data->gameWindow.draw(this->playButtonOuter);
		this->data->gameWindow.draw(this->title);

		//Display window
		this->data->gameWindow.display();
	}
}