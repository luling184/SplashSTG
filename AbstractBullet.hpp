#pragma once
#include <rnfs.h>

class AbstractBullet : public Task
{
public:
	AbstractBullet();
	virtual ~AbstractBullet() {};
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	virtual Polygon getPositionAndShape() const;

protected:
	Vec2 pos;
	int32 width;
	int32 height;
	int32 speed;
	String imageName;
	Rect shape;

private:
	TaskCall updateConnecter;
	TaskCall drawConnecter;
	TaskSend sender;
};
