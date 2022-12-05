#include "AIController.h"
#include<iostream>

using namespace gm;
using namespace sf;
using namespace std;

AIController::AIController(Paddle* paddle2, Ball* ball)
{
	this->paddle2 = paddle2;
	this->ball = ball;
	aiMovement = STATIC;
}

AIController::~AIController()
{

}

// moves the paddle based on the sense desicion 
void AIController::Update(sf::RenderWindow& window, float deltaTime)
{
	Sense(deltaTime);


	if (aiMovement ==  STATIC)
	{
		paddle2->setMovmentDirection(MovementDirection::None);

	}


	else if (aiMovement == MOVEDOWN)
	{
		if (paddle2->getPosition().y < 540)
		{
			paddle2->setMovmentDirection(MovementDirection::DOWN);

		}
		else
		{
			paddle2->setMovmentDirection(MovementDirection::None);

		}

	}

	else if (aiMovement == MOVEUP)
	{
		if (paddle2->getPosition().y > 5)
		{
			paddle2->setMovmentDirection(MovementDirection::UP);

		}
		else
		{
			paddle2->setMovmentDirection(MovementDirection::None);

		}

	}

	
}

// Senses the ball position
void AIController::Sense(float deltaTime)
{
	if (ball->getPosition().x < 0 || ball->getPosition().x > 640)
	{
		aiMovement = STATIC;
	}
	
	else if (paddle2->getPosition().y < ball->getPosition().y)
	{	
		aiMovement = MOVEDOWN;

	}

	else if (paddle2->getPosition().y > ball->getPosition().y)
	{
		aiMovement = MOVEUP;
	}
	
	

	

}
