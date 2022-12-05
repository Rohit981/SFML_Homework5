#ifndef UI_H
#define UI_H

#include "Ball.h"
namespace gm
{
	class UI
	{
	public:
		UI(Ball* ball);
		~UI();

		void Update(sf::RenderWindow& window, float deltaTime);
		void render(sf::RenderWindow& window, float deltaTime);

		void SetScore(const int PlayerScore, const int AIscore );
		const int GetPlayerScore() const;
		const int GetAIScore() const;
		
		bool isGameOver = false;
		

		
		

	private:

		int newPlayerScore = 0;
		int newAIScore = 0;

		int PlayerScore = 0;
		int AIScore = 0;

		

		sf::Font font;
		sf::Text Player1scoretext;
		sf::Text Player2scoretext;
		sf::Text GameOvertext;

		

		Ball* ball;
	};

}

#endif // !UI_H

