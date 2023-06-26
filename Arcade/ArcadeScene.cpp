#include "ArcadeScene.h"
#include "Color.h"
#include "Screen.h"
#include "Line2D.h"
#include "Triangle.h"
#include  "AARectangle.h"
#include "Circle.h"


ArcadeScene::ArcadeScene() {

}
void ArcadeScene::Init(){

}
void ArcadeScene::Update(uint32_t dt) {

}
void ArcadeScene::Draw(Screen& theScreen) {
	Line2D line = { Vec2D(0,0), Vec2D(theScreen.Width(), theScreen.Height()) };
	AARectangle rect = { Vec2D(theScreen.Width() / 2 - 25, theScreen.Height() / 2 - 25), 50, 50 };
	Triangle triangle = { Vec2D(60, 10), Vec2D(10, 110), Vec2D(110,110) };
	Circle circle = { Vec2D(theScreen.Width() / 2 + 50, theScreen.Height() / 2 + 50), 50 };

	theScreen.Draw(triangle, Color::White(), true, Color::Red());
	theScreen.Draw(circle, Color::Blue(), true, Color::Red());

}
const std::string& ArcadeScene::GetSceneName() const {
	return "Arcade Scene";
}


std::unique_ptr<Scene> ArcadeScene::GetScene(eGame game) {
	switch (game)
	{
	case TETRIS:
		break;
	case BREAK_OUT:
		break;
	case ASTEROIDS:
		break;
	case PACMAN:
		break;
	case NUM_GAMES:
		break;
	default:
		break;
	}
	return nullptr;
}

