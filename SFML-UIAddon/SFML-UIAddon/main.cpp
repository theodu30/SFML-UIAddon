#include <SFML/Graphics.hpp>
#include <SFMLUIAddon/UIPanel.hpp>

#include <iostream>

int main()
{
    sfui::UIPanel panel;
    panel.setActive(true);

	sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}