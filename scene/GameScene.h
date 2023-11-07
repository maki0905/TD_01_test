#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

#include "Block.h"
#include "Player.h"
#include "Bubble.h"
#include "EffectManager.h"
#include "IScene.h"

#include <memory>
#include <vector>
#include <optional>

#include <sstream>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// データの読み込み
	/// </summary>
	//void LoadPopData();

	/// <summary>
	/// データの更新
	/// </summary>
	//void UpdataPopCommands();

	/// <summary>
	/// ゴミの発生
	/// </summary>
	void Pop(const Vector3& position, uint32_t type);

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	ViewProjection viewProjection_;

	EffectManager* effectManager_;

	std::unique_ptr<Model> sphere_;

	std::unique_ptr<IScene> sceneRetention_[2];
	// シーンを管理する変数
	uint32_t sceneNo_;
	uint32_t prevSceneNo_;

	// 発生コマンド
	//std::stringstream popCommands_;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	/// <summary>
	/// ゲームシーン用
	std::list<Block*> blocks_;
	std::unique_ptr<Player> player_;
	
	/// </summary>
};
