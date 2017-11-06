#include "Rocket.h"
#include <ctime>
#include <iostream>

namespace CoreAidan {
	Rocket::Rocket(GameDataRef data) :  _data(data){
		_position.x = SCREEN_WIDTH / 2;
		_position.y = SCREEN_HEIGHT - 25;

		//_velocity.x = -3 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (3 - -3)));
		//_velocity.y = -3 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 - -3)));

		count = 0;
		
	}

	Rocket::Rocket(GameDataRef data, DNA newDNA) : _data(data){
		dna = newDNA;

		_position.x = SCREEN_WIDTH / 2;
		_position.y = SCREEN_HEIGHT - 25;

		//_velocity.x = -3 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (3 - -3)));
		//_velocity.y = -3 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 - -3)));

		count = 0;
	}

	Rocket::~Rocket() {
	}

	void Rocket::applyForce(Vector2d force) {
		_acceleration = _acceleration + force;
	}

	void Rocket::update(Vector2d target) {
		//std::cout << "count: " << _count << std::endl;
		applyForce(*dna._genes.at(count));

		if (count < dna.size - 1) {
			count++;
		}
		
		completed(target);

		if (!_completed) {
			_velocity = _velocity + _acceleration;
			_position = _position + _velocity;
			_acceleration = _acceleration * 0.0f;
		}
		
	}

	void Rocket::draw() {
		sf::RectangleShape rocketShape(sf::Vector2f(5, 25));
		rocketShape.setPosition(_position.x, _position.y);
		rocketShape.setFillColor(sf::Color(0, 255, 0, 150));
		rocketShape.rotate(_velocity.direction());

		_data->window.draw(rocketShape);
	}



	float Rocket::calcFitness(Vector2d vector) {
		if (_completed) {
			fitness *= 10;
		}
		else {
			fitness = 1 / distance(vector.x, vector.y);
		}
		
		return fitness;
	}

	float Rocket::distance(float x, float y){
		float deltaX = x - _position.x;
		float deltaY = y - _position.y;
		return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
	}

	bool Rocket::isDone(){
		//std::cout << "dna size: " << dna.size << std::endl;
		return count == dna.size - 1;
	}
	void Rocket::completed(Vector2d target){
		if (distance(target.x, target.y) < 10) {
			_completed = true;
			_position.x = target.x;
			_position.y = target.y;
		}
	}
}