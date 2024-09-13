#include "Map.h"
#include "Input.h"
#include <random>

Map::Map() {}

Map::~Map() {}

void Map::Initialize()
{
	// マップの数
	int mapCountX = sizeof(map[0]) / sizeof(map[0][0]);
	int mapCountY = sizeof(map) / sizeof(map[0]);

	// 画像の割り当て
	BLOCK_TEXTURE = LoadGraph("Resource/Block3_1.png", TRUE);
	MOVE_BLOCK_TEXTURE = LoadGraph("Resource/1.png", TRUE);
	DAMAGE_BLOCK_TEXTURE = LoadGraph("Resource/DamageBlock.png", TRUE);
	GOAL_BLOCK_TEXTURE = LoadGraph("Resource/goal.png", TRUE);
	NONBREAK_BLOCK_TEXTURE = LoadGraph("Resource/Block3.png", TRUE);

	// マップチップの描画
	for (int y = 0; y < MAP_SIZE_HEIGHT; y++) {
		for (int x = 0; x < MAP_SIZE_WIDTH; x++) {
			block = { static_cast<float>(x * blockSize), static_cast<float>(y * blockSize) };

			blockPosition[y][x] = { block.x_, block.y_ };
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
	for (int y = 0; y < MAP_SIZE_HEIGHT; y++) {
		for (int x = 0; x < MAP_SIZE_WIDTH; x++) {
			block = { static_cast<float>(x * blockSize), static_cast<float>(y * blockSize) };

			blockPosition[y][x] = { block.x_, block.y_ };

			if (map[y][x] == BLOCK) {
				DrawGraph(block.x_, block.y_ - mapChipMoveY_, BLOCK_TEXTURE, TRUE);
			}
			if (map[y][x] == MOVE_BLOCK) {
				DrawGraph(block.x_, block.y_ + addSpeed - mapChipMoveY_, MOVE_BLOCK_TEXTURE, TRUE);
			}
			if (map[y][x] == DAMAGE_BLOCK) {
				DrawGraph(block.x_ + addShakeX_, block.y_ + addShakeY_ - mapChipMoveY_, DAMAGE_BLOCK_TEXTURE, TRUE);
			}
			if (map[y][x] == GOAL_BLOCK) {
				DrawGraph(block.x_, block.y_ - mapChipMoveY_, GOAL_BLOCK_TEXTURE, TRUE);
			}
			if (map[y][x] == NONBREAK_BLOCK) {
				DrawGraph(block.x_, block.y_ - mapChipMoveY_, NONBREAK_BLOCK_TEXTURE, TRUE);
			}
		}
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
