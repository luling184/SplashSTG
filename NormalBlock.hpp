#pragma once
#include "AbstractBlock.hpp"
class NormalBlock :
	public AbstractBlock
{
public:
	NormalBlock();
	NormalBlock(int,int);
	NormalBlock(const Vec2&);
	~NormalBlock();

	void init() override;
	void update() override;
	void draw() override;
};

