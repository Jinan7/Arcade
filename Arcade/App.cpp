#include "App.h"
#include <iostream>
#include <SDL.h>"
#include "Vec2D.h"
#include "Color.h"
#include "Screen.h"
#include "Line2D.h"
#include "Triangle.h"
#include  "AARectangle.h"
#include "Circle.h"

App& App::Singleton()
{
	static App theApp;
	return theApp;
}
bool App::Init(uint32_t width, uint32_t height, uint32_t mag) {
	mnoptrWindow = mScreen.Init(width, height, mag);
	return mnoptrWindow != nullptr;
}
void App::Run() {
	if (mnoptrWindow) {
	
		Line2D line = { Vec2D(0,0), Vec2D(mScreen.Width(), mScreen.Height())};
		AARectangle rect = { Vec2D(mScreen.Width() / 2 - 25, mScreen.Height() / 2 - 25), 50, 50 };
		Triangle triangle = { Vec2D(60, 10), Vec2D(10, 110), Vec2D(110,110) };
		Circle circle = { Vec2D(mScreen.Width() / 2 + 50, mScreen.Height() / 2 + 50), 50 };

		mScreen.Draw(triangle, Color::White(), true, Color::Red());
		mScreen.Draw(circle, Color::Blue(), true, Color::Red());
		mScreen.SwapScreen();

		SDL_Event sdlEvent;
		bool running = true;

		while (running) {
			while (SDL_PollEvent(&sdlEvent)) {
				switch (sdlEvent.type) {
				case SDL_QUIT:
					running = false;
					break;
				}
			}
		}

	}
	
}
