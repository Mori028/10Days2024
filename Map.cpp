#include "Map.h"

Map::Map(){}

Map::~Map(){}

void Map::Initialize()
{
	// マップの数
	int mapCountX = sizeof(map[0]) / sizeof(map[0][0]);
	int mapCountY = sizeof(map) / sizeof(map[0]);

	// 画像の割り当て
	block = LoadGraph("Resources/1.png", TRUE);
}

void Map::Update()
{
	const float floorSpeed_ = 0.5f;
	const int returnTime_ = 100;

	floorMoveTime_++;
	if (!isFloorMove_) {
		floor[0].y += floorSpeed_;
		floor[1].y += floorSpeed_;
	}
	if (floorMoveTime_ >= returnTime_ / 2 && floorMoveTime_ < returnTime_) {
		isFloorMove_ = true;
	}
	if (isFloorMove_) {
		floor[0].y -= floorSpeed_;
		floor[1].y -= floorSpeed_;
	}
	if (floorMoveTime_ >= returnTime_) {
		isFloorMove_ = false;
		floorMoveTime_ = 0;
	}
}

void Map::Draw()
{
	for (int i = 0; i < 2; i++) {
		DrawGraph(floor[i].x, floor[i].y, block, TRUE);
	}
	
	// マップチップの描画
	for (int y = 0; y < MAP_SIZE_HEIGHT; y++) {
		for (int x = 0; x < MAP_SIZE_WIDTH; x++) {
			blockX = x * blockSize;
			blockY = y * blockSize;

			if (map[y][x] == BLOCK) {
				DrawGraph(blockX, blockY, block, TRUE);
			}
		}
	}
}

void Map::Move()
{
}
