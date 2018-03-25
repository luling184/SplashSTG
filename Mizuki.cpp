#include "stdafx.h"
#include "Mizuki.hpp"
#include "NormalBullet.hpp"


Mizuki::Mizuki()
{
	init();
}

Mizuki::Mizuki(int _x, int _y)
{
	init();
	pos.x = _x;
	pos.y = _y;
}

Mizuki::Mizuki(const Vec2& _vec2)
{
	init();
	pos = _vec2;
}

void Mizuki::init()
{
	pos.x = 0;
	pos.y = 0;
	width = 32;
	height = 32;
	AddAnimeAsset(L"MizukiMain", 4, 100);
	AddAnimeAsset(L"MizukiMirror",4, 100);
	currentAnime = 0;
	parameter.jumpPower = 110;
	state.moveDirection = MoveDirection::Non;
	state.isOnBlock = false;
	bulletCounter = 0;
}

Mizuki::~Mizuki() {
}

void Mizuki::update()
{
	++bulletCounter;
	if (Input::AnyKeyPressed()) {
		anime[currentAnime].start();
		if (Input::KeyUp.clicked) {
			state.isJumping = true;
			state.moveDirection = MoveDirection::Up;
			for (auto it : anime) {
				it.reset();
			}
		}

		if (Input::KeyDown.pressed && !state.isOnBlock) {
			pos.y += 3;
			state.moveDirection = MoveDirection::Down;
			for (auto it : anime) {
				it.reset();
			}
		}

		if (Input::KeyRight.pressed) {
			pos.x += 3;
			state.moveDirection = MoveDirection::Right;
			currentAnime = 1;
		}

		if (Input::KeyLeft.pressed) {
			pos.x -= 3;
			state.moveDirection = MoveDirection::Left;
			currentAnime = 0;
		}

		if (Input::KeyZ.pressed) {
			if (bulletCounter % 5 == 0) {
				SoundAsset(L"Mizuki").playMulti(0.1);
				Create<NormalBullet>(pos);
			}
		}

	}
	else {
		if (state.isOnBlock) {
			state.moveDirection = MoveDirection::Non;
		}
		else {
			state.moveDirection = MoveDirection::Down;
			for (unsigned i = 0; i < anime.size(); ++i) {
				anime[i].reset();
			}
		}
	}

	if (!state.isOnBlock && !state.isJumping) {
		pos.y += 1;
	}

	if (state.isJumping == true) {
		jump();
	}
}

void Mizuki::draw()
{
	switch (state.moveDirection)
	{
	case MoveDirection::Up:
		FontAsset(L"normal_10.5")(L"Up").draw(0, 40);
		break;
	case MoveDirection::Down:
		FontAsset(L"normal_10.5")(L"Down").draw(0, 40);
		break;
	case MoveDirection::Left:
		FontAsset(L"normal_10.5")(L"Left").draw(0, 40);
		break;
	case MoveDirection::Right:
		FontAsset(L"normal_10.5")(L"Right").draw(0, 40);
		break;
	case MoveDirection::Non:
		FontAsset(L"normal_10.5")(L"Non").draw(0, 40);
		break;
	default:
		break;
	}

	FontAsset(L"normal_10.5")(state.isOnBlock).draw(0,0);
	FontAsset(L"normal_10.5")(pos).draw(0, 20);
	anime[currentAnime].draw(pos);

}