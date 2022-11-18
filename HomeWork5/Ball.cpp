#include "Ball.h"

using namespace gm;
using namespace std;
using namespace sf;

Ball::Ball(const sf::Vector2f& position, const sf::Vector2f& size): GameObject(position, size)
{
	body.setPosition(position);
	body.setSize(size);
}

void Ball::update(RenderWindow& window, float deltaTime)
{
	
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
}

void Ball::setPosition(const Vector2f& position)
{
	GameObject::setPosition(position);
	body.setPosition(position);
}



void gm::Ball::setVelocity(const sf::Vector2f& velocity)
{
	this->velocity = velocity;
}

const sf::Vector2f& gm::Ball::getVelocity() const
{
	return velocity;
}

void Ball::Bounce(const sf::Vector2f& velocity)
{
}
