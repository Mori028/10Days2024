#include "Map.h"

void Map::Initialize()
{
	
}

void Map::Update()
{
	floorMoveTime_++;
	if (!isFloorMove_) {
		floor.y += 0.5f;
	}
	if (floorMoveTime_ >= 50 && floorMoveTime_ < 100) {
		isFloorMove_ = true;
	}
	if (isFloorMove_) {
		floor.y -= 0.5f;
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
