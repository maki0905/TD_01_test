#pragma once

enum SCENE {TITLE, PLAY};

class IScene {
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void ForeDraw() = 0;
	virtual void Draw() = 0;
	virtual void BackDraw() = 0;
	virtual void Release() = 0;
	int GetSceneNo() { return sceneNo_; }

protected:
	static int sceneNo_;
};
