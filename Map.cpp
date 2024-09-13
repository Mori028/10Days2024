#include "Map.h"
#include "Input.h"
#include <random>

Map::Map() {}

Map::~Map() {}

void Map::Initialize()
{
	// 画像の割り当て
	BLOCK_TEXTURE = LoadGraph("Resource/Block.png", TRUE);
	MOVE_BLOCK_TEXTURE = LoadGraph("Resource/1.png", TRUE);
	DAMAGE_BLOCK_TEXTURE = LoadGraph("Resource/DamageBlock.png", TRUE);
	GOAL_BLOCK_TEXTURE = LoadGraph("Resource/goal.png", TRUE);
	BREAK_BLOCK_TEXTURE = LoadGraph("Resource/Block4.png", TRUE);

	// マップの数
	for (int i = 0; i < maxStage_; i++) {
		if (i == 0) {
			mapCount[i].x_ = sizeof(map[0][0]) / sizeof(map[0][0][0]);
			mapCount[i].y_ = sizeof(map[0]) / sizeof(map[0][0]);
		}else if (i == 1) {
			mapCount[i].x_ = sizeof(map[1][0]) / sizeof(map[1][0][0]);
			mapCount[i].y_ = sizeof(map[1]) / sizeof(map[1][0]);
		}else if (i == 2) {
			mapCount[i].x_ = sizeof(map[2][0]) / sizeof(map[2][0][0]);
			mapCount[i].y_ = sizeof(map[2]) / sizeof(map[2][0]);
		}else if (i == 3) {
			mapCount[i].x_ = sizeof(map[3][0]) / sizeof(map[3][0][0]);
			mapCount[i].y_ = sizeof(map[3]) / sizeof(map[3][0]);
		}else if (i == 4) {
			mapCount[i].x_ = sizeof(map[4][0]) / sizeof(map[4][0][0]);
			mapCount[i].y_ = sizeof(map[4]) / sizeof(map[4][0]);
		}
	}

	// マップチップの描画
	for (int i = 0; i < maxStage_; i++) {
		for (int y = 0; y < mapCount[i].y_; y++) {
			for (int x = 0; x < mapCount[i].x_; x++) {
				block[i] = { static_cast<float>(x * blockSize), static_cast<float>(y * blockSize) };

				blockPosition[i][y][x] = { block[i].x_, block[i].y_ };
			}
		}
	}
}

void Map::Update()
{
	Map::Move();
	
	Map::Shake();
}

void Map::Draw()
{
	// マップチップの描画
	switch (stage_) {
	case STAGE_1:
		
		for (int y = 0; y < mapCount[0].y_; y++) {
			for (int x = 0; x < mapCount[0].x_; x++) {
				block[0] = {static_cast<float>(x * blockSize), static_cast<float>(y * blockSize)};

				blockPosition[0][y][x] = { block[0].x_, block[0].y_};

				if (map[0][y][x] == BLOCK) {
					DrawGraph(block[0].x_, block[0].y_ - mapChipMoveY_, BLOCK_TEXTURE, TRUE);
				}
				if (map[0][y][x] == MOVE_BLOCK) {
					DrawGraph(block[0].x_, block[0].y_ + addSpeed - mapChipMoveY_, MOVE_BLOCK_TEXTURE, TRUE);
				}
				if (map[0][y][x] == DAMAGE_BLOCK) {
					DrawGraph(block[0].x_ + addShakeX_, block[0].y_ + addShakeY_ - mapChipMoveY_, DAMAGE_BLOCK_TEXTURE, TRUE);
				}
				if (map[0][y][x] == GOAL_BLOCK) {
					DrawGraph(block[0].x_, block[0].y_ - mapChipMoveY_, GOAL_BLOCK_TEXTURE, TRUE);
				}
				if (map[0][y][x] == BREAK_BLOCK) {
					DrawGraph(block[0].x_, block[0].y_ - mapChipMoveY_, BREAK_BLOCK_TEXTURE, TRUE);
				}
			}
		}

		break;

	case STAGE_2:
		
		for (int y = 0; y < mapCount[1].y_; y++) {
			for (int x = 0; x < mapCount[1].x_; x++) {
				block[1] = {static_cast<float>(x * blockSize), static_cast<float>(y * blockSize)};

				blockPosition[1][y][x] = { block[1].x_, block[1].y_};

				if (map[1][y][x] == BLOCK) {
					DrawGraph(block[1].x_, block[1].y_ - mapChipMoveY_, BLOCK_TEXTURE, TRUE);
				}
				if (map[1][y][x] == MOVE_BLOCK) {
					DrawGraph(block[1].x_, block[1].y_ + addSpeed - mapChipMoveY_, MOVE_BLOCK_TEXTURE, TRUE);
				}
				if (map[1][y][x] == DAMAGE_BLOCK) {
					DrawGraph(block[1].x_ + addShakeX_, block[1].y_ + addShakeY_ - mapChipMoveY_, DAMAGE_BLOCK_TEXTURE, TRUE);
				}
				if (map[1][y][x] == GOAL_BLOCK) {
					DrawGraph(block[1].x_, block[1].y_ - mapChipMoveY_, GOAL_BLOCK_TEXTURE, TRUE);
				}
				if (map[1][y][x] == BREAK_BLOCK) {
					DrawGraph(block[1].x_, block[1].y_ - mapChipMoveY_, BREAK_BLOCK_TEXTURE, TRUE);
				}
			}
		}

		break;

	case STAGE_3:

		for (int y = 0; y < mapCount[2].y_; y++) {
			for (int x = 0; x < mapCount[2].x_; x++) {
				block[2] = {static_cast<float>(x * blockSize), static_cast<float>(y * blockSize)};

				blockPosition[2][y][x] = { block[2].x_, block[2].y_};

				if (map[2][y][x] == BLOCK) {
					DrawGraph(block[2].x_, block[2].y_ - mapChipMoveY_, BLOCK_TEXTURE, TRUE);
				}
				if (map[2][y][x] == MOVE_BLOCK) {
					DrawGraph(block[2].x_, block[2].y_ + addSpeed - mapChipMoveY_, MOVE_BLOCK_TEXTURE, TRUE);
				}
				if (map[2][y][x] == DAMAGE_BLOCK) {
					DrawGraph(block[2].x_ + addShakeX_, block[2].y_ + addShakeY_ - mapChipMoveY_, DAMAGE_BLOCK_TEXTURE, TRUE);
				}
				if (map[2][y][x] == GOAL_BLOCK) {
					DrawGraph(block[2].x_, block[2].y_ - mapChipMoveY_, GOAL_BLOCK_TEXTURE, TRUE);
				}
				if (map[2][y][x] == BREAK_BLOCK) {
					DrawGraph(block[2].x_, block[2].y_ - mapChipMoveY_, BREAK_BLOCK_TEXTURE, TRUE);
				}
			}
		}

		break;

	case STAGE_4:

		for (int y = 0; y < mapCount[3].y_; y++) {
			for (int x = 0; x < mapCount[3].x_; x++) {
				block[3] = {static_cast<float>(x * blockSize), static_cast<float>(y * blockSize)};

				blockPosition[3][y][x] = { block[3].x_, block[3].y_};

				if (map[3][y][x] == BLOCK) {
					DrawGraph(block[3].x_, block[3].y_ - mapChipMoveY_, BLOCK_TEXTURE, TRUE);
				}
				if (map[3][y][x] == MOVE_BLOCK) {
					DrawGraph(block[3].x_, block[3].y_ + addSpeed - mapChipMoveY_, MOVE_BLOCK_TEXTURE, TRUE);
				}
				if (map[3][y][x] == DAMAGE_BLOCK) {
					DrawGraph(block[3].x_ + addShakeX_, block[3].y_ + addShakeY_ - mapChipMoveY_, DAMAGE_BLOCK_TEXTURE, TRUE);
				}
				if (map[3][y][x] == GOAL_BLOCK) {
					DrawGraph(block[3].x_, block[3].y_ - mapChipMoveY_, GOAL_BLOCK_TEXTURE, TRUE);
				}
				if (map[3][y][x] == BREAK_BLOCK) {
					DrawGraph(block[3].x_, block[3].y_ - mapChipMoveY_, BREAK_BLOCK_TEXTURE, TRUE);
				}
			}
		}

		break;

	case STAGE_5:

		for (int y = 0; y < mapCount[4].y_; y++) {
			for (int x = 0; x < mapCount[4].x_; x++) {
				block[4] = {static_cast<float>(x * blockSize), static_cast<float>(y * blockSize)};

				blockPosition[4][y][x] = { block[4].x_, block[4].y_};

				if (map[4][y][x] == BLOCK) {
					DrawGraph(block[4].x_, block[4].y_ - mapChipMoveY_, BLOCK_TEXTURE, TRUE);
				}
				if (map[4][y][x] == MOVE_BLOCK) {
					DrawGraph(block[4].x_, block[4].y_ + addSpeed - mapChipMoveY_, MOVE_BLOCK_TEXTURE, TRUE);
				}
				if (map[4][y][x] == DAMAGE_BLOCK) {
					DrawGraph(block[4].x_ + addShakeX_, block[4].y_ + addShakeY_ - mapChipMoveY_, DAMAGE_BLOCK_TEXTURE, TRUE);
				}
				if (map[4][y][x] == GOAL_BLOCK) {
					DrawGraph(block[4].x_, block[4].y_ - mapChipMoveY_, GOAL_BLOCK_TEXTURE, TRUE);
				}
				if (map[4][y][x] == BREAK_BLOCK) {
					DrawGraph(block[4].x_, block[4].y_ - mapChipMoveY_, BREAK_BLOCK_TEXTURE, TRUE);
				}
			}
		}

		break;
	}
}

void Map::Move()
{
	const float floorSpeed_ = 0.5f;
	const int returnTime_ = 100;

	floorMoveTime_++;
	if (!isFloorMove_) {
		addSpeed += floorSpeed_;
	}
	if (floorMoveTime_ >= returnTime_ / 2 && floorMoveTime_ < returnTime_) {
		isFloorMove_ = true;
	}
	if (isFloorMove_) {
		addSpeed -= floorSpeed_;
	}
	if (floorMoveTime_ >= returnTime_) {
		isFloorMove_ = false;
		floorMoveTime_ = 0;
	}
}

void Map::Shake()
{
	if (isShake_) {
		// 乱数の取得
		std::random_device rnd;
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<> rand(shakeMin_, shakeMax_);
		std::uniform_int_distribution<> rand1(shakeMin_, shakeMax_);

		shakePosX_ = rand(mt) / shakeMdX_;
		shakePosY_ = rand1(mt) / shakeMdY_;

		shakeTime_++;

		if (shakeTime_ >= defaultShakeTimer_) {
			addShakeX_ -= shakePosX_;
			addShakeY_ -= shakePosY_;
		}
		if (shakeTime_ >= shakeTimer10_) {
			addShakeX_ -= shakePosX_;
			addShakeY_ -= shakePosY_;
		}
		if (shakeTime_ >= shakeTimer20_) {
			addShakeX_ = shakeDefaultPos_;
			shakeTime_ = defaultShakeTimer_;
			isShake_ = false;
		}
	}
}

void Map::MapChipHitCheck()
{

}
