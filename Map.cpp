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
	BLOCK_TEXTURE = LoadGraph("Resources/1.png", TRUE);

	// マップチップの描画
	for (int y = 0; y < MAP_SIZE_HEIGHT; y++) {
		for (int x = 0; x < MAP_SIZE_WIDTH; x++) {
			blockX = static_cast<float>(x * blockSize);
			blockY = static_cast<float>(y * blockSize);

			blockPosition[y][x] = { blockX,blockY };
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
			blockX = static_cast<float>(x * blockSize);
			blockY = static_cast<float>(y * blockSize);

			blockPosition[y][x] = { blockX,blockY };

			if (map[y][x] == BLOCK) {
				DrawGraph(blockX, blockY, BLOCK_TEXTURE, TRUE);
			}
			if (map[y][x] == MOVE_BLOCK) {
				DrawGraph(blockX, blockY + addSpeed, BLOCK_TEXTURE, TRUE);
			}
			if (map[y][x] == DAMAGE_BLOCK) {
				DrawGraph(blockX + addShakeX_, blockY + addShakeY_, BLOCK_TEXTURE, TRUE);
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
