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
#include "ArcadeScene.h"
#include <memory>

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
	
		


		SDL_Event sdlEvent;
		bool running = true;

		uint32_t lastTick = SDL_GetTicks();
		uint32_t currentTick = lastTick;
		uint32_t dt = 10;
		uint32_t accumulator = 0;

		std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();
		arcadeScene->Init();

		while (running) {
			currentTick = SDL_GetTicks();
			uint32_t frameTime = currentTick - lastTick;
			if (frameTime > 300)
			{
				frameTime = 300;
			}
			lastTick = currentTick;
			accumulator += frameTime;

			while (SDL_PollEvent(&sdlEvent)) {
				switch (sdlEvent.type) {
				case SDL_QUIT:
					running = false;
					break;
				}
			}
			while (accumulator >= dt) {
				arcadeScene->Update(dt);
				std::cout << "delta time " << dt << std::endl;
				accumulator -= dt;
			}

			arcadeScene->Draw(mScreen);
			mScreen.SwapScreen();
		}

	}
	
}
