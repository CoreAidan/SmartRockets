#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2d.h"
#include"DEFINITIONS.h"
#include "Game.h"
#include "DNA.h"

namespace CoreAidan {
	class Rocket {
	public:
		Rocket(GameDataRef data);
		Rocket(GameDataRef data, DNA newDNA);
		~Rocket();
		void applyForce(Vector2d force);
		void update(Vector2d target);
		void draw();

		float calcFitness(Vector2d vector);
		float distance(float x, float y);

		bool isDone();
		void completed(Vector2d target);

		double fitness;
		int count;
		DNA dna;

	private:
		bool _completed = false;

		GameDataRef _data;
		
		Vector2d _target;
		Vector2d _position;
		Vector2d _velocity;
		Vector2d _acceleration;

	};
}
