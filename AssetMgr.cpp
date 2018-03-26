#include "AssetMgr.hpp"

int32 texture::loadAsset()
{
	TextureAsset::Register(L"PobooMain"       , L"Image\\Enemy\\Poboo\\main.png"         );
	TextureAsset::Register(L"PobooEffect"     , L"Image\\Enemy\\Poboo\\effect.png"       );
	TextureAsset::Register(L"MizukiMain"      , L"Image\\Player\\Mizuki\\Main.png"       );
	TextureAsset::Register(L"MizukiMirror"    , L"Image\\Player\\Mizuki\\Main_mirror.png");
	TextureAsset::Register(L"MizukiMainBullet", L"Image\\Bullet\\Mizuki\\main.png"       );
	TextureAsset::Register(L"NormalBlockMain" , L"Image\\Block\\Normal\\main.png"        );
	TextureAsset::Register(L"Planet_and_Water", L"Image\\Back\\Planet_and_Water.png"     );
	return 0;
}

int32 sound::loadAsset()
{
	SoundAsset::Register(L"Mizuki", L"Sound\\ショット音\\bubble.wav");
	SoundAsset::Register(L"ジャンプ", L"Sound\\nc24552.wav");
	return 0;
}

int32 font::loadAsset()
{
	FontAsset::Register(L"normal_30", 30);
	FontAsset::Register(L"normal_20", 20);
	FontAsset::Register(L"normal_10", 10 );
	return 0;
}