#include "Time.h"

void Time::Initialize()
{
	//計測用
	time_ = 0;

	//描画用
	drawTime_ = 0;

	//
	timeGraph[0] = LoadGraph("Resource//Drop0.png");
	timeGraph[1] = LoadGraph("Resource//Drop1.png");
	timeGraph[2] = LoadGraph("Resource//Drop2.png");
	timeGraph[3] = LoadGraph("Resource//Drop3.png");
	timeGraph[4] = LoadGraph("Resource//Drop4.png");
	timeGraph[5] = LoadGraph("Resource//Drop5.png");
	timeGraph[6] = LoadGraph("Resource//Drop6.png");
	timeGraph[7] = LoadGraph("Resource//Drop7.png");
	timeGraph[8] = LoadGraph("Resource//Drop8.png");
	timeGraph[9] = LoadGraph("Resource//Drop9.png");

	//動かす
	timeStopFlag_ = false;
}

void Time::Update()
{
	if (!timeStopFlag_)
	{
		time_++;

		if (time_ == 60)
		{
			drawTime_++;
			time_ = 0;
		}
	}
}

void Time::Draw()
{
	//位置情報
	int x = 500;
	int y = 0;
	int size = 80;

	//1000秒超えた時
	if (drawTime_ > 999)
	{
		drawTime_ = 999;
	}

	//
	if (drawTime_ > 99)
	{
		int a = drawTime_ / 100;
		DrawExtendGraph(x, y, x + size, y + size, timeGraph[a], true);
	}
	else
	{
		DrawExtendGraph(x, y, x + size, y + size, timeGraph[0], true);
	}

	if (drawTime_ > 9)
	{
		if (drawTime_ > 99)
		{
			int a = drawTime_ - (drawTime_ / 100 * 100);
			a = a / 10;
			DrawExtendGraph(x + size, y, x + size + size, y + size, timeGraph[a], true);
		}
		else
		{
			int a = drawTime_ / 10;
			DrawExtendGraph(x + size, y, x + size + size, y + size, timeGraph[a], true);
		}
	}
	else
	{
		DrawExtendGraph(x + size, y, x + size + size, y + size, timeGraph[0], true);
	}


	//
	int a = drawTime_ - (drawTime_ / 10 * 10);
	DrawExtendGraph(x + size + size, y, x + size + size + size, y + size, timeGraph[a], true);
}

void Time::Finalize()
{

}

void Time::Reset()
{
	//計測用
	time_ = 0;

	//描画用
	drawTime_ = 0;

	//動かす
	timeStopFlag_ = false;
}
