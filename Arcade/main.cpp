#include <iostream>
#include <SDL.h>"
#include "Vec2D.h"
using namespace std;

int main(int argc, char* []) {
	Vec2D V(3, 7);
	Vec2D result = 3 * V;

	cout << V << endl;
	cout << result << endl;
	return 0;
}