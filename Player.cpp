#include "Player.h"

void Player::Initialize(/*Model* model*/) { 
	model_ = Model::Create();

	input_ = Input::GetInstance();

	worldTransform_.Initialize();

}

void Player::Update() { 

	if (input_->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= moveSpeed_;
		worldTransform_.translation_.y += moveSpeed_;
	
	}
	if (input_->PushKey(DIK_D)) {
		worldTransform_.translation_.x += moveSpeed_;
		worldTransform_.translation_.y += moveSpeed_;
	}
	
	worldTransform_.UpdateMatrix(); 

}

void Player::Draw(ViewProjection& viewProjection) { 
	model_->Draw(worldTransform_, viewProjection); 
}
