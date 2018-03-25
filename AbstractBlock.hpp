#pragma once

# include "AnimeAsset.hpp"
# include <rnfs.h>

#define AddAnimeAsset(imageName, duration, changeSpeed) anime.emplace_back(asc::AnimeAsset(imageName, duration, changeSpeed))

class AbstractBlock : public Task
{
public:
	AbstractBlock();
	virtual ~AbstractBlock();

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	virtual Polygon getPositionAndShape() const;

protected:
	Vec2 pos;
	int32 width, height;
	Array<asc::AnimeAsset> anime;
	
private:
	TaskCall updateConnecter;
	TaskCall drawConnecter;
	TaskSend sender;
};

