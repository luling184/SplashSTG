#pragma once
#include "AbstractPlayer.hpp"
class Mizuki :
	public AbstractPlayer
{
public:
	Mizuki();
	Mizuki(int, int);
	Mizuki(const Vec2&);
	~Mizuki();

	void init() override;
	void update() override;
	void draw() override;

private:

};

