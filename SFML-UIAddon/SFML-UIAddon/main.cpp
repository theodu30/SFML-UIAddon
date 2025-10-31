#include <SFML/Graphics.hpp>
#include <SFUIL/UIPanel.hpp>
#include <SFUIL/Containers/UIVisualContainer.hpp>

#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 640, 360 }), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(sf::Vector2f(window.getSize()) * .5f);
	shape.setOrigin(sf::Vector2f(shape.getRadius(), shape.getRadius()));

	sfui::UIPanel panel;
	panel.setActive(true);
	panel.setSize(window.getSize());
	panel.getRootElement()->getFlexProperty().flexDirection = sfui::FlexDirectionProperty::Column;
	
	sfui::UIVisualContainer* container1 = new sfui::UIVisualContainer("Container 1");
	sfui::UIVisualContainer* container2 = new sfui::UIVisualContainer("Container 2");
	sfui::UIVisualContainer* container3 = new sfui::UIVisualContainer("Container 3");
	sfui::UIVisualContainer* container4 = new sfui::UIVisualContainer("Container 4");
	container1->getBackgroundProperty().color = sf::Color(255, 0, 0, 191); // Semi-transparent red
	container3->getBackgroundProperty().color = sf::Color(0, 0, 255, 191); // Semi-transparent blue
	container4->getBackgroundProperty().color = sf::Color(0, 255, 0, 191); // Semi-transparent green
	container2->getFlexProperty().flexDirection = sfui::FlexDirectionProperty::Row;
	container3->getTransformProperty().origin.x = { .value = 50.f, .type = sfui::TransformOriginValueTypeProperty::Percentage };
	container3->getTransformProperty().origin.y = { .value = 50.f, .type = sfui::TransformOriginValueTypeProperty::Percentage };
	panel.getRootElement()->addChild(container1);
	panel.getRootElement()->addChild(container2);
	container2->addChild(container3);
	container2->addChild(container4);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
			if (event->is<sf::Event::KeyPressed>())
			{
				sf::Keyboard::Key key = event->getIf<sf::Event::KeyPressed>()->code;
				if (key == sf::Keyboard::Key::Escape)
					window.close();
				if (key == sf::Keyboard::Key::A)
				{
					panel.setActive(!panel.isActive());
					std::cout << "Toggled UIPanel active state to " << (panel.isActive() ? "true" : "false") << std::endl;
				}
				if (key == sf::Keyboard::Key::R)
				{
					if (sfui::UIVisualContainer* c = panel.getRootElement()->query<sfui::UIVisualContainer>("Container 3"))
					{
						sfui::TransformProperty& transform = c->getTransformProperty();
						transform.rotate.angle.value += 15.f;
					}
				}
			}
		}

		window.clear();
		window.draw(shape);

		panel.render();
		panel.drawToTarget(window);

		window.display();
	}
}