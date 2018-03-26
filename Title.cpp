#include "stdafx.h"
#include "Title.hpp"


Title::Title()
{
}


Title::~Title()
{
}

void Title::update()
{
	if (Input::MouseL.clicked) {
		changeScene(SceneName::Game, 0);
	}
}

void Title::draw() const
{
	TextureAsset(L"Planet_and_Water").draw(0, 0);
	FontAsset(L"normal_30")(L"�Ƃ肠�����̃^�C�g����ʂł�").draw(0, 0);
	FontAsset(L"normal_30")(L"���N���b�N�Ńf�o�b�O�V�[���ɑJ�ڂ��܂�").draw(0,40);
}
