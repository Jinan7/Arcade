#include <iostream>
#include <SDL.h>"
#include "Vec2D.h"
using namespace std;

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
int main(int argc, char* []) {
	
	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "error" << endl;
		return 1;
	}

	SDL_Window* optrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (optrWindow == nullptr) {
		std::cout << "Could not create window " << SDL_GetError() << endl;
	}

	
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
	

	SDL_DestroyWindow(optrWindow);
	SDL_Quit();
	return 0;
}