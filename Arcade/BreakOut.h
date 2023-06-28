#pragma once
#ifndef BREAKOUT_H_
#define BREAKOUT_H_
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"

class BreakOut: public Game
{
	public:
		virtual void Init(GameController& controller) override;
		virtual void Update(uint32_t dt) override;
		virtual void Draw(Screen& screen) override;
		virtual std::string &GetName() const override;

	private:
		void ResetGame();
		Paddle mPaddle;
		Ball mBall;
};

#endif // !1



