#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;


void getplayercoordinateforview(float x, float y) { //функция для считывания координат игрока
	float tempX = x; float tempY = y;

	if (x < 320) tempX = 320;
	if (y < 240) tempY = 240;
	if (y > 554) tempY = 554;	

	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 

}

void viewmap(float time) { //функция для перемещения камеры по карте. принимает время sfml
	int const speed = 5;

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move(0.1 * speed * time, 0); 
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, 0.1 * speed * time);
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move(-0.1 * speed * time, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, -0.1 * speed * time);
	}


}
void changeview() {


	//if (Mouse::) {
	//	//view.zoom(1.0100f); 
	//	view.zoom(1.0006f); 
	//}

	/*
	Event event{};
	if (event.type ==  sf::Event::MouseWheelScrolled)
	{
		if (event.mouseWheelScroll.delta < 0) {
			view.zoom(0.8f);
			
		}

		else if (event.mouseWheelScroll.delta > 0) {
			view.zoom(1.01f);
			
		}
	}
		*/
	Event event{};
	if (event.type == sf::Event::MouseWheelScrolled)
	{
		if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
		{
			if (event.mouseWheelScroll.delta < 0)
			{
				view.zoom(0.9f);
			}
			else
			{
				view.zoom(1.1f);
			}
		}
	}
	
	


	if (Keyboard::isKeyPressed(Keyboard::I)) {
		view.setSize(640, 480);//устанавливает размер камеры (наш исходный)
	}

	//if (Keyboard::isKeyPressed(Keyboard::P)) {
	//	view.setSize(540, 380);//например другой размер
	//}


	//if (Keyboard::isKeyPressed(Keyboard::Q)) {
	//	view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));
	//}



}