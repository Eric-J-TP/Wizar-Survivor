class Map
{
private:
	sf::Texture texture;
	sf::Sprite sprite{ texture };
	std::string file_path = "classes/Map/textures/map4.jpg";
	sf::Vector2i spriteSize{ 1200,600};
	
public:
	Map()
	{
		if (texture.loadFromFile(file_path))
			sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect({ 0,0 }, { spriteSize.x, spriteSize.y }));
	}
	

	sf::Sprite getSprite() { return sprite; }
};
