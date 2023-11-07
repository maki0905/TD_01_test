#include "EffectManager.h"

#include "WinApp.h"


void EffectManager::Initialize(
    Effect effect, uint32_t count, 
	const WorldTransform& worldTransform, 
	const ViewProjection& viewProjection) { 
	if (effect == Effect::kBubble) {
		Vector3 position2D = {
		    worldTransform.matWorld_.m[3][0], 
			worldTransform.matWorld_.m[3][1],
		    worldTransform.matWorld_.m[3][2]
		};

		// ビューポート行列
		Matrix4x4 matViewport =
		    MakeViewportMatrix(0, 0, WinApp::kWindowWidth, WinApp::kWindowHeight, 0, 1);
		// ビュー行列とプロジェクション行列、ビューポート行列を合成する
		Matrix4x4 matViewProjectionViewport =
		    Multiply(Multiply(viewProjection.matView, viewProjection.matProjection), matViewport);
		// ワールド→スクリーン座標変換(ここで3Dから2Dになる)
		position2D = Transform(position2D, matViewProjectionViewport);

		for (uint32_t index = 0; index < count; index++) {
			Bubble* newBubble = new Bubble();
			newBubble->Initialize(position2D);
			bubbles_.push_back(newBubble);
		}
	
	} 


}

void EffectManager::Update() { 
	for (auto bubble : bubbles_) {
		bubble->Update();
	}
	bubbles_.remove_if([](Bubble* bubble) {
		if (bubble->IsDead()) {
			delete bubble;
			return true;
		}
		return false;
	});

}

void EffectManager::Draw() { 
	for (auto bubble : bubbles_) {
		bubble->Draw();
	}
}
