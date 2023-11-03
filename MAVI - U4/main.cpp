#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main()
{
	//////Variables//////
	Texture texture;
	Sprite circleRed1, circleRed2, circleRed3, circleRed4;
	bool mousePressed = false, targetCircle1 = false, targetCircle2 = false, targetCircle3 = false, targetCircle4 = false;


	//Cargamos la textura del archivo
	texture.loadFromFile("assets/rcircle.png");

	//Cargamos el material del sprite
	circleRed1.setTexture(texture);
	circleRed2.setTexture(texture);
	circleRed3.setTexture(texture);
	circleRed4.setTexture(texture);

	//Modificamos posicionamiento
	circleRed2.setPosition(672, 0);
	circleRed3.setPosition(0, 472);
	circleRed4.setPosition(672, 472);

	/////Creamos la ventana//////
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Que ventana horrible");

	/////Loop principal//////
	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;

				//Cuando hacemos click
			case sf::Event::MouseButtonPressed:
				mousePressed = true;
				//Si clickeamos dentro del area del circulo 1
				if (sf::Mouse::getPosition(App).x >= circleRed1.getPosition().x && sf::Mouse::getPosition(App).x <= circleRed1.getPosition().x + 128 &&
					sf::Mouse::getPosition(App).y >= circleRed1.getPosition().y && sf::Mouse::getPosition(App).y <= circleRed1.getPosition().y + 128) {
					targetCircle1 = true;
				}
				//Si clickeamos dentro del area del circulo 2
				else if (sf::Mouse::getPosition(App).x >= circleRed2.getPosition().x && sf::Mouse::getPosition(App).x <= circleRed2.getPosition().x + 128 &&
					sf::Mouse::getPosition(App).y >= circleRed2.getPosition().y && sf::Mouse::getPosition(App).y <= circleRed2.getPosition().y + 128) {
					targetCircle2 = true;
				}
				//Si clickeamos dentro del area del circulo 3
				else if (sf::Mouse::getPosition(App).x >= circleRed3.getPosition().x && sf::Mouse::getPosition(App).x <= circleRed3.getPosition().x + 128 &&
						 sf::Mouse::getPosition(App).y >= circleRed3.getPosition().y && sf::Mouse::getPosition(App).y <= circleRed3.getPosition().y + 128) {
					targetCircle3 = true;
				}
				//Si clickeamos dentro del area del circulo 4
				else if (sf::Mouse::getPosition(App).x >= circleRed4.getPosition().x && sf::Mouse::getPosition(App).x <= circleRed4.getPosition().x + 128 &&
						 sf::Mouse::getPosition(App).y >= circleRed4.getPosition().y && sf::Mouse::getPosition(App).y <= circleRed4.getPosition().y + 128) {
					targetCircle4 = true;
				}
				
				break;

			case sf::Event::MouseButtonReleased:
				mousePressed = false;
				targetCircle1 = false;
				targetCircle2 = false;
				targetCircle3 = false;
				targetCircle4 = false;

				break;

				//Movemos el circulo seleccionado
			case sf::Event::MouseMoved:
				if (mousePressed && targetCircle1) {
					
					circleRed1.setPosition(sf::Mouse::getPosition(App).x - 64, sf::Mouse::getPosition(App).y - 64);
				}
				if (mousePressed && targetCircle2) {
					circleRed2.setPosition(sf::Mouse::getPosition(App).x - 64, sf::Mouse::getPosition(App).y - 64);
				}
				if (mousePressed && targetCircle3) {
					circleRed3.setPosition(sf::Mouse::getPosition(App).x - 64, sf::Mouse::getPosition(App).y - 64);
				}
				if (mousePressed && targetCircle4) {
					circleRed4.setPosition(sf::Mouse::getPosition(App).x - 64, sf::Mouse::getPosition(App).y - 64);
				}
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
				App.close();
		}		

		App.clear();

		App.draw(circleRed1);
		App.draw(circleRed2);
		App.draw(circleRed3);
		App.draw(circleRed4);

		App.display();
	}
	return 0;
}

