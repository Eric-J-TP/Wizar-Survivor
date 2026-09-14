#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//classes file
#include "classes/Map/Map.cpp";
#include "classes/Player/Player.cpp";
#include "classes/Enemy/Skeleton_Archer/Archer.cpp";
void startMusic(sf::Music& music)
{
	if (music.openFromFile("sounds/main2.wav"))
	{
		music.play();
		music.setLooping(true);
	}
}

int main()
{

	sf::RenderWindow window(sf::VideoMode({ 1200,600 }), "Wizard Survivor");
	Map map;
	Player player;
	Archer archer;
	sf::Music mainMusic;


	startMusic(mainMusic);
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.setFramerateLimit(60);
		window.clear(sf::Color::Black);
		window.draw(map.getSprite());

		//Enemy
		archer.animate();
		window.draw(archer.getSprite());
		//Player
		player.animate();
		window.draw(player.getSprite());
		//------------
		window.display();
	}

	return 0;
}