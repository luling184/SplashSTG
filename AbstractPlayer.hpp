#pragma once

#include "AnimeAsset.hpp"
#include "PlayerParameter.hpp"
#include "PlayerState.hpp"

#define AddAnimeAsset(imageName, duration, changeSpeed) anime.emplace_back(asc::AnimeAsset(imageName, duration, changeSpeed))

class AbstractBlock;

class AbstractPlayer : public Task
{
public:
	AbstractPlayer();
	AbstractPlayer(int, int) {}
	AbstractPlayer(const Vec2&) {}
	virtual ~AbstractPlayer() {}

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	virtual void jump();
	void HitCheck(AbstractBlock&);

	virtual Polygon getPositionAndShape() const;



protected:
	Vec2 pos;
	int32 width, height;
	Rect shape;
	PlayerState state;
	PlayerParameter parameter;

	INIReader ini;
	int32 currentAnime;
	Array<asc::AnimeAsset> anime;
	int bulletCounter;

private:
	TaskCall updateConnecter;
	TaskCall drawConnecter;
	TaskSend sender;
	TaskReceive receiver;
};