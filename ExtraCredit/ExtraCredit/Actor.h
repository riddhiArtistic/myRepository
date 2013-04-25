#ifndef __ACTOR_H_
#define __ACTOR_H_

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <time.h>
/*
	Actor
	======================
	Main in-world representation of a physical object
*/
class Actor
{
public:
	/* Data */
	int x;											// x coordinate in world space
	int y;											// y coordinate in world space
	sf::RectangleShape rect;

	/* Functions */
	Actor() : x(0), y(0) { }
	const bool DoesCollide( const Actor* actor );	// Determines if two actors are colliding
	virtual void Load();
	virtual void Move(int xVel, int yVel);
	virtual void Draw(sf::RenderWindow &rWindow);
	int getXPosition();
	int getYPosition();
};

#endif