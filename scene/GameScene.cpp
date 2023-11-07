#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

#include <fstream>
#include <string>

#include "CSV.h"
#include "Title.h"
#include "Play.h"

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	effectManager_ = new EffectManager;

	sphere_.reset(Model::CreateFromOBJ("sphere", true));

	// CSVからデータの読み込み
	std::unique_ptr<CSV> csv = std::make_unique<CSV>();
	csv->LoadPopData();
	std::vector<CSV::Pop> pops = csv->UpdataPopCommands();
	// 読み込んだデータから生成
	for (CSV::Pop pop : pops) {
		Pop(pop.position, pop.type);
	}

	player_ = std::make_unique<Player>();
	player_->Initialize(effectManager_);
	

	viewProjection_.farZ = 10000.0f;
	viewProjection_.Initialize();

	// シーン
	// sceneRetention_[SCENE::TITLE] = std::make_unique<TitleScene>();
	sceneRetention_[SCENE::TITLE] = std::make_unique<Title>();
	sceneRetention_[SCENE::PLAY] = std::make_unique<Play>();
	sceneNo_ = SCENE::TITLE;
	sceneRetention_[sceneNo_]->Initialize();

}

void GameScene::Update() { 
	// シーンのチェック
	prevSceneNo_ = sceneNo_;
	sceneNo_ = sceneRetention_[sceneNo_]->GetSceneNo();

	// シーン変更チェック
	if (prevSceneNo_ != sceneNo_) {
		sceneRetention_[sceneNo_]->Initialize();
	}

	sceneRetention_[sceneNo_]->Update();
	player_->Update();
	effectManager_->Update();
	if (input_->PushKey(DIK_SPACE)) {
		for (Block* block : blocks_) {
			delete block;
		}
		blocks_.clear();
	}
	if (input_->PushKey(DIK_P)) {
		// CSVからデータの読み込み
		std::unique_ptr<CSV> csv = std::make_unique<CSV>();
		csv->LoadPopData();
		std::vector<CSV::Pop> pops = csv->UpdataPopCommands();
		// 読み込んだデータから生成
		for (CSV::Pop pop : pops) {
			Pop(pop.position, pop.type);
		}
	}
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	for (Block* block : blocks_) {
		block->Draw(viewProjection_);
	
	}
	player_->Draw(viewProjection_);
	sceneRetention_[sceneNo_]->Draw();
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	effectManager_->Draw();
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}



void GameScene::Pop(const Vector3& position, uint32_t type) {
	// ゴミの発生
	Block* newBlock = new Block();

	// ファイル名を指定してテクスチャを読み込む
	//textureHandle_ = TextureManager::Load("")

	// 初期化
	newBlock->Initialize(sphere_.get(), textureHandle_, position, type);

	// 登録
	blocks_.push_back(newBlock);

}
