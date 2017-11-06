#pragma once
#include"DEFINITIONS.h"
#include "Game.h"
#include "Rocket.h"

namespace CoreAidan {
	class Rockets {
	public:
		Rockets(GameDataRef data);

		void update(Vector2d target);
		void draw();

		void evaluate(Vector2d vector);
		void selection();

		bool isDone();
	private:
		GameDataRef _data;

		std::vector<Rocket*> _rockets;
		std::vector<Rocket*> _matingpool;
		int _populationSize;
	};
}