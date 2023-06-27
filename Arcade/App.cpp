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
#include <cassert>

App& App::Singleton()
{
	static App theApp;
	return theApp;
}
bool App::Init(uint32_t width, uint32_t height, uint32_t mag) {
	mnoptrWindow = mScreen.Init(width, height, mag);
	std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();
	PushScene(std::move(arcadeScene));
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

			mInputController.Init([&running](uint32_t dt, InputState state) {
				running = false;
			});

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

			mInputController.Update(dt);
			Scene* topScene = App::TopScene();
			assert(topScene && "there is no scene");
			if (topScene) {
				while (accumulator >= dt) {
					topScene->Update(dt);
					//d::cout << "delta time " << dt << std::endl;
					accumulator -= dt;
				}
				topScene->Draw(mScreen);
			}
			

			
			mScreen.SwapScreen();
		}

	}
	
}

void App::PushScene(std::unique_ptr<Scene> scene) {
	assert(scene && "dont push null ptr");
	if (scene) {
		scene->Init();
		mInputController.SetGameController(scene->GetGameController());
		mSceneStack.emplace_back(std::move(scene));
		SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
	}
	
}
void App::PopScene() {
	if (mSceneStack.size() > 1) {
		mSceneStack.pop_back();
	}

	if (TopScene()) {
		mInputController.SetGameController(TopScene()->GetGameController());
		SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
	}
	
}
Scene* App::TopScene() {
	if (mSceneStack.empty()) {
		return nullptr;
	}

	return mSceneStack.back().get();
}
