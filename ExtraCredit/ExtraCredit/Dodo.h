#ifndef __DODO_H_
#define __DODO_H_

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Actor.h"
/*
	Actor
	======================
	Main in-world representation of a physical object
*/
class Dodo : public Actor
{
public:
	/* Data */
	int x;											// x coordinate in world space
	int y;											// y coordinate in world space
	int SpeedX;
	int SpeedY;

	/* Functions */
	Dodo() : x(300), y(450) { }
	const bool DoesCollide( const Actor* actor );	// Determines if two actors are colliding
	void Load();
	virtual void Move(int xVel, int yVel);
	void Draw(sf::RenderWindow & rWindow);
	void Died();
};

#endif