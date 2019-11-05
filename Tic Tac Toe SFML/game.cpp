#include "game.h"
#include "SplashState.h"

namespace stobon
{
	Game::Game(int width, int height, std::string appTitle)
	{
		data->gameWindow.create(sf::VideoMode(width, height), appTitle, sf::Style::Close | sf::Style::Titlebar);
		data->stateMachine.AddStates(StateReference(new SplashState(this->data)));

		this->runGame();
	}

	void Game::runGame()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->data->gameWindow.isOpen())
		{
			this->data->stateMachine.UpdateChanges();

			newTime = this->clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->data->stateMachine.GetCurrentState()->HandleInput();
				this->data->stateMachine.GetCurrentState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->data->stateMachine.GetCurrentState()->Draw(interpolation);
		}
	}
}