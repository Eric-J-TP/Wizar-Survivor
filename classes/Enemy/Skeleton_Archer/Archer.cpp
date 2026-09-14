class Archer
{
protected:
	sf::Texture texture;
	sf::Sprite sprite{ texture };
	std::string file_path = "classes/Enemy/Skeleton_Archer/textures/sprite.png";
	sf::Vector2i spriteSize{ 128,128 };
	sf::Vector2f position{ 100.f, 456.f };
	sf::Vector2f origin{ 55,64.f }; ;
	sf::Clock clock;
	float elapsedMiliSeconds = 0;
	int frameNumber = 0;
	int xIndex = 0;
	int yIndex = 0;
	int milisec = 125;
	float facing = 1;
	bool startAttack1 = false;
	bool startAttack2 = false;

public:
	Archer()
	{
		if (texture.loadFromFile(file_path));
			sprite.setTexture(texture);

		sprite.setTextureRect(sf::IntRect({ 0,0 }, { spriteSize.x, spriteSize.y }));
		sprite.setPosition(position);
		sprite.setOrigin(origin);
		sprite.scale({ facing,1 });
	};
	void animate()
	{
		idle();
	}

	void idle()
	{
		yIndex = 8 * spriteSize.y;
		frameNumber = 6;

		float deltaTime = clock.restart().asMilliseconds();
		elapsedMiliSeconds += deltaTime;

		if (elapsedMiliSeconds >= milisec)
		{
			elapsedMiliSeconds = 0;
			sprite.setTextureRect(sf::IntRect({ xIndex, yIndex }, { spriteSize.x, spriteSize.y }));
			xIndex += spriteSize.x;
			if (xIndex >= spriteSize.x * frameNumber)
				xIndex = 0;
		}
	}


	//----------
	sf::Sprite getSprite() { return sprite; }
};