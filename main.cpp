#include "DxLib.h"
#include "Math.h"
#include "Input.h"
#include "Player.h"
#include "Map.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ClearScene.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "10Days2024";

// ウィンドウ横幅
const int WIN_WIDTH = 1200;

// ウィンドウ縦幅
const int WIN_HEIGHT = 800;

enum
{
	Title,
	Game,
	Clear,
};

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み

	// ゲームループで使う変数の宣言

	//タイトル
	std::unique_ptr<TitleScene> titleScene_;
	titleScene_ = std::make_unique<TitleScene>();
	titleScene_->Initialize();

	//ゲーム
	std::unique_ptr<GameScene> gameScene_;
	gameScene_ = std::make_unique<GameScene>();
	gameScene_->Initialize();

	//クリア
	std::unique_ptr<ClearScene> clearScene_;
	clearScene_ = std::make_unique<ClearScene>();
	clearScene_->Initialize();

	//現在のシーン
	size_t nowScene_ = Title;

	//BGM
	int sound_ = LoadSoundMem("Resource//Sound//BT.wav");

	//音量調整
	int Volume = 75;
	ChangeVolumeSoundMem(Volume, sound_);
	//ループBGM
	PlaySoundMem(sound_, DX_PLAYTYPE_LOOP);

	// ゲームループ
	while (true)
	{
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		Input::GetInstance()->Update();

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理

		//scene判別
		switch (nowScene_)
		{
		case Title:

			//
			titleScene_->Update();

			//次のシーンへ
			if (titleScene_->IsNextScene())
			{
				nowScene_ = Game;
			}

			break;

		case Game:

			//
			gameScene_->Update();

			//次のシーンへ
			if (gameScene_->IsNextScene())
			{
				nowScene_ = Clear;
			}

			break;

		case Clear:

			//
			clearScene_->Update();

			//次のシーンへ
			if (clearScene_->IsNextScene())
			{
				nowScene_ = Title;
			}

			break;

		default:
			break;
		}

		// 描画処理

		//scene判別
		switch (nowScene_)
		{
		case Title:

			//
			titleScene_->Draw();

			break;

		case Game:

			//
			gameScene_->Draw();

			break;

		case Clear:

			//
			clearScene_->Draw();

			break;

		default:
			break;
		}

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}

	//音と画像消去
	InitGraph();
	InitSoundMem();

	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}
