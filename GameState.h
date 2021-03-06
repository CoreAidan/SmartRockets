#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Rockets.h"

namespace CoreAidan
{
	class GameState : public State
	{
	public:

		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		Rockets *rockets;
		Vector2d _target;
		
		int _generation;

		sf::Sprite _background;
	};
}