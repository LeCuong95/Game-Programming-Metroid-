#include "Quang.h"


void  CQuang::Update(int t)
{
	//x = x + vx;
	SQuang->SelectIndex(4);
	SQuang->Reset();
}
void CQuang::Draw(GCamera * cam)
{
	D3DXVECTOR2 pos = cam->Transform(x,y);
	SQuang->DrawFromTL(pos.x, pos.y);
}

CQuang::CQuang()
{
	TQuang = new GTexture("./Resources/mainmenu1.png", 1, 1, 1);
	SQuang = new GSprite(TQuang);
}

CQuang::~CQuang()
{
}
