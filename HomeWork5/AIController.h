#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

#include "Paddle.h"
#include "Ball.h"
enum AIMovement 
{
	STATIC = 0,
	MOVEUP = -1,
	MOVEDOWN = 1
};

namespace gm
{
	

	class AIController
	{
	
	public:
		AIController(Paddle* paddle2, Ball* ball);
		~AIController();

		void Update(sf::RenderWindow& window, float deltaTime);
		void Sense(float deltaTime);

	private:
		bool StopDownMove = false;

		Paddle* paddle2;
		Ball* ball;

		AIMovement aiMovement;
	};

}

#endif // !AI_CONTROLLER_H

