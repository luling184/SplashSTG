#pragma once
#include <Siv3D.hpp>
#include <rnfs.h>
#include <HamFramework.hpp>

enum CallGroup
{
	callGroupUpdate,   //更新グループ
	callGroupDraw,     //描画グループ
};