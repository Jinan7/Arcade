#include "BreakOut.h"
#include <iostream>
#include "GameController.h"
#include "App.h"


void BreakOut::Init(GameController& controller)
{
	controller.ClearAll();
	ResetGame();
	ButtonAction leftKeyAction;
	leftKeyAction.key = GameController::LeftKey();
	leftKeyAction.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state)) {
			mPaddle.SetMovementDirection(PaddleDirection::LEFT);
		}
		else
		{
			mPaddle.UnsetMovementDirection(PaddleDirection::LEFT);

		}
	};
	controller.AddInputActionForKey(leftKeyAction);

	ButtonAction rightKeyAction;
	rightKeyAction.key = GameController::RightKey();
	rightKeyAction.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state)) {
			mPaddle.SetMovementDirection(PaddleDirection::RIGHT);
		}
		else
		{
			mPaddle.UnsetMovementDirection(PaddleDirection::RIGHT);

		}
	};
	controller.AddInputActionForKey(rightKeyAction);

}
void BreakOut::Update(uint32_t dt)
{
	mBall.Update(dt);
	mPaddle.Update(dt);
}
void BreakOut::Draw(Screen& screen)
{
	mBall.Draw(screen);
	mPaddle.Draw(screen);
}
std::string &BreakOut::GetName() const
{

	static std::string name = "Break Out!";
	return name;
	
}
void BreakOut::ResetGame()
{
	AARectangle paddleRect = {Vec2D(App::Singleton().Width()/2 - 50/2, App::Singleton().Height() - 3*10), 50, 10};
	AARectangle levelBoundary = { Vec2D::Zero, App::Singleton().Width(), App::Singleton().Height() };
	mPaddle.Init(paddleRect, levelBoundary);
	mBall.MoveTo(Vec2D(App::Singleton().Width() / 2, App::Singleton().Height() / 2));
}

