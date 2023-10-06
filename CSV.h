#pragma once

#include <sstream>
#include <vector>

#include "Vector3.h"

class CSV {

public:
	struct Pop {
		Vector3 position;
		uint32_t type;
	};

public:
	/// <summary>
	/// データの読み込み
	/// </summary>
	void LoadPopData();

	/// <summary>
	/// データの更新
	/// </summary>
	std::vector<Pop> UpdataPopCommands();

private:
	// 発生コマンド
	std::stringstream popCommands_;
};
