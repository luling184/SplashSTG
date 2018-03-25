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
	FontAsset(L"normal_30")(L"とりあえずのタイトル画面です").draw(0, 0);
	FontAsset(L"normal_30")(L"左クリックでデバッグシーンに遷移します").draw(0,40);
}
