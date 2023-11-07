#include "Bubble.h"

#include <cstdlib>
#include <cassert>

void Bubble::Initialize(Vector3 position) { 
	//assert(model); 
	
	worldTransform_.Initialize();

	spriteParameter_.textureHandle = TextureManager::Load("bubble.png");
	spriteParameter_.position = {position.x, position.y};
	spriteParameter_.color = {1, 1, 1, 1};
	spriteParameter_.anchorpoint = {0.5f, 0.5f};
	sprite_ = Sprite::Create(
	    spriteParameter_.textureHandle, spriteParameter_.position, spriteParameter_.color,
	    spriteParameter_.anchorpoint);
	sprite_->Initialize();
	spriteParameter_.size = sprite_->GetSize();
	move_ = {float(rand() % 6 - 3), float(rand() % 5 + 1)};
}

void Bubble::Update() {
	// 移動
	//spriteParameter_.position.x += move_.x;
	move_.x *= -1;
	spriteParameter_.position.y -= move_.y;
	
	// サイズ
	spriteParameter_.size.x -= 0.5f;
	spriteParameter_.size.y -= 0.5f;
	if (spriteParameter_.size.x == 0.0f) {
		isDead_ = true;
	}

	// 更新
	sprite_->SetPosition(spriteParameter_.position);
	sprite_->SetSize(spriteParameter_.size);
	/*if (spriteParameter_.size.x != sprite_->GetSize().x) {
		sprite_->SetSize(spriteParameter_.size);
	}*/
}

void Bubble::Draw(/*ViewProjection& viewProjection*/) { 
	
	sprite_->Draw(); 

}
