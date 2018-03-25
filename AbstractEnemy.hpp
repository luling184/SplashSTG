#pragma once
#include "EnemyParameter.hpp"
#include "AnimeAsset.hpp"

#define AddAnimeAsset(imageName , changeSpeed) anime.emplace_back(asc::AnimeAsset(imageName, TextureAsset(imageName).width / pixelSize, changeSpeed));

class AbstractEnemy : public Task
{
public:
	AbstractEnemy();
	AbstractEnemy(int, int) {}
	AbstractEnemy(const Vec2&) {}
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	EnemyParameter parameter;
	Vec2 pos;
	int width;
	int height;

protected:
	Array<asc::AnimeAsset> anime;
	const int pixelSize = 32;
	
private:
	TaskCall updateConnecter;
	TaskCall drawConnecter;
};