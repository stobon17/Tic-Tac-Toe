#include "SplashState.h"
#include <sstream>
#include <iostream>
#include "definitions.h"
namespace stobon
{
	SplashState::SplashState(gameDataReference p_data) : data(p_data)
	{

	}

	void SplashState::Initialize() 
	{
		this->data->assets.LoadTexture("Splash State Background", SPLASH_STATE_BACKGROUND_FILEPATH);

		background.setTexture(this->data->assets.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput()
	{
		sf::Event event;
		while (this->data->gameWindow.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				this->data->gameWindow.close();
		}
	}

	void SplashState::Update(float dt)
	{
		if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			//Switch to menu
			std::cout << "Go to menu" << std::endl;
		}
	}

	void SplashState::Draw(float dt)
	{
		this->data->gameWindow.clear(sf::Color::Blue);
		this->data->gameWindow.draw(this->background);
		this->data->gameWindow.display();
	}
}