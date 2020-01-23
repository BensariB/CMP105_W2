#include "Level.h"
#include <string>
#include<sstream>  
#include <cmath>


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	//text:
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Font error";
	}
	text.setFont(font);

	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);
	text.setPosition(0, 0);
	justPressed = 0;
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	//Keys::
	if (input->isKeyDown(sf::Keyboard::W)) {
		std::cout << "The key W was pressed\n";
		input->setKeyUp(sf::Keyboard::W);
	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L)) {
		std::cout << "J, K and L were pressed.\n";
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
	}
	
	if (input->isKeyDown(sf::Keyboard::Escape)) {
		window->close();
	}

	//Mouse position:
	int x = input->getMouseX();
	std::stringstream s1;
	s1 << x;
	std::string sx;
	s1 >> sx;

	int y = input->getMouseY();
	std::stringstream s2;
	s2 << y;
	std::string sy;
	s2 >> sy;

	std::string str = "Position X: " + sx + "\nPosition Y: " + sy;
	text.setString(str);

	//Mouse press:
	if (input->isMouseLDown() && justPressed == 0) {
		justPressed = 1;
		mouseLx = input->getMouseX();
		mouseLy = input->getMouseY();
	}
	if (input->isMouseLDown() == 0 && justPressed == 1) {
		justPressed = 0;
		int mx = input->getMouseX();
		int my = input->getMouseY();
		int dis;
		mx = (mx - mouseLx) * (mx - mouseLx);
		my = (my - mouseLy) * (my - mouseLy);
		dis = sqrt(my + mx);
		std::cout << "Distance: " << dis << std::endl;
	}
}

// Update game objects
void Level::update()
{
	
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}