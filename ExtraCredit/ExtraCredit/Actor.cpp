#include "Actor.h"

/** Public **/
const bool Actor::DoesCollide( const Actor* actor )
{
	// We assume actors are 1 world unit in width and height and move 1 unit per turn
	return actor->x == x && actor->y == y;
}

void Actor::Load()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setOrigin(5, 5);
	rect.setPosition(x, y);
	rect.setFillColor(sf::Color::White);
}

void Actor::Move(int xVel, int yVel)
{
	rect.move(xVel, yVel);
}

void Actor::Draw(sf::RenderWindow &rWindow)
{
	rWindow.draw(rect);
}

int Actor::getXPosition()
{
	x = rect.getPosition().x;
	return x;
}

int Actor::getYPosition()
{
	y = rect.getPosition().y;
	return y;
}