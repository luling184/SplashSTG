# include "Game.hpp"
# include "Mizuki.hpp"

Game::Game()
	: onExec(&Game::readyCount)
{
}


Game::~Game()
{
}

void Game::init()
{
	Create<Mizuki>(0, 0);
}

void Game::update()
{
	onExec = onExec.exec(this);
}

void Game::draw() const
{
	TaskCall::All::Update(callGroupDraw);
}

MethodExec<Game> Game::readyCount()
{
	static Stopwatch sw(true);
	sw.isActive() ? true : sw.restart();

	FontAsset(L"normal_10")(3 - sw.s()).draw(0, 0, Palette::White);

	if (sw.s() == 3) {
		sw.reset();
		return &Game::startBattle;
	}
	
	return &Game::readyCount;
}

MethodExec<Game> Game::startBattle()
{
	TaskCall::All::Update(callGroupUpdate);
	Circle(100, 100, 20).draw(Palette::Red);
	if (Input::KeySpace.clicked)
	{
		return &Game::readyCount;
	}
	else
	{
		return &Game::startBattle;
	}

}
