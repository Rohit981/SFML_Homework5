#define _USE_MATH_DEFINES

#include "Ball.h"
#include <cmath>
#include <math.h>
#include<iostream>

using namespace gm;
using namespace std;
using namespace sf;


Ball::Ball(const sf::Vector2f& position, const sf::Vector2f& size): GameObject(position, size)
{
	this->size = size;
	body.setPosition(position);
	body.setFillColor(Color::Red);
	body.setSize(size);
}

void Ball::update(RenderWindow& window, float deltaTime)
{
	MoveBall(deltaTime);

	ResetBallPos(deltaTime);


}

void Ball::render(RenderWindow& window, float deltaTime)
{
	window.draw(body);
}

void Ball::move(const Vector2f& velocity)
{
	GameObject::move(velocity);
	// Don't forget to update the Box's shape position to match the new position
	
	body.setPosition(position);
	body.setSize(size);

	
}

void Ball::setPosition(const Vector2f& position)
{
	GameObject::setPosition(position);
	body.setPosition(position);
}

void Ball::setSize(const sf::Vector2f& size)
{
	GameObject::setSize(size);
	body.setSize(size);
}



void gm::Ball::setVelocity(const sf::Vector2f& velocity)
{
	this->velocity = velocity;
}

const sf::Vector2f& gm::Ball::getVelocity() const
{
	return velocity;
}

void gm::Ball::setDirection(const int MoveDirection)
{
	this->MoveDirection = MoveDirection;
}

int gm::Ball::getDirection() const
{
	return MoveDirection;
}

// Bounces the ball of the paddle based on which side of the paddle the ball hits
void Ball::Bounce(const sf::Vector2f& BallPos, const sf::Vector2f& PaddlePos,const sf::Vector2f& PaddleSize, int SpeedIncrease)
{
	
	//ball collides with top paddle
	if (BallPos.y < PaddlePos.y + PaddleSize.x)
	{	
		
		setVelocity(Vector2f(MoveDirection, reflectionDir.x));
	}
	else
	{
		//ball collides with bottom paddle
		setVelocity(Vector2f(MoveDirection, reflectionDir.y));


	}

	//ball collides with center of the paddle
	if (BallPos.x <= PaddlePos.y + (PaddleSize.x)/2 && BallPos.y <= PaddlePos.y +(PaddleSize.y) / 2)
	{
		setVelocity(Vector2f(MoveDirection, rebound));
		//printf("Center");

	}

	/*cout<< " Ball Position X: " << BallPos.x << endl;
	cout<< " Ball Position Y: " << BallPos.y << endl;*/


	BallMovementSpeed += SpeedIncrease;

	


	

}


//when the ball goes off the screen then after 2 sec reset the ball to the original position and radomize direction
void Ball::ResetBallPos(float deltaTime)
{


	if (getPosition().x < 0 || getPosition().x > 640)
	{
		ResetTimer += deltaTime;
		
	}

	if (ResetTimer > 2)
	{

		MoveDirection = MinMoveDirection + rand() % (MaxMoveDirection - MinMoveDirection + 1);

		if (MoveDirection == 0)
		{
			MoveDirection = -1;
		}

		setVelocity(Vector2f(MoveDirection, 0));

		

		BallMovementSpeed = 300;

		setPosition(Vector2f(320, 320));

		ResetTimer = 0;
		
		
	}
}

// moves the ball on update
void Ball::MoveBall(float deltaTime)
{

	move(Vector2f(getVelocity().x* BallMovementSpeed* deltaTime, getVelocity().y * BallMovementSpeed * deltaTime));

}


