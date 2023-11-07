#include "Player.h"

void Player::Initialize(EffectManager* effectManager) { 
	model_ = Model::Create();

	input_ = Input::GetInstance();

	worldTransform_.Initialize();
	viewProjection_.Initialize();
	effectManager_ = effectManager;

}

void Player::Update() { 
	

	if (input_->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= moveSpeed_;
		effectManager_->Initialize(
		    EffectManager::Effect::kBubble, 1, worldTransform_, viewProjection_);
	
	}
	if (input_->PushKey(DIK_D)) {
		worldTransform_.translation_.x += moveSpeed_;
		effectManager_->Initialize(
		    EffectManager::Effect::kBubble, 1, worldTransform_, viewProjection_);
	}
	if (input_->PushKey(DIK_S)) {
		worldTransform_.translation_.y -= moveSpeed_;
		effectManager_->Initialize(
		    EffectManager::Effect::kBubble, 1, worldTransform_, viewProjection_);
	}
	if (input_->PushKey(DIK_W)) {
		worldTransform_.translation_.y += moveSpeed_;
		effectManager_->Initialize(
		    EffectManager::Effect::kBubble, 1, worldTransform_, viewProjection_);
	}
	worldTransform_.UpdateMatrix(); 

}

void Player::Draw(ViewProjection& viewProjection) { 
	model_->Draw(worldTransform_, viewProjection); 
}
