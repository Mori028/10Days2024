#include "Map.h"

Map::Map(){}

Map::~Map(){}

void Map::Initialize()
{
	
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
	DrawBox(50, 0, 100, 1000, GetColor(255, 255, 255), TRUE);
	DrawBox(1150, 0, 1100, 1000, GetColor(255, 255, 255), TRUE);
	DrawBox(400, 400, 800, 420, GetColor(255, 255, 255), TRUE);
	DrawBox(floor[1].x, floor[1].y, floor[1].x + 200, floor[1].y + 20, GetColor(255, 255, 255), TRUE);
	DrawBox(floor[0].x, floor[0].y, floor[0].x + 200, floor[0].y + 20, GetColor(255, 255, 255), TRUE);
}

void Map::Move()
{
}
