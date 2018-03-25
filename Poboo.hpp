#pragma once
#include "AbstractEnemy.hpp"
class Poboo :
	public AbstractEnemy
{
public:
	Poboo();
	Poboo(int, int);
	Poboo(const Vec2&);
	~Poboo() {}

	void init() override;
	void update() override;
	void draw() override;

private:
};