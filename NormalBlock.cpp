#include "stdafx.h"
#include "NormalBlock.hpp"


NormalBlock::NormalBlock()
{
	init();
}

NormalBlock::NormalBlock(int _x, int _y)
{
	init();
	pos.x = _x;
	pos.y = _y;
}

NormalBlock::NormalBlock(const Vec2 &_pos)
{
	init();
	pos = _pos;
}


NormalBlock::~NormalBlock()
{
}

void NormalBlock::init()
{
	pos.x = 0;
	pos.y = 0;
	width = 32;
	height = 32;
	AddAnimeAsset(L"NormalBlockMain", 1, 500);
}

void NormalBlock::update()
{

}

void NormalBlock::draw()
{
	anime[0].draw(pos);
}