#include <stdio.h>
#include "Game.h"

/**
	Main entry point for the application.
**/
int main( int argc, char* argv[] )
{
	Game game;

	// Game now handles all application execution
	game.Execute();

	return 0;
}