#pragma once
#include "IScene.h"
#include "ViewProjection.h"

class Title : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void ForeDraw() override;
	void Draw() override;
	void BackDraw() override;
	void Release() override;

private:
	
	ViewProjection viewProjection_;

	
};
