#include <SFML/Graphics.hpp>
#include <SFUIL/UIPanel.hpp>

#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(sf::Vector2f(window.getSize()) * .5f);
	shape.setOrigin(sf::Vector2f(shape.getRadius(), shape.getRadius()));

	sfui::UIPanel panel;
	panel.setActive(true);
	panel.setAlignment(sfui::Alignment::MiddleCenter);
	panel.setSize(window.getSize());

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
			if (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape)
				window.close();
		}

		panel.render();

		window.clear();
		window.draw(shape);

		panel.drawToTarget(window);

		window.display();
	}
}