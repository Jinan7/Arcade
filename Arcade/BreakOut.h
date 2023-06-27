#pragma once
#ifndef BREAKOUT_H_
#define BREAKOUT_H_
#include "Game.h"

class BreakOut: public Game
{
	public:
		virtual void Init(GameController& controller) override;
		virtual void Update(uint32_t dt) override;
		virtual void Draw(Screen& screen) override;
		virtual std::string GetName() const override;
};

#endif // !1



