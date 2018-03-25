#pragma once

#include "GameData.hpp"

enum class SceneName {
	Title,
	Game,
	Config,
	Debug,
};

using MyApp = SceneManager<SceneName, GameData>;