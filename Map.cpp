#include "Map.h"

Map::Map() {}

Map::~Map() {}

void Map::Initialize()
{
	// �}�b�v�̐�
	int mapCountX = sizeof(map[0]) / sizeof(map[0][0]);
	int mapCountY = sizeof(map) / sizeof(map[0]);

	// �摜�̊��蓖��
	BLOCK_TEXTURE = LoadGraph("Resources/1.png", TRUE);

	// �}�b�v�`�b�v�̕`��
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
}

void Map::Draw()
{
	// �}�b�v�`�b�v�̕`��
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
			if (map[y][x] == GOAL) {
				//blend���Z
				SetDrawBlendMode(DX_BLENDMODE_ADD, 150);
				DrawGraph(blockX, blockY, BLOCK_TEXTURE, TRUE);
				//blend�߂�
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
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
