#pragma once
#ifndef PADDLE_H_
#define PADDLE_H_
#include "Excluder.h"
#include <stdint.h>

class Screen;
enum PaddleDirection
{
	LEFT = 1 << 0,
	RIGHT = 1 << 1,
};

class Paddle: public Excluder
{
	public:
		static const uint32_t PADDLE_WIDTH = 100;
		static const uint32_t PADDLE_HEIGHT = 30;
		void Init(const AARectangle& rect, const AARectangle& boundary);
		void Update(uint32_t dt);
		void Draw(Screen& screen);
		inline bool IsMovingLeft() const { return mDirection == PaddleDirection::LEFT; }
		inline bool IsMovingRight() const { return mDirection == PaddleDirection::RIGHT; }

		inline void SetMovementDirection(PaddleDirection dir) { mDirection |= dir; }
		inline void UnsetMovementDirection(PaddleDirection dir) { mDirection &= ~dir; }
		inline void StopMovement() { mDirection = 0; }
	private:
		uint32_t mDirection;
		const float VELOCITY = 100.0f;
		AARectangle mBoundary; 


};
#endif // !PADDLE_H_



