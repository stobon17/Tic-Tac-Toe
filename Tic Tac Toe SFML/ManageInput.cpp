#include "ManageInput.h"

namespace stobon
{
	bool ManageInput::isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect playButton(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

			if (playButton.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		return false;
	}
	sf::Vector2i ManageInput::GetMousePosition(sf::RenderWindow& gameWindow)
	{
		return sf::Mouse::getPosition(gameWindow);
	}
}