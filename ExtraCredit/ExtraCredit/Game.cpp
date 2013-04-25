#include "Game.h"

/** Public **/
void Game::Setup( SessionData* data )
{
	// @TODO: parse information from SessionData for initial game state

}

void Game::Execute()
{
	// Begin activity
	isActive = true;

	gameWindow.create(sf::VideoMode(500, 500), "myExtraCreditProg");
	gameWindow.setFramerateLimit(60);

	actors[0] = &hunter;
	actors[1] = &dodo;
	actors[2] = &fox;

	h_SpeedX = 1;
	h_SpeedY = 1;

	d_SpeedX = -1;
	d_SpeedY = 1;

	f_SpeedX = 1;
	f_SpeedY = -1;

	for(int i=0; i<3; i++)
		renderable[i] = true;
	

	for(int i=0; i<3; i++)
		actors[i]->Load();

	// Continuous loop until the simulation has been told to terminate
	while ( isActive )
	{
		EventHandling();
		HandleFrame();
		Render();
	}
	gameWindow.close();
}

/** Private **/
void Game::EventHandling()
{
	sf::Event event;
	while(gameWindow.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			EndGame();
	}
}

void Game::HandleFrame()
{
	// @TODO: implement your game logic here
	actors[0]->Move(h_SpeedX, h_SpeedY);
	actors[1]->Move(d_SpeedX, d_SpeedY);
	actors[2]->Move(f_SpeedX, f_SpeedY);

	if(actors[0]->getXPosition() < 0) h_SpeedX = -h_SpeedX;
	if(actors[0]->getXPosition() > 498) h_SpeedX = -h_SpeedX;
	if(actors[0]->getYPosition() < 0) h_SpeedY = -h_SpeedY;
	if(actors[0]->getYPosition() > 498) h_SpeedY = -h_SpeedY;

	if(actors[1]->getXPosition() < 0) d_SpeedX = -d_SpeedX;
	if(actors[1]->getXPosition() > 498) d_SpeedX = -d_SpeedX;
	if(actors[1]->getYPosition() < 0) d_SpeedY = -d_SpeedY;
	if(actors[1]->getYPosition() > 498) d_SpeedY = -d_SpeedY;

	if(actors[2]->getXPosition() < 0) f_SpeedX = -f_SpeedX;
	if(actors[2]->getXPosition() > 498) f_SpeedX = -f_SpeedX;
	if(actors[2]->getYPosition() < 0) f_SpeedY = -f_SpeedY;
	if(actors[2]->getYPosition() > 498) f_SpeedY = -f_SpeedY;

	for(int i=0; i<3; i++)
	{
		if(i != 1)
		{
			if((actors[1]->getXPosition() == actors[i]->getXPosition()) && (actors[1]->getYPosition() == actors[i]->getYPosition()))
			{
				renderable[1] = false;
			}
		}

		if(i != 2)
		{
			if((actors[2]->getXPosition() == actors[i]->getXPosition()) && (actors[2]->getYPosition() == actors[i]->getYPosition()))
				renderable[2] = false;
		}
		if(i != 0)
		{
			int d = sqrt( ((actors[0]->getXPosition() - actors[i]->getXPosition()) * (actors[0]->getXPosition() - actors[i]->getXPosition())) 
				         +((actors[0]->getYPosition() - actors[i]->getYPosition()) * (actors[0]->getXPosition() - actors[i]->getXPosition())));

			if(d<15)
			{
				if(actors[0]->getXPosition() < actors[i]->getXPosition())
				{
					h_SpeedX = 1;
				}
				else
				{
					h_SpeedX = -1;
				}

				if(actors[0]->getYPosition() < actors[i]->getYPosition())
				{
					h_SpeedY = 1;
				}
				else
				{
					h_SpeedY = -1;
				}
			}
		}
	}

	for(int i=0; i<2; i++)
	{
		if((actors[2]->getXPosition() - actors[i]->getXPosition()) < 14)
		{
			f_SpeedX = -f_SpeedX;
		}

		if((actors[2]->getYPosition() - actors[i]->getYPosition()) < 14)
		{
			f_SpeedY = -f_SpeedY;
		}
	}
}

void Game::Render()
{
	gameWindow.clear();

	for(int i=0; i<3; i++)
	{
		if(renderable[i])
			actors[i]->Draw(gameWindow);
	}

	gameWindow.display();
}

void Game::EndGame()
{
	isActive = false;
}