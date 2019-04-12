#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	const float g = 9.81;
	float speedy, speedx;
	std::string vsync;

	std::cout << "enter vertical speed: " << std::endl;
	std::cin >> speedy;

	std::cout << "enter horizontal speed: " << std::endl;
	std::cin >> speedx;

	std::cout << "enable vsync? 5unstable ball.jpg) (y/n)" << std::endl;
	std::cin >> vsync;

	

	//initialises the window
	sf::RenderWindow window(sf::VideoMode(1500, 900), "Gravity", sf::Style::Close);

	if (vsync == "y")
	{
		window.setVerticalSyncEnabled(true);
	}

	sf::CircleShape ball;
	ball.setRadius(20);
	ball.setOutlineThickness(1);
	ball.setOutlineColor(sf::Color::Black);
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(40, 40);
	ball.setOrigin(0, 0);

	sf::Clock clock; // starts the clock


	while (window.isOpen())
	{
		sf::Event evnt;

		//closes the window if needed'
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}

		if (ball.getPosition().y <= window.getSize().y && ball.getPosition().y >= 0)
		{
			ball.move(speedx, speedy);
		}
		if (ball.getPosition().y >= window.getSize().y - 40)
		{
			speedy *= -0.8;
			ball.move(speedx, speedy);
		}

		if (ball.getPosition().y <= 0)
		{
			speedy *= -1;
			ball.move(speedx, speedy);
		}

		sf::Time elapsed1 = clock.getElapsedTime();

		if (elapsed1.asSeconds() >= 0.03125)
		{
			if (speedx < 0)
			{
				speedx += 0.03;
			}

			if (speedx > 0)
			{
				speedx -= 0.03;
			}
			speedy += 0.3125;
			clock.restart();
		}

		if (ball.getPosition().x >= window.getSize().x - 30)
		{
			speedx *= -0.9;
		}

		if (ball.getPosition().x <= 0)
		{
			speedx *= -0.9;
		}

		window.clear(sf::Color::White);
		window.draw(ball);
		window.display();
	}
	return 0;
}