#pragma once
#include "Vector2d.h"
#include "Game.h"

namespace CoreAidan {
	class DNA {
	public:
		DNA();
		DNA(std::vector<Vector2d*> genes);
		~DNA();

		DNA crossover(DNA partner);

		std::vector<Vector2d*> _genes;

		int size;

	private:
		void createDNA();
	};
}