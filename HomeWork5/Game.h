// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 /* Our Includes */
#include "Paddle.h"
#include "Ball.h"
#include "PlayerController.h"
#include "AIController.h"
#include "UI.h"
#include "SoundManager.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	const int GameWidth = 640;
	const int GameHeight = 640;

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		// The game window
		sf::RenderWindow window;
		// For tracking/maintaining delta time
		sf::Clock clock;
		float deltaTime;
		// Our game objects
		Paddle*paddle1;
		Paddle* paddle2;
		Ball *ball;
		Paddle*paddingTop;
		Paddle*paddingBottom;
		Paddle* paddingLeft;
		Paddle* paddingRight;

		//Controllers
		PlayerController* playerController;
		AIController* aiController;
		UI* gameUI;
		SoundManager* soundManager;

		float testTime = 0;
		


		
	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		void run();
		// Game Loop Programming Pattern Methods
		void handleInput();
		void update();
		void render();
		void Setup();
		void CollisionCheck();
		// Destructor
		~Game();
	};
}

#endif