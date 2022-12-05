// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include<iostream>

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;
using namespace std;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0)
{
	Setup();
	// Set our fps to 60
	window.setFramerateLimit(60);
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
		// Every frame we...
		// Keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();

		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();

		


		
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() 
{
	// Check for events from the window
	// E.g., is the window being closed?
	playerController->HandleInput(window);
	
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() 
{
	if (gameUI->isGameOver == false)
	{
		paddle1->update(window, deltaTime);
		paddle2->update(window, deltaTime);
		ball->update(window, deltaTime);
		aiController->Update(window, deltaTime);
		gameUI->Update(window, deltaTime);
	
		CollisionCheck();


	}

	


}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() 
{
	// This clears the window at the beginning of every frame
	window.clear();

	// Draw our GameObjects
	paddle1->render(window, deltaTime);
	paddle2->render(window, deltaTime);
	ball->render(window, deltaTime);
	/*paddingTop->render(window, deltaTime);
	paddingBottom->render(window, deltaTime);*/
	/*paddingLeft->render(window, deltaTime);
	paddingRight->render(window, deltaTime);*/


	gameUI->render(window, deltaTime);

	
	
	
	// Display the window buffer for this frame
	window.display();
}

void Game::Setup()
{
	//Initializing all the GameObjects
	paddle1 = new Paddle(Vector2f(20, 270), Vector2f(30, 100));
	paddle2 = new Paddle(Vector2f(590, 270), Vector2f(30, 100));
	ball = new Ball(Vector2f(320, 320), Vector2f(20, 20));
	paddingTop = new Paddle(Vector2f(50,0), Vector2f(550,20));
	paddingBottom = new Paddle(Vector2f(50,620), Vector2f(550, 20));
	paddingLeft = new Paddle(Vector2f(0, 0), Vector2f(2, 640));
	paddingRight = new Paddle(Vector2f(636, 0), Vector2f(2, 640));
	
	//Initializing the Controllers
	playerController = new PlayerController(paddle1);
	aiController = new AIController(paddle2, ball);
	
	gameUI = new UI(ball);
	soundManager = new SoundManager();

	
}

//Collision check function and setting the reflection vector of the ball when it collides with paddles
// 
// set direction is in which direction the ball will go after colliding with the paddles
//rebound variable is used for the bottom as the ball was not bouncing when it was hitting the pad
void Game::CollisionCheck()
{
	// If the ball collides with box1
	if (paddle1->collide(FloatRect(ball->getPosition().x, ball->getPosition().y, ball->getSize().x, ball->getSize().y)))
	{
		ball->reflectionDir = Vector2f(-1, 1);
		ball->rebound = 0;
		ball->setDirection(1);

		ball->Bounce(ball->getPosition(), paddle1->getPosition(), paddle1->getSize(), 5);



		soundManager->PlayPaddleSFX();

		

	}

	// If the ball collides with box2
	if (paddle2->collide(FloatRect(ball->getPosition().x, ball->getPosition().y, ball->getSize().x, ball->getSize().y)))
	{
		ball->reflectionDir = Vector2f(-1, 1);
		ball->rebound = 0;
		ball->setDirection(-1);

		ball->Bounce(ball->getPosition(), paddle2->getPosition(), paddle2->getSize(), 5);



		soundManager->PlayPaddleSFX();




	}

	//if ball collides with top padding
	if (paddingTop->collide(FloatRect(ball->getPosition().x, ball->getPosition().y, ball->getSize().x, ball->getSize().y)))
	{
		ball->reflectionDir = Vector2f(1, -1);
		ball->rebound = 0;

		ball->Bounce(ball->getPosition(), paddingTop->getPosition(), paddingTop->getSize(), 0);

		soundManager->PlayWallSFX();

	}

	//if ball collides with bottom padding
	if (paddingBottom->collide(FloatRect(ball->getPosition().x, ball->getPosition().y, ball->getSize().x, ball->getSize().y)))
	{
		ball->reflectionDir = Vector2f(-1, 1);
		ball->rebound = -1;


		ball->Bounce(ball->getPosition(), paddingBottom->getPosition(), paddingBottom->getSize(), 0);


		soundManager->PlayWallSFX();


	}


	//Cheesy way of playing score sound wasn't able to figure out how to play it otherwise

	if (paddingLeft->collide(FloatRect(ball->getPosition().x, ball->getPosition().y, ball->getSize().x, ball->getSize().y)))
	{

		soundManager->PlayScoreSFX();



	}


	if (paddingRight->collide(FloatRect(ball->getPosition().x, ball->getPosition().y, ball->getSize().x, ball->getSize().y)))
	{

		soundManager->PlayScoreSFX();


	}




}



// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() 
{

}