#include "Map.h"

Map::Map(){}

Map::~Map(){}

void Map::Initialize()
{
	// �}�b�v�̐�
	int mapCountX = sizeof(map[0]) / sizeof(map[0][0]);
	int mapCountY = sizeof(map) / sizeof(map[0]);
}

void Map::Update()
{
	const float floorSpeed_ = 0.5f;
	const int returnTime_ = 100;

	floorMoveTime_++;
	if (!isFloorMove_) {
		floor[0].y += floorSpeed_;
		floor[1].y -= floorSpeed_;
	}
	if (floorMoveTime_ >= returnTime_ / 2 && floorMoveTime_ < returnTime_) {
		isFloorMove_ = true;
	}
	if (isFloorMove_) {
		floor[0].y -= floorSpeed_;
		floor[1].y += floorSpeed_;
	}
	if (floorMoveTime_ >= returnTime_) {
		isFloorMove_ = false;
		floorMoveTime_ = 0;
	}

	DrawFormatString(600, 10, GetColor(255, 255, 255), "%d", floorMoveTime_);
}

void Map::Draw()
{
	LoadGraphScreen(floor[0].x, floor[0].y, "Resources/1.png", TRUE);
	LoadGraphScreen(floor[1].x, floor[1].y, "Resources/1.png", TRUE);
	
	for (int y = 0; y < MAP_SIZE_HEIGHT; y++) {
		for (int x = 0; x < MAP_SIZE_WIDTH; x++) {
			if (map[y][x] == 1) {
				LoadGraphScreen(x * blockSize, y * blockSize, "Resources/1.png", TRUE);
			}
		}
	}
}

void Map::Move()
{
}
