#ifndef __GAME_H_
#define __GAME_H_

#include <cstdlib>

#include "SessionData.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <cmath>
#include "Hunter.h"
#include "Dodo.h"
#include "Fox.h"

/*
	Game
	======================
	Basic logic handler for setting up state and maintaining game session.
*/
class Game
{
public:
	Game() : isActive(false) { }
	void Setup( SessionData* data );	// Initializes game state
	void Execute();						// Begins game loop execution
	Actor *actors[3];
	bool renderable[3];
	Hunter hunter;
	Dodo dodo;
	Fox fox;

private:
	/* Data */
	bool isActive;						// Flag indicating whether the game will continue or not

	sf::RenderWindow gameWindow;

	int h_SpeedX, d_SpeedX, f_SpeedX;
	int h_SpeedY, d_SpeedY, f_SpeedY;

	/* Functions */
	void EventHandling();
	void HandleFrame();					// Runs logic needed per-frame
	void Render();
	void EndGame();						// Stops 
};

#endif