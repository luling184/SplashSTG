#include "stdafx.h"
#include "NormalBullet.hpp"


NormalBullet::NormalBullet()
{
	init();
}

NormalBullet::NormalBullet(int _x, int _y)
{
	init();
	pos.x = _x;
	pos.y = _y;
}


NormalBullet::NormalBullet(const Vec2 &_pos)
{
	init();
	pos = _pos;
}

NormalBullet::~NormalBullet()
{
}

void NormalBullet::init()
{
	speed = 8;
	pos.x = 0;
	pos.y = 0;
	width  = 32;
	height = 32;
	imageName = L"MizukiMainBullet";
	shape = Rect(width, height);
}

void NormalBullet::update()
{
	pos.x += speed;
	if (pos.x > Window::Width() + TextureAsset(imageName).width)
		this->Destroy();
}

void NormalBullet::draw()
{
	TextureAsset(imageName).draw(pos);
}
