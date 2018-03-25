#pragma once

#include "SceneName.hpp"

class Title :
	public MyApp::Scene
{
public:
	Title();
	~Title();
	void update() override;
	void draw() const override;
};

