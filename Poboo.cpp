#include "stdafx.h"
#include "Poboo.hpp"

Poboo::Poboo()
{
	init();
}

Poboo::Poboo(int _x, int _y) 
{
	init();
	pos.x = _x;
	pos.y = _y;
}

Poboo::Poboo(const Vec2& _pos)
{
	init();
	pos = _pos;
}

void Poboo::init()
{
	pos.x = 0;
	pos.y = 0;
	width = 32;
	width = 32;
	AddAnimeAsset(L"PobooMain", 500);
	AddAnimeAsset(L"PobooEffect", 100);
}

void Poboo::update()
{
	pos.x -= 0.5;
}

void Poboo::draw() 
{
	for (auto it : anime) {
		it.draw(pos.x, pos.y);
	}
}
