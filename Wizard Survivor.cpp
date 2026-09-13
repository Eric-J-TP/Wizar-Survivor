#include <SFML/Graphics.hpp>

//classes file
#include "classes/Map/Map.cpp";
#include "classes/Player/Player.cpp";


int main()
{

	sf::RenderWindow window(sf::VideoMode({ 1200,600 }), "Wizard Survivor");
	Map map;
	Player player;


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
		player.animate();
		window.draw(player.getSprite());
		window.display();
	}

	return 0;
}