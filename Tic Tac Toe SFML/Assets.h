#pragma once

#include <map>

#include <SFML/Graphics.hpp>

namespace stobon
{
	class AssetManagement
	{
	public:
		//Constructor Destructor
		AssetManagement() {}
		~AssetManagement() {}

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);

		void LoadFonts(std::string name, std::string fileName);
		sf::Font& GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> allTextures;
		std::map<std::string, sf::Font> allFonts;

	};
}