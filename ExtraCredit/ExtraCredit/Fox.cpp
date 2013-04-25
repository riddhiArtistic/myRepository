#include "Fox.h"

/** Public **/
const bool Fox::DoesCollide( const Actor* actor )
{
	// We assume actors are 1 world unit in width and height and move 1 unit per turn
	return actor->x == x && actor->y == y;
}

void Fox::Load()
{
	rect.setSize(sf::Vector2f(10.0, 10.0));
	rect.setOrigin(5.0, 5.0);
	rect.setPosition(x, y);
	rect.setFillColor(sf::Color::Red);
	
}

void Fox::Draw(sf::RenderWindow & rWindow)
{
	x = rect.getPosition().x;
	y = rect.getPosition().y;
	rWindow.draw(rect);
}

void Fox::Move(int xVel, int yVel)
{
	rect.move(xVel, yVel);
}

void Fox::Died()
{
	rect.scale(0.1, 0.1);
}