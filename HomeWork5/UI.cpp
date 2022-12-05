#include "UI.h"

using namespace gm;
using namespace sf;
using namespace std;

UI::UI(Ball* ball)
{
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		throw("Could not found the font");
	}

	Player1scoretext.setFont(font);
	Player1scoretext.setCharacterSize(44);
	//scoretext.setColor(Color::Green);
	Player1scoretext.setStyle(Text::Bold);
	Player1scoretext.setPosition(Vector2f(50, 50));
	Player1scoretext.setString(to_string(GetPlayerScore()));

	Player2scoretext.setFont(font);
	Player2scoretext.setCharacterSize(44);
	//scoretext.setColor(Color::Green);
	Player2scoretext.setStyle(Text::Bold);
	Player2scoretext.setPosition(Vector2f(550, 50));
	Player2scoretext.setString(to_string(GetAIScore()));

	GameOvertext.setFont(font);
	GameOvertext.setCharacterSize(60);
	//scoretext.setColor(Color::Green);
	GameOvertext.setStyle(Text::Bold);
	GameOvertext.setPosition(Vector2f(90, 300));
	

	this->ball = ball;
}

UI::~UI()
{

}

// updates the sprite for player1 and player2 scores 
void UI::Update(sf::RenderWindow& window, float deltaTime)
{
	

	if (ball->getPosition().x < 0)
	{
		newAIScore = GetAIScore() + 1;
		Player2scoretext.setString(to_string(newAIScore));
		
		
	}

	if (ball->getPosition().x > 640)
	{
		newPlayerScore = GetPlayerScore() + 1;
		Player1scoretext.setString(to_string(newPlayerScore));
		

	}


	if (ball->getPosition().x == 320)
	{
		SetScore(newPlayerScore, newAIScore);
		
	}

	if (newPlayerScore == 5)
	{
		GameOvertext.setString("PLAYER 1 WON");
		isGameOver = true;

	}
	else if (newAIScore == 5)
	{
		GameOvertext.setString("PLAYER 2 WON");
		isGameOver = true;

	}
	

}

void gm::UI::render(sf::RenderWindow& window, float deltaTime)
{

	window.draw(Player1scoretext);
	window.draw(Player2scoretext);
	window.draw(GameOvertext);

	
}

void gm::UI::SetScore(const int PlayerScore, const int AIscore)
{
	this->PlayerScore = PlayerScore;
	this->AIScore = AIscore;

	
}

const int gm::UI::GetPlayerScore() const
{
	return PlayerScore;
}

const int gm::UI::GetAIScore() const
{
	return AIScore;
}
