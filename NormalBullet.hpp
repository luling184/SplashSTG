#pragma once
#include "AbstractBullet.hpp"
class NormalBullet :
	public AbstractBullet
{
public:
	NormalBullet();
	NormalBullet(int,int);
	NormalBullet(const Vec2&);
	~NormalBullet();

	void init() override;
	void update() override;
	void draw() override;

private:
	
};

