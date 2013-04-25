#ifndef __HUNTER_H_
#define __HUNTER_H_

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Actor.h"

/*
	Actor: Hunter
	======================
	Main in-world representation of a physical object
*/
class Hunter : public Actor
{
public:
	/* Data */
	int x;											// x coordinate in world space
	int y;											// y coordinate in world space
	int SpeedX;
	int SpeedY;

	/* Functions */
	Hunter() : x(90), y(50) { }
	const bool DoesCollide( const Actor* actor );	// Determines if two actors are colliding
	void Load();
	virtual void Move(int xVel, int yVel);
	void Draw(sf::RenderWindow & rWindow);
};

#endif