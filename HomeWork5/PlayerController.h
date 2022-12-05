#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Paddle.h"
namespace gm {
	class PlayerController
{
public:
	PlayerController(Paddle* Paddle1);
	~PlayerController();

	void HandleInput(sf::RenderWindow& window);

private:
	Paddle* Paddle1;
};

}

#endif // !PLAYER_CONTROLLER_H


