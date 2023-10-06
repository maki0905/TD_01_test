#pragma once

#include "Input.h"
#include "MathFunction.h"
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

#include <vector>
#include <optional>
#include <list>

class Player {
public:
	void Initialize(/*Model* model*/);

	void Update();

	void Draw(ViewProjection& viewProjection);


private:
	WorldTransform worldTransform_;

	Input* input_ = nullptr;
	Model* model_ = nullptr;

	const float moveSpeed_ = 0.2f;

};
