#pragma once

#include "TextureManager.h"
#include "MathFunction.h"
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Sprite.h"



class Bubble {
public:
	struct SpriteParameter {
		uint32_t textureHandle;
		Vector2 position;
		Vector4 color;
		Vector2 anchorpoint;
		Vector2 size;
	};


	void Initialize(Vector3 position);
	

	void Update();

	void Draw(/*ViewProjection& viewProjection*/);

	bool IsDead() { return isDead_; }


private:
	Model* model_shpere_;
	Sprite* sprite_;
	WorldTransform worldTransform_;
	Vector2 move_;
	SpriteParameter spriteParameter_;
	bool isDead_ = false;


};
