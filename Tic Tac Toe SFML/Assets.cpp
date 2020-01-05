#include "Assets.h"


namespace stobon
{
	//Store any textures we load to use later
	void AssetManagement::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture texture;
		if (texture.loadFromFile(fileName))
		{
			this->allTextures[name] = texture;
		}
	}
	//Find stored texture within the map and return it
	sf::Texture& AssetManagement::GetTexture(std::string name)
	{
		return this->allTextures.at(name);
	}

	//Store any fonts we load for later use
	void AssetManagement::LoadFonts(std::string name, std::string fileName)
	{
		sf::Font font;
		if (font.loadFromFile(fileName))
		{
			this->allFonts[name] = font;
		}
	}
	//find stored font and return
	sf::Font& AssetManagement::GetFont(std::string name)
	{
		return this->allFonts.at(name);
	}
}