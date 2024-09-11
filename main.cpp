#include "DxLib.h"
#include "Math.h"
#include "Input.h"
#include "Player.h"
#include "Map.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ClearScene.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "10Days2024";

// �E�B���h�E����
const int WIN_WIDTH = 1200;

// �E�B���h�E�c��
const int WIN_HEIGHT = 800;

enum
{
	Title,
	Game,
	Clear,
};

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���

	// �Q�[�����[�v�Ŏg���ϐ��̐錾

	//�^�C�g��
	std::unique_ptr<TitleScene> titleScene_;
	titleScene_ = std::make_unique<TitleScene>();
	titleScene_->Initialize();

	//�Q�[��
	std::unique_ptr<GameScene> gameScene_;
	gameScene_ = std::make_unique<GameScene>();
	gameScene_->Initialize();

	//�N���A
	std::unique_ptr<ClearScene> clearScene_;
	clearScene_ = std::make_unique<ClearScene>();
	clearScene_->Initialize();

	//���݂̃V�[��
	size_t nowScene_ = Title;

	//BGM
	int sound_ = LoadSoundMem("Resource//Sound//BT.wav");

	//���ʒ���
	int Volume = 75;
	ChangeVolumeSoundMem(Volume, sound_);
	//���[�vBGM
	PlaySoundMem(sound_, DX_PLAYTYPE_LOOP);

	// �Q�[�����[�v
	while (true)
	{
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		// �ŐV�̃L�[�{�[�h�����擾
		Input::GetInstance()->Update();

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����

		//scene����
		switch (nowScene_)
		{
		case Title:

			//
			titleScene_->Update();

			//���̃V�[����
			if (titleScene_->IsNextScene())
			{
				nowScene_ = Game;
			}

			break;

		case Game:

			//
			gameScene_->Update();

			//���̃V�[����
			if (gameScene_->IsNextScene())
			{
				nowScene_ = Clear;
			}

			break;

		case Clear:

			//
			clearScene_->Update();

			//���̃V�[����
			if (clearScene_->IsNextScene())
			{
				nowScene_ = Title;
			}

			break;

		default:
			break;
		}

		// �`�揈��

		//scene����
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

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}

	//���Ɖ摜����
	InitGraph();
	InitSoundMem();

	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
