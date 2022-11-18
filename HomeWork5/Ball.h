#ifndef BALL_H
#define BALL_H

#include "GameObject.h"

namespace gm {
class Ball :public GameObject
{
private:
	sf::Vector2f velocity;

protected:
	sf::RectangleShape body;

public:
	Ball(const sf::Vector2f& position, const sf::Vector2f& size);
	// Our update interface, NOTE it is a pure virtual function
	virtual void update(sf::RenderWindow& window, float deltaTime) override;

	// Our render interface, NOTE it is a pure virtual function
	virtual void render(sf::RenderWindow& window, float deltaTime) override;

	// Move the box from its current position to a new one with a specified velocity
	virtual void move(const sf::Vector2f& velocity) override;

	virtual void setPosition(const sf::Vector2f& position) override;

	virtual void setVelocity(const sf::Vector2f& velocity);
	virtual const sf::Vector2f& getVelocity() const;

	void Bounce(const sf::Vector2f& velocity);

};

}
#endif // !BALL_H


