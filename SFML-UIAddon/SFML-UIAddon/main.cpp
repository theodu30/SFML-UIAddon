#include <SFML/Graphics.hpp>
//#include <SFUIL/UIPanel.hpp>
//#include <SFUIL/Containers/UIVisualContainer.hpp>
//#include <SFUIL/Graphics/RoundedRectangle.hpp>
//#include <SFUIL/System/Properties.hpp>
//#include <SFUIL/Containers/UIImage.hpp>

#include <iostream>
//#include <SFUIL/XMLExport.hpp>
//#include <SFUIL/XMLImport.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 960, 540 }), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(sf::Vector2f(window.getSize()) * .5f);
	shape.setOrigin(sf::Vector2f(shape.getRadius(), shape.getRadius()));

	//sfui::UIPanel panel;
	//panel.setActive(true);
	//panel.setSize(window.getSize());
	//panel.getRootElement()->getProperty<sfui::FlexProperty>().setFlexDirection(sfui::FlexProperty::Direction::Column);
	
	//sfui::UIVisualContainer* container1 = new sfui::UIVisualContainer("Container 1");
	//sfui::UIVisualContainer* container2 = new sfui::UIVisualContainer("Container 2");
	//sfui::UIVisualContainer* container3 = new sfui::UIVisualContainer("Container 3");
	//sfui::UIVisualContainer* container4 = new sfui::UIVisualContainer("Container 4");
	//container1->getProperty<sfui::BackgroundProperty>().setColor(255ui8, 0ui8, 0ui8, 127ui8); // Semi-transparent red
	//container3->getProperty<sfui::BackgroundProperty>().setColor(0ui8, 0ui8, 255ui8, 127ui8); // Semi-transparent blue
	//container4->getProperty<sfui::BackgroundProperty>().setColor(0ui8, 255ui8, 0ui8, 127ui8); // Semi-transparent green
	//container1->getProperty<sfui::FlexProperty>().setFlexDirection(sfui::FlexProperty::Direction::Row);
	//container2->getProperty<sfui::FlexProperty>().setFlexDirection(sfui::FlexProperty::Direction::Row);
	//container1->getProperty<sfui::TransformProperty>().setOriginX(50.f, sfui::TransformProperty::OriginType::Percentage);
	//container1->getProperty<sfui::TransformProperty>().setOriginY(100.f, sfui::TransformProperty::OriginType::Percentage);
	//container2->getProperty<sfui::TransformProperty>().setOriginX(50.f, sfui::TransformProperty::OriginType::Percentage);
	//container2->getProperty<sfui::TransformProperty>().setOriginY(50.f, sfui::TransformProperty::OriginType::Percentage);
	//container3->getProperty<sfui::TransformProperty>().setOriginX(0.f, sfui::TransformProperty::OriginType::Percentage);
	//container3->getProperty<sfui::TransformProperty>().setOriginY(100.f, sfui::TransformProperty::OriginType::Percentage);
	//container4->getProperty<sfui::TransformProperty>().setOriginX(50.f, sfui::TransformProperty::OriginType::Percentage);
	//container4->getProperty<sfui::TransformProperty>().setOriginY(0.f, sfui::TransformProperty::OriginType::Percentage);
	//container1->getProperty<sfui::BorderProperty>().setRadius(20.f);
	//container1->getProperty<sfui::BorderProperty>().setWidth(5.f);
	//container1->getProperty<sfui::BorderProperty>().setColor(255ui8, 0ui8, 0ui8, 191ui8);
	//panel.getRootElement()->addChild(container1);
	//panel.getRootElement()->addChild(container2);
	//
	//sfui::UIImage* img1 = new sfui::UIImage();
	//sfui::ImageProperty& imgProp = img1->getProperty<sfui::ImageProperty>();
	//img1->getProperty<sfui::BackgroundProperty>().setColor(255ui8, 255ui8, 255ui8, 127ui8); // Semi-transparent white
	//img1->getProperty<sfui::BorderProperty>().setRadius(10.f);
	//img1->getProperty<sfui::BorderProperty>().setWidth(3.f);
	//img1->getProperty<sfui::BorderProperty>().setColor(255ui8, 255ui8, 255ui8, 255ui8);
	//imgProp.setImagePath("kirbo_sunset_wallpaper.png");
	////imgProp.setImagePath("circle.png");
	//imgProp.loadImage();
	//imgProp.setWidth(100.f, sfui::ImageProperty::SizeType::Percentage);
	//imgProp.setHeight(100.f, sfui::ImageProperty::SizeType::Percentage);
	//imgProp.setScaleMode(sfui::ImageProperty::ScaleMode::ScaleToFit);
	//imgProp.setSmooth(sfui::ImageProperty::Smooth::Smooth);
	//imgProp.setPositionX(sfui::ImageProperty::PositionXPositionType::Center, 0.f);
	//imgProp.setPositionY(sfui::ImageProperty::PositionYPositionType::Bottom, 100.f, sfui::ImageProperty::PositionOffsetType::Percentage);
	//img1->getProperty<sfui::TransformProperty>().setOriginX(50.f, sfui::TransformProperty::OriginType::Percentage);
	//img1->getProperty<sfui::TransformProperty>().setOriginY(50.f, sfui::TransformProperty::OriginType::Percentage);
	//img1->getProperty<sfui::PositionProperty>().setMode(sfui::PositionProperty::Mode::Relative);
	//container2->addChild(container3);
	//container2->addChild(img1);
	//container2->addChild(container4);

	//sfui::XMLExport::exportToXML(panel.getRootElement(), "panel.xml");
	//sfui::XMLImport::importFromXML("panel.xml");
	std::string panelToLoad = "panel_test.xml";
	//panel.setRootElement(sfui::XMLImport::importFromXML(panelToLoad.c_str())->as<sfui::UIVisualContainer>());
	//sfui::XMLExport::exportToXML(panel.getRootElement(), "panel_out.xml");

	bool rotating = false;
	float rotationSpeed = 50.f; // degrees per frame

	sf::Clock frameClock;

	while (window.isOpen())
	{
		float dt = frameClock.restart().asSeconds();

		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if (event->is<sf::Event::KeyPressed>())
			{
				sf::Keyboard::Key key = event->getIf<sf::Event::KeyPressed>()->code;
				if (key == sf::Keyboard::Key::Escape)
				{
					window.close();
				}
				else if (key == sf::Keyboard::Key::A)
				{
					//panel.setActive(!panel.isActive());
					//std::cout << "Toggled UIPanel active state to " << (panel.isActive() ? "true" : "false") << std::endl;
				}
				else if (key == sf::Keyboard::Key::R)
				{
					rotating = !rotating;
				}
				else if (key == sf::Keyboard::Key::Backspace)
				{
					//if (panel.getRootElement())
					//{
					//	panel.getRootElement()->removeFromHierarchy();
					//}
				}
				else if (key == sf::Keyboard::Key::L)
				{
					//if (panel.getRootElement())
					//{
					//	panel.getRootElement()->removeFromHierarchy();
					//}
					//panel.setRootElement(sfui::XMLImport::importFromXML(panelToLoad.c_str())->as<sfui::UIVisualContainer>());
				}
				else if (key == sf::Keyboard::Key::S)
				{
					//if (panel.getRootElement())
					//{
					//	sfui::XMLExport::exportToXML(panel.getRootElement(), "panel_out.xml");
					//}
				}
			}
		}

		if (rotating)
		{
			bool single = true;
			if (single)
			{
				//if (sfui::UIVisualContainer* c = panel.getRootElement()->query<sfui::UIVisualContainer>("__ELEMENT_TO_ROTATE__"))
				//{
				//	sfui::TransformProperty& transform = c->getProperty<sfui::TransformProperty>();
				//	transform.setRotate(transform.getRotate().value + rotationSpeed * dt);
				//}
			}
			else
			{
				//for (sfui::UIVisualContainer* c : panel.getRootElement()->queryAll<sfui::UIVisualContainer>())
				//{
				//	sfui::TransformProperty& transform = c->getProperty<sfui::TransformProperty>();
				//	transform.setRotate(transform.getRotate().value + rotationSpeed * dt);
				//}
			}
		}

		window.clear();
		window.draw(shape);

		//panel.render();
		//panel.drawToTarget(window);

		window.display();
	}
}