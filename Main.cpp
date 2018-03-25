# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Title.hpp"
// #include "Debug.hpp"
# include "AssetMgr.hpp"
# include "SceneName.hpp"
# include "Mizuki.hpp"
# include "NormalBlock.hpp"
# include "Poboo.hpp"

void Main()
{
	//            ( 30,  20);
	Window::Resize(960, 640);
	Window::SetTitle(L"スプラッシュ！ --test now--");

	texture::loadAsset();
	sound  ::loadAsset();
	font   ::loadAsset();
	
	MyApp sceneMgr;
	sceneMgr.add<Title>(SceneName::Title);

	while (System::Update())
	{
		TaskSend::All::Update();
		TaskCall::All::Update(callGroupUpdate);
		TaskCall::All::Update(callGroupDraw);
		Task::All::Update();
		FontAsset(L"normal_10.5")(Profiler::FPS() , L"fps").draw(Window::Width()-100,Window::Height()-50);
	}
	Task::All::Clear();
}
