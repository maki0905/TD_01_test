#include "CSV.h"

#include <cassert>
#include <fstream>
#include <string>


void CSV::LoadPopData() {
	// ファイルを開く
	std::ifstream file;
	file.open("Resources/Pop.csv");
	assert(file.is_open());

	// ファイルの内容を文字列ストリームにコピー
	popCommands_ << file.rdbuf();

	// ファイルを閉じる
	file.close();
}

std::vector<CSV::Pop> CSV::UpdataPopCommands() {
	// 1行分の文字列を入れる変数
	std::string line;

	std::vector<CSV::Pop> result;
	Pop pop;

	// コマンド実行ループ
	while (getline(popCommands_, line)) {
		// 1行分の文字列をストリームに変更して解析しやすくする
		std::istringstream line_stream(line);

		std::string word;
		// ,区切りで行の先頭文字列を取得
		getline(line_stream, word, ',');

		// "//"から始まる行はコメント
		if (word.find("//") == 0) {
			// コメント行を飛ばす
			continue;
		}

		// Positionコマンド
		if (word.find("Position") == 0) {
			// x座標
			getline(line_stream, word, ',');
			pop.position.x = (float)std::atof(word.c_str());

			// y座標
			getline(line_stream, word, ',');
			pop.position.y = (float)std::atof(word.c_str());

			// z座標
			getline(line_stream, word, ',');
			pop.position.z = (float)std::atof(word.c_str());
		}

		pop.type = 999;

		// Typeコマンド
		if (word.find("Type") == 0) {
			// type(0~2)
			getline(line_stream, word, ',');
			pop.type = (uint32_t)std::atof(word.c_str());
		}

		// ここに発生の処理
		if (pop.type != 999) {
			result.push_back(pop);
		}
	}
	return result;
}
