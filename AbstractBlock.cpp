#include "stdafx.h"
#include "AbstractBlock.hpp"


AbstractBlock::AbstractBlock() :
	Task(),
	updateConnecter(this, &AbstractBlock::update, callGroupUpdate),
	drawConnecter(this, &AbstractBlock::draw, callGroupDraw)
{
	sender.Register(this);
}


AbstractBlock::~AbstractBlock()
{
}

Polygon AbstractBlock::getPositionAndShape() const
{
	Polygon polygon
	{
		{ pos.x, pos.y },
		{ pos.x, pos.y + height },
		{ pos.x + width, pos.y + height },
		{ pos.x + width, pos.y },

	};
	return polygon;
}
