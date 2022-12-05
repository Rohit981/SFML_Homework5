#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H


#include <SFML/Audio.hpp>

namespace gm
{
	class SoundManager
	{
	public:
		SoundManager();
		~SoundManager();

		void PlayPaddleSFX();
		void PlayWallSFX();
		void PlayScoreSFX();
		void PlayGameOverMusic();

		//Paddle Bounce SFX
		sf::SoundBuffer PaddlesfxBuffer;
		sf::Sound paddleBounceSFX;

		//Wall Bounce SFX
		sf::SoundBuffer WallsfxBuffer;
		sf::Sound wallBounceSFX;

		//Score SFX
		sf::SoundBuffer ScoresfxBuffer;
		sf::Sound ScoreSFX;

		//Game Over SFX
		sf::SoundBuffer GameOverBuffer;
		sf::Sound GameOverSFX;
		

	};

}

#endif // !SOUND_MANAGER_H


