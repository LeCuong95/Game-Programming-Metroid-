#include "IronMan.h"

IronMan::IronMan()
{
	this->x = IRONMAN_X;
	this->y = IRONMAN_Y;

	Vx = 0;
	Vy = 0;
	Speed = IRONMAN_VX;

	Size = new GTexture(IRONMAN_IMAGE_FILE, 4, 1, 4);
	ObjectSprite = new GSprite(Size, IRONMAN_FRAME);

	IsMoving = 0;
	Trend = IRONMAN_TREND;
}

void IronMan::Update(GCamera *camera,int t)
{
	x += Vx;
	y += Vy;

	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (IsMoving != 0)
	{
		if (pos.x <= 0) this->MoveRigh();
		if (pos.x >= G_ScreenWidth) this->MoveLeft();
		ObjectSprite->Update(t);
	}
	else ObjectSprite->SelectIndex(IRONMAN_STOP_IMAGE);

}

void IronMan::DrawObject(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (Trend == -1) ObjectSprite->Draw(pos.x, pos.y);
	else ObjectSprite->DrawFlipX(pos.x, pos.y);
}

