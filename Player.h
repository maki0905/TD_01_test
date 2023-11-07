#pragma once

#include "Input.h"
#include "MathFunction.h"
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

#include "EffectManager.h"

#include <vector>
#include <optional>
#include <list>

class Player {
public:
	void Initialize(EffectManager* effectManager);

	void Update();

	void Draw(ViewProjection& viewProjection);


private:
	WorldTransform worldTransform_;
	ViewProjection viewProjection_;
	EffectManager* effectManager_;
	Input* input_ = nullptr;
	Model* model_ = nullptr;

	const float moveSpeed_ = 0.2f;

};
