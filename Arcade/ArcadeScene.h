#ifndef ARCADESCENE_H_
#define ARCADESCENE_H_
#include "Scene.h"
#include <memory>

enum eGame { TETRIS = 0, BREAK_OUT, ASTEROIDS, PACMAN, NUM_GAMES };

class ArcadeScene : public Scene
{
public:
	ArcadeScene();
	virtual void Init() override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& theScreen) override;
	virtual const std::string& GetSceneName() const override;

private:
	std::unique_ptr<Scene> GetScene(eGame game);



};
#endif // !1