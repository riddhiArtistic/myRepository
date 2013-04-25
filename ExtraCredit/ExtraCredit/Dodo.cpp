#include "Dodo.h"

/** Public **/
const bool Dodo::DoesCollide( const Actor* actor )
{
	// We assume actors are 1 world unit in width and height and move 1 unit per turn
	return actor->x == x && actor->y == y;
}

void Dodo::Load()
{
	rect.setSize(sf::Vector2f(10.0, 10.0));
	rect.setOrigin(5.0, 5.0);
	rect.setPosition(x, y);
	rect.setFillColor(sf::Color::Yellow);
	
}

void Dodo::Draw(sf::RenderWindow & rWindow)
{
	rWindow.draw(rect);
}

void Dodo::Move(int xVel, int yVel)
{
	rect.move(xVel, yVel);
}

void Dodo::Died()
{
	rect.scale(0.1, 0.1);
}

