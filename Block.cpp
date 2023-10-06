#include "Block.h"

#include <assert.h>

#include "ImGuiManager.h"

#include <fstream>
#include <string>

void Block::Initialize(
    Model* model, uint32_t textureHandle, const Vector3& position, uint32_t type) { 
	assert(model);
	model_ = model;
	type_ = type;
	textureHandle_ = textureHandle;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.UpdateMatrix();
}

void Block::Update() { 

	worldTransform_.UpdateMatrix();
	
	ImGui::Begin("debug");
	
	ImGui::End();

}

void Block::Draw(ViewProjection& viewProjection) { 
	model_->Draw(worldTransform_, viewProjection);

}

