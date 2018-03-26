#pragma once
class Game :
	public MyApp::Scene
{
public:
	Game();
	~Game();

	MethodExec<Game> onExec;

	void init() override;
	void update() override;
	void draw() const override;

private:
	MethodExec<Game> readyCount();
	MethodExec<Game> startBattle();
	//MethodExec<Game>
};

