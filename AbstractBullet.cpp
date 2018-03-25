#include "stdafx.h"
#include "AbstractBullet.hpp"

AbstractBullet::AbstractBullet() : 
	Task(),
	updateConnecter(this,&AbstractBullet::update,callGroupUpdate),
	drawConnecter(this, &AbstractBullet::draw, callGroupDraw)
{
	sender.Register(this);
}

Polygon AbstractBullet::getPositionAndShape() const
{
	const Polygon polygon
	{
		{ pos.x, pos.y },
		{ pos.x, pos.y + height },
		{ pos.x + width, pos.y + height },
		{ pos.x + width, pos.y },

	};
	return polygon;
}
