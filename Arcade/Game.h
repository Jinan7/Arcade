#pragma once
#ifndef GAME_H_
#define GAME_H_
#include <stdint.h>
#include <string>

class GameController;
class Screen;

class Game
{
public:
	virtual ~Game(){}
	virtual void Init(GameController& controller) = 0;
	virtual void Update(uint32_t dt) = 0;
	virtual void Draw(Screen& screen) = 0;
	virtual std::string& GetName() const = 0;
};

#endif // !GAME_H_



