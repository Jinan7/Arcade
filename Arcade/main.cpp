#include <iostream>
#include <SDL.h>"
#include "App.h"
using namespace std;

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 2;


int main(int argc, char* []) {
	
	if (App::Singleton().Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION))
	{
		App::Singleton().Run();
	}

	return 0;
}

