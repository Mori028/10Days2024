#include "DxLib.h"
#include "Math.h"
#include "Input.h"
#include "Player.h"
#include "Map.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ClearScene.h"

// ウィンドウのタイトルに表示する斁E���E
const char TITLE[] = "4027_CRush";

// ウィンドウ横幁E
const int WIN_WIDTH = 1200;

// ウィンドウ縦幁E
const int WIN_HEIGHT = 800;

enum
{
	Title,
	Game,
	Clear,
};

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設宁E
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、E
	// かつウィンドウサイズに合わせて拡大できなぁE��ぁE��する
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設宁Eモニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設宁E解像度との比率で設宁E
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定すめE
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期匁E
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィチE��領域は裏面を指宁E
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースチE�Eタの変数宣言と読み込み

	// ゲームループで使ぁE��数の宣言

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
	int damagesound_ = LoadSoundMem("Resource//Sound//damege.wav");
	int jumpsound_ = LoadSoundMem("Resource//Sound//Jump.wav");
	int clearsound_ = LoadSoundMem("Resource//Sound//gameClear.wav");
	int oversound_ = LoadSoundMem("Resource//Sound//gameOver.wav");
	int titlesound_ = LoadSoundMem("Resource//Sound//gameTitle.wav");

	int standTimer = 0;
	//音量調整
	int Volume = 75;
	ChangeVolumeSoundMem(Volume, sound_);
	ChangeVolumeSoundMem(Volume, titlesound_);
	ChangeVolumeSoundMem(Volume, clearsound_);
	ChangeVolumeSoundMem(Volume, oversound_);
	ChangeVolumeSoundMem(Volume, damagesound_);
	ChangeVolumeSoundMem(Volume, jumpsound_);
	//タイトルBGM
	PlaySoundMem(titlesound_, DX_PLAYTYPE_LOOP);
	//ダメージSE
	//PlaySoundMem(damagesound_, DX_PLAYTYPE_LOOP);
	// ゲームオーバ�EBGM
	//PlaySoundMem(oversound_, DX_PLAYTYPE_LOOP);

	// ゲームルーチE
	while (true)
	{
		// 最新のキーボ�Eド情報だったものは1フレーム前�Eキーボ�Eド情報として保孁E
		// 最新のキーボ�Eド情報を取征E
		Input::GetInstance()->Update();

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処琁E

		//scene判別
		switch (nowScene_)
		{
		case Title:

			standTimer++;
			if (standTimer >= 60) {
				//
				titleScene_->Update();
				StopSoundMem(oversound_);
				//StopSoundMem(clearsound_);
				//次のシーンへ
				if (titleScene_->IsNextScene())
				{
					PlaySoundMem(jumpsound_, DX_PLAYTYPE_NORMAL);
					nowScene_ = Game;
					//ゲームBGM
					PlaySoundMem(sound_, DX_PLAYTYPE_LOOP);
					titleScene_->Reset();
				}
			}
			break;

		case Game:
			standTimer = 0;
			StopSoundMem(titlesound_);
			//
			gameScene_->Update();
			//クリア次のシーンへ
			if (gameScene_->IsNextScene())
			{

				nowScene_ = Clear;

				//���ʂ��i�[
				size_t time = gameScene_->GetTime();
				clearScene_->SetResult(time);
				gameScene_->Reset();
			}

			break;

		case Clear:
			standTimer++;
			//クリアBGM
			if (standTimer >= 0 && standTimer <= 155) {
				StopSoundMem(sound_);
				if (CheckSoundMem(clearsound_) == 0) {
					PlaySoundMem(clearsound_, DX_PLAYTYPE_BACK, true);
				}
			}
			else {
				StopSoundMem(clearsound_);
			}
			//
			clearScene_->Update();
			//次のシーンへ
			if (clearScene_->IsNextScene())
			{
				StopSoundMem(clearsound_);
				standTimer = 0;
				PlaySoundMem(titlesound_, DX_PLAYTYPE_LOOP);
				nowScene_ = Title;
				clearScene_->Reset();
			}

			break;

		default:
			break;
		}

		// 描画処琁E

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

		// 20ミリ秒征E��E疑似60FPS)
		WaitTimer(20);

		// WindowsシスチE��からくる惁E��を�E琁E��めE
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

	// Dxライブラリ終亁E�E琁E
	DxLib_End();

	// 正常終亁E
	return 0;
}
