#include "stdafx.h"
#include "AbstractEnemy.hpp"

AbstractEnemy::AbstractEnemy() :
	Task(),
	updateConnecter(this, &AbstractEnemy::update, callGroupUpdate),
	drawConnecter(this, &AbstractEnemy::draw, callGroupDraw)
{
}
