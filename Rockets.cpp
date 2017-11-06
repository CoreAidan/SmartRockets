#include "Rockets.h"
#include <iostream>
#pragma once

CoreAidan::Rockets::Rockets(GameDataRef data) : _data(data){
	_populationSize = 100;

	for (int i = 0; i < _populationSize; i++) {
		_rockets.push_back(new Rocket(_data));
	}
}

void CoreAidan::Rockets::update(Vector2d target){
	for (std::vector<Rocket*>::iterator it = _rockets.begin(); it != _rockets.end(); ++it) {
		(*it)->update(target);

	}
}

void CoreAidan::Rockets::draw(){
	for (std::vector<Rocket*>::iterator it = _rockets.begin(); it != _rockets.end(); ++it) {
		(*it)->draw();
	}
}

void CoreAidan::Rockets::evaluate(Vector2d vector) {
	float maxFit = 0;

	for (std::vector<Rocket*>::iterator it = _rockets.begin(); it != _rockets.end(); ++it) {
		(*it)->calcFitness(vector);

		if ((*it)->fitness > maxFit) {
			maxFit = (*it)->fitness;
		}
	}

	for (std::vector<Rocket*>::iterator it = _rockets.begin(); it != _rockets.end(); ++it) {
		(*it)->fitness /= maxFit;
	}

	_matingpool.clear();

	for (std::vector<Rocket*>::iterator it = _rockets.begin(); it != _rockets.end(); ++it) {
		float n = (*it)->fitness * 100;
		for (int i = 0; i < n; i++) {
			_matingpool.push_back(*it);
		}
	}
	std::cout << "mating pool size: " << _matingpool.size() << std::endl;
}

void CoreAidan::Rockets::selection(){
	std::vector<Rocket*> newRockets;
	for (int i = 0; i < _rockets.size(); i++) {
		DNA parentA = _matingpool.at(rand() % _matingpool.size())->dna;
		DNA parentB = _matingpool.at(rand() % _matingpool.size())->dna;
		DNA child = parentA.crossover(parentB);
		newRockets.push_back(new Rocket(_data, child));
	}
	_rockets = newRockets;
}

bool CoreAidan::Rockets::isDone() {
	std::vector<Rocket*>::iterator it = _rockets.begin();
	return (*it)->isDone();
	
}

