#pragma once
#include <Siv3D.hpp>
#include <rnfs.h>
#include <HamFramework.hpp>
#include "SceneName.hpp"

template <typename T>
class MethodExec {
public:
	MethodExec(MethodExec<T>(T::*f)()) : func_(f) {};
	MethodExec<T> exec(T* obj) {
		return (obj->*func_)();
	}
private:
	MethodExec<T>(T::*func_)(); // 実行するT型クラスのメソッドポインタ
};

enum CallGroup
{
	callGroupUpdate,   //更新グループ
	callGroupDraw,     //描画グループ
};