#include <SFML/Graphics.hpp>
#include <SFUIL/UIPanel.hpp>
#include <SFUIL/Containers/UIVisualContainer.hpp>
#include <SFUIL/Graphics/RoundedRectangle.hpp>
#include <SFUIL/System/UIElementProperty.hpp>

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
	panel.getRootElement()->getProperty<sfui::FlexProperty>().setFlexDirection(sfui::FlexProperty::Direction::Column);
	
	sfui::UIVisualContainer* container1 = new sfui::UIVisualContainer("Container 1");
	sfui::UIVisualContainer* container2 = new sfui::UIVisualContainer("Container 2");
	sfui::UIVisualContainer* container3 = new sfui::UIVisualContainer("Container 3");
	sfui::UIVisualContainer* container4 = new sfui::UIVisualContainer("Container 4");
	container1->getProperty<sfui::BackgroundProperty>().setColor(255ui8, 0ui8, 0ui8, 127ui8); // Semi-transparent red
	container3->getProperty<sfui::BackgroundProperty>().setColor(0ui8, 0ui8, 255ui8, 127ui8); // Semi-transparent blue
	container4->getProperty<sfui::BackgroundProperty>().setColor(0ui8, 255ui8, 0ui8, 127ui8); // Semi-transparent green
	container2->getProperty<sfui::FlexProperty>().setFlexDirection(sfui::FlexProperty::Direction::Row);
	container1->getProperty<sfui::TransformProperty>().setOriginX(50.f, sfui::TransformProperty::OriginType::Percentage);
	container1->getProperty<sfui::TransformProperty>().setOriginY(100.f, sfui::TransformProperty::OriginType::Percentage);
	container1->getProperty<sfui::BorderProperty>().setRadius(20.f);
	container1->getProperty<sfui::BorderProperty>().setWidth(5.f);
	container1->getProperty<sfui::BorderProperty>().setColor(255ui8, 0ui8, 0ui8, 191ui8);
	panel.getRootElement()->addChild(container1);
	panel.getRootElement()->addChild(container2);
	container2->addChild(container3);
	container2->addChild(container4);

	bool rotating = false;

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
					rotating = !rotating;
					if (!rotating)
					{
						if (sfui::UIVisualContainer* c = panel.getRootElement()->query<sfui::UIVisualContainer>("Container 1"))
						{
							const sfui::TransformProperty& transform = c->getConstProperty<sfui::TransformProperty>();
							std::cout << "Stopped rotating. Final angle: " << transform.getRotate().value << " degrees." << std::endl;
						}
					}
				}
			}
		}

		if (rotating)
		{
			if (sfui::UIVisualContainer* c = panel.getRootElement()->query<sfui::UIVisualContainer>("Container 1"))
			{
				sfui::TransformProperty& transform = c->getProperty<sfui::TransformProperty>();
				transform.setRotate(transform.getRotate().value + 15.f);
			}
		}

		window.clear();
		window.draw(shape);

		panel.render();
		panel.drawToTarget(window);

		window.display();
	}
}