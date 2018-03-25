#include "stdafx.h"
#include "AbstractPlayer.hpp"

#include "AbstractBlock.hpp"

AbstractPlayer::AbstractPlayer() :
	Task(),
	updateConnecter(this, &AbstractPlayer::update, callGroupUpdate), 
	drawConnecter  (this, &AbstractPlayer::draw, callGroupDraw)
{
	// 送信側のセット
	sender.Register(this);

	// 受信側のセット
	receiver.Register<AbstractBlock>(this, &AbstractPlayer::HitCheck);
}

void AbstractPlayer::jump()
{
	static bool startJump = false;
	static int32 firstHeight = 0;
	static Vec2 prevPos;
	static int32 tempY = 0;
	
	static Stopwatch sw;
	if (!startJump) {
		firstHeight = pos.y;
		prevPos.y = pos.y;
		sw.start();
	}

	startJump = true;

	if (startJump) {
		tempY = pos.y;
		pos.y += (int)pos.y - prevPos.y - 1;
		prevPos.y = tempY;
		if (pos.y <= firstHeight - parameter.jumpPower) {
			state.isJumping = false;
			startJump = false;
			sw.reset();
		}
	}
}

void AbstractPlayer::HitCheck(AbstractBlock& block)
{
	Rect playerShape(getPositionAndShape().boundingRect);
	Rect blockShape (block.getPositionAndShape().boundingRect);
	static Vec2 prevPos;
	static Vec2 tempPos = pos;
	const int zuresi[2] = { 1,3 };
	prevPos = tempPos;
	
	if (prevPos != pos || blockShape.top.intersects(playerShape)) {
		state.isOnBlock = false;
	}
	Line tempTop = blockShape.top;
	tempTop.moveBy(0, (zuresi[0]+0.1)*(-1));
	tempTop.begin.x += zuresi[1];
	tempTop.end.x -= zuresi[1];
	if (tempTop.intersects(playerShape)) {
		pos.y = blockShape.y - height - zuresi[0];
		state.isOnBlock = true;
	}
	if (blockShape.intersects(playerShape)) {
		/*
		if (blockShape.left.intersects(playerShape)) {
			SoundAsset(L"ジャンプ").play();
			pos.x = blockShape.x - width;
		} else if (playerShape.right.intersects(playerShape)) {
			SoundAsset(L"Mizuki").play();
			pos.x = blockShape.x + blockShape.w;
			
		}*/
		
		if (blockShape.bottom.intersects(playerShape)) {
			pos.y = blockShape.y + blockShape.h;
		}
	}
	tempPos = pos;
	/*
	if (playerShape.intersects(blockShape)) {
		if (state.isOnBlock) {
			// もしも横にあたってたら
			if (state.moveDirection == MoveDirection::Right)
				pos.x = blockShape.x;
			if (state.moveDirection == MoveDirection::Left)
				pos.x = blockShape.w;
		}
		//// もしも下から叩いたら
		if (state.isJumping)
			pos.y = blockShape.y;
	}
	// もしも上に乗ってたら
	if (playerShape.x + playerShape.w > blockShape.x && playerShape.x < blockShape.x + blockShape.w) {
		if (playerShape.y + playerShape.h >= blockShape.y && playerShape.y < blockShape.y + blockShape.h) {
			SoundAsset(L"Mizuki").play();
			pos.y = blockShape.y - height;
			state.isOnBlock = true;
		}
	}
	else {
		state.isOnBlock = false;
	}
	// state.isOnBlock = (pos.y == blockShape.y - height) ? true : false;
	*/
}

Polygon AbstractPlayer::getPositionAndShape() const
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
