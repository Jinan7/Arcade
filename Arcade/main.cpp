#include <iostream>
#include <SDL.h>"
#include "Vec2D.h"
#include "Color.h"
#include "ScreenBuffer.h"
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

	SDL_Surface* noptrWindowSurface = SDL_GetWindowSurface(optrWindow);

	SDL_PixelFormat* pixelFormat = noptrWindowSurface->format;
	Color::InitColorFormat(pixelFormat);
	Color c(255, 0, 0, 0);

	ScreenBuffer screenBuffer;
	screenBuffer.Init(pixelFormat->format, noptrWindowSurface->w, noptrWindowSurface->h);
	screenBuffer.SetPixel(Color::Red(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	SDL_BlitSurface(screenBuffer.GetSurface(), nullptr, noptrWindowSurface, nullptr);
	std::cout << "the window pixel format is: " << SDL_GetPixelFormatName(pixelFormat->format);

	uint32_t color = 0xFF0000;

	//SetPixel(noptrWindowSurface, c.GetPixelColor(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	
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

