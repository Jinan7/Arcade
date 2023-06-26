#include <iostream>
#include <SDL.h>"
#include "Vec2D.h"
#include "Color.h"
#include "Screen.h"
#include "Line2D.h"
#include "Triangle.h"
#include  "AARectangle.h"

using namespace std;

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 2;


int main(int argc, char* []) {
	
	Screen theScreen;
	theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
	Line2D line = { Vec2D(0,0), Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT) };
	AARectangle rect = { Vec2D(SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT / 2 - 25), 50, 50 };
	Triangle triangle = { Vec2D(60, 10), Vec2D(10, 110), Vec2D(110,110) };
	theScreen.Draw(triangle, Color::White());
	theScreen.Draw(rect, Color::Blue());
	theScreen.SwapScreen();

	//ScreenBuffer screenBuffer;
	//screenBuffer.Init(pixelFormat->format, noptrWindowSurface->w, noptrWindowSurface->h);
	//screenBuffer.SetPixel(Color::Red(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	//SDL_BlitSurface(screenBuffer.GetSurface(), nullptr, noptrWindowSurface, nullptr);
	//std::cout << "the window pixel format is: " << SDL_GetPixelFormatName(pixelFormat->format);

	//uint32_t color = 0xFF0000;

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
	

	
	return 0;
}

