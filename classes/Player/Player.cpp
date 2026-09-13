class Player
{
private:
	sf::Texture texture; //textures for a sprite
	sf::Sprite sprite{ texture }; //sprite
	std::string file_path = "classes/Player/textures/Idle.png"; // file path to load a texture
	sf::Vector2i spriteSize{ 128,128 }; // sprite lenght,width
	sf::Vector2f position{ 600.f, 456.f }; // starting positions of a sprite
	sf::Vector2f origin{ 55,64.f }; // the origin of a sprite (center point)
	sf::Clock clock; // clock for delta time
	float elapsedMiliSeconds = 0.0;
	int frameNumber = 0; // munber of frame - 1
	int xIndex = 0; // the xIndex for animation
	int yIndex = 0; // the yIndex to chose a animation
	int milisec = 125; // the frame duration (ms)
	float facing = 1; // 1- rigth -1 left
	bool StartAttack1 = false;
	bool StartAttack2 = false;
	bool StartAttack3 = false;
	bool StartJump = false;

public:
	Player()
	{
		if (texture.loadFromFile("classes/Player/textures/Sprite_Sheet2.png"));
			sprite.setTexture(texture);

		sprite.setTextureRect(sf::IntRect({ 0,0 }, { spriteSize.x, spriteSize.y }));
		sprite.setPosition(position);
		sprite.setOrigin(origin);
		sprite.scale({ facing,1 });
	}
	void animate() // put all animation and make them work together
	{

		if (StartAttack1 == true) attack1();
		if (StartAttack2 == true) attack2();
		if (StartAttack3 == true) attack3();
		if (StartJump == true) jump();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E) && StartAttack1 == false)
		{
			StartAttack1 = true; 
			xIndex = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) && StartAttack2 == false)
		{
			StartAttack2 = true;
			xIndex = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) && StartAttack3 == false)
		{
			StartAttack3 = true;
			xIndex = 0;
		}
		//------
		
		// Movment
		//jump
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && StartJump == false)
			{
				StartJump = true;
				xIndex = 0;
			}
		//run
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) // left
			{
				facing = 1;
				sprite.setScale({ 1.f, 1.f });
				run();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) // right
			{
				facing = -1;
				sprite.setScale({ -1.f, 1.f });
				run();
			}
		//walk
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // left
			{
				facing = 1;
				sprite.setScale({ 1.f, 1.f });
				walk();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) // right
			{
				facing = -1;
				sprite.setScale({ -1.f, 1.f });
				walk();
			}
		else
		{
			idle();
		}
		//-----------

	}

	void idle()
	{
		yIndex = 4 * spriteSize.y;
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
	void walk()
	{
		yIndex = 9 * spriteSize.y;
		frameNumber = 6;

		float deltaTime = clock.restart().asMilliseconds();
		elapsedMiliSeconds += deltaTime;

		if (elapsedMiliSeconds >= milisec)
		{
			elapsedMiliSeconds = 0;
			sprite.setTextureRect(sf::IntRect({ xIndex, yIndex }, { spriteSize.x, spriteSize.y }));
			xIndex += spriteSize.x;
			if (xIndex > spriteSize.x * frameNumber)
				xIndex = 0;
			sf::Vector2f movment = sprite.getPosition() + sf::Vector2f({ 5.f,0 }) * facing;
			sprite.setPosition(movment);
		}
	}
	void run()
	{
		yIndex = 8 * spriteSize.y;
		frameNumber = 7;

		float deltaTime = clock.restart().asMilliseconds();
		elapsedMiliSeconds += deltaTime;

		if (elapsedMiliSeconds >= milisec)
		{
			elapsedMiliSeconds = 0;
			sprite.setTextureRect(sf::IntRect({ xIndex, yIndex }, { spriteSize.x, spriteSize.y }));
			xIndex += spriteSize.x;
			if (xIndex > spriteSize.x * frameNumber)
				xIndex = 0;

			
			sf::Vector2f movment = sprite.getPosition() + sf::Vector2f({ 20.f,0 }) * facing;
			sprite.setPosition(movment);
		}
	}
	void jump()
	{
		yIndex = 5 * spriteSize.y;
		frameNumber = 7;

		float deltaTime = clock.restart().asMilliseconds();
		elapsedMiliSeconds += deltaTime;

		if (elapsedMiliSeconds >= milisec)
		{
			elapsedMiliSeconds = 0;
			sprite.setTextureRect(sf::IntRect({ xIndex, yIndex }, { spriteSize.x, spriteSize.y }));
			xIndex += spriteSize.x;
			if (xIndex > spriteSize.x * frameNumber)
				xIndex = 0;


			sf::Vector2f movment = sprite.getPosition() + sf::Vector2f({ 20.f,0 }) * facing;
			sprite.setPosition(movment);
			if (xIndex >= spriteSize.x * frameNumber)
			{
				xIndex = 0; StartJump= false;
			}
		}
	}

	void attack1()
	{
		yIndex = 0 * spriteSize.y;
		frameNumber = 9;

		float deltaTime = clock.restart().asMilliseconds();
		elapsedMiliSeconds += deltaTime;

		if (elapsedMiliSeconds >= milisec)
		{
			elapsedMiliSeconds = 0;
			sprite.setTextureRect(sf::IntRect({ xIndex, yIndex }, { spriteSize.x, spriteSize.y }));
			xIndex += spriteSize.x;
			if (xIndex > spriteSize.x * frameNumber)
			{
				xIndex = 0; StartAttack1 = false;
			}
		}
	}
	void attack2()
	{
		yIndex = 1 * spriteSize.y;
		frameNumber = 3;

		float deltaTime = clock.restart().asMilliseconds();
		elapsedMiliSeconds += deltaTime;

		if (elapsedMiliSeconds >= milisec)
		{
			elapsedMiliSeconds = 0;
			sprite.setTextureRect(sf::IntRect({ xIndex, yIndex }, { spriteSize.x, spriteSize.y }));
			xIndex += spriteSize.x;
			if (xIndex > spriteSize.x * frameNumber)
			{
				xIndex = 0; StartAttack2 = false;
			}
		}
	}
	void attack3()
	{
		yIndex = 6 * spriteSize.y;
		frameNumber = 6;

		float deltaTime = clock.restart().asMilliseconds();
		elapsedMiliSeconds += deltaTime;

		if (elapsedMiliSeconds >= milisec)
		{
			elapsedMiliSeconds = 0;
			sprite.setTextureRect(sf::IntRect({ xIndex, yIndex }, { spriteSize.x, spriteSize.y }));
			xIndex += spriteSize.x;
			if (xIndex > spriteSize.x * frameNumber)
			{
				xIndex = 0; StartAttack3 = false;
			}
		}
	}
	sf::Sprite getSprite() { return sprite; }
};