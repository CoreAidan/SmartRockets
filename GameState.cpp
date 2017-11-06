#pragma once

#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"

#include <iostream>

namespace CoreAidan
{
	GameState::GameState(GameDataRef data) : _data(data)
	{
		_generation = 1;
		std::cout << "generation:  " << _generation << std::endl; 
	}

	void GameState::Init()
	{
		//this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		//_background.setTexture(this->_data->assets.GetTexture("Game Background"));

		_target.x = SCREEN_WIDTH / 2;
		_target.y = 50;

		rockets = new Rockets(_data);
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void GameState::Update(float dt)
	{
		rockets->update(_target);

		if (rockets->isDone()) {
			_generation++;
			std::cout << "generation:  "<<_generation << std::endl;
			rockets->evaluate(_target);
			rockets->selection();
		}
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		//this->_data->window.draw(this->_background);

		sf::CircleShape target(16);
		target.setPosition(_target.x, _target.y);

		this->_data->window.draw(target);

		rockets->draw();

		this->_data->window.display();
	}
}