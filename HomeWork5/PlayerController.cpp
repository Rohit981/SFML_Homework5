#include "PlayerController.h"

using namespace gm;
using namespace sf;

PlayerController::PlayerController(Paddle* Paddle1)
{
	this->Paddle1 = Paddle1;
}

PlayerController::~PlayerController()
{

}

void PlayerController::HandleInput(sf::RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		// Handle keyboard input to move box 1
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::W) {
				Paddle1->setMovmentDirection(MovementDirection::UP);
			}
			else if (event.key.code == Keyboard::S) {
				Paddle1->setMovmentDirection(MovementDirection::DOWN);
			}
		}

		if (event.type == Event::KeyReleased) {
			if (event.key.code == Keyboard::W && Paddle1->getMovementDirection() == MovementDirection::UP) {
				Paddle1->setMovmentDirection(MovementDirection::None);
			}
			if (event.key.code == Keyboard::S && Paddle1->getMovementDirection() == MovementDirection::DOWN) {
				Paddle1->setMovmentDirection(MovementDirection::None);
			}
		}

	}
}
