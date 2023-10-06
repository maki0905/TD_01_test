#pragma once

#include "Input.h"
#include "MathFunction.h"
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

#include <vector>
#include <optional>
#include <list>

#include <sstream>


class Block {
public:
	void Initialize(Model* model, uint32_t textureHandle, const Vector3& position, uint32_t type);

	void Update();

	void Draw(ViewProjection& viewProjection);
 
private:
	WorldTransform worldTransform_;
	
	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0;
	uint32_t type_;

};
