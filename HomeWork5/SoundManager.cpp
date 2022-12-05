#include "SoundManager.h"

using namespace gm;

SoundManager::SoundManager()
{
	if (!PaddlesfxBuffer.loadFromFile("Audio/paddle_bounce.wav"))
	{
		throw("Could not load paddle bounce SFX");
	}

	paddleBounceSFX.setBuffer(PaddlesfxBuffer);

	if (!WallsfxBuffer.loadFromFile("Audio/wall_bounce.wav"))
	{
		throw("Could not load wall bounce SFX");
	}
	wallBounceSFX.setBuffer(WallsfxBuffer);
	
	if (!ScoresfxBuffer.loadFromFile("Audio/score.wav"))
	{
		throw("Could not load score SFX");
	}

	ScoreSFX.setBuffer(ScoresfxBuffer);

	if (!GameOverBuffer.loadFromFile("Audio/victory.wav"))
	{
		throw("Could not Game Over Music");

	}
	GameOverSFX.setBuffer(GameOverBuffer);


}

SoundManager::~SoundManager()
{

}

void SoundManager::PlayPaddleSFX()
{
	
	paddleBounceSFX.play();
}

void SoundManager::PlayWallSFX()
{
	

	wallBounceSFX.play();
}

void SoundManager::PlayScoreSFX()
{
	
	ScoreSFX.play();
	

}

void SoundManager::PlayGameOverMusic()
{

	GameOverSFX.play();

	
}
