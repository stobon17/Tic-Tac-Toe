#pragma once

#include <SFML/Graphics.hpp>

namespace stobon
{
	class ManageInput
	{
	public:
		//Constructor and Destructor
		ManageInput() {}
		~ManageInput() {}

		bool isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow & window);
		sf::Vector2i GetMousePosition(sf::RenderWindow& gameWindow);
	};
}