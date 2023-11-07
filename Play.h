#pragma once
#include "IScene.h"
class Play : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void ForeDraw() override;
	void Draw() override;
	void BackDraw() override;
	void Release() override;

private:
	
};
