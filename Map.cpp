#include "Map.h"

Map::Map(){}

Map::~Map(){}

void Map::Initialize()
{
	
}

void Map::Update()
{
	const float floorSpeed_ = 0.5f;

	floorMoveTime_++;
	if (!isFloorMove_) {
		floor.y += floorSpeed_;
	}
	if (floorMoveTime_ >= 50 && floorMoveTime_ < 100) {
		isFloorMove_ = true;
	}
	if (isFloorMove_) {
		floor.y -= floorSpeed_;
	}
	if (floorMoveTime_ >= 100) {
		isFloorMove_ = false;
		floorMoveTime_ = 0;
	}

	//DrawFormatString(500, 10, GetColor(255, 255, 255), "%d", floorMoveTime_);
}

void Map::Draw()
{
	DrawBox(50, 0, 100, 1000, GetColor(255, 255, 255), TRUE);
	DrawBox(1150, 0, 1100, 1000, GetColor(255, 255, 255), TRUE);
	DrawBox(400, 400, 800, 420, GetColor(255, 255, 255), TRUE);
	DrawBox(900, 500, 1100, 520, GetColor(255, 255, 255), TRUE);
	DrawBox(floor.x, floor.y, floor.x + 200, floor.y + 20, GetColor(255, 255, 255), TRUE);
}

void Map::Move()
{
}
