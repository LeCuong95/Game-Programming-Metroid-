#include "Bat.h"

Bat::Bat()
{
	this->x = BAT_X;
	this->y = BAT_Y;
	
	Vx = 0;
	Vy = 0;
	Speed = BAT_VX;

	Size = new GTexture(BAT_IMAGE_FILE, 4, 1, 4);
	ObjectSprite = new GSprite(Size, BAT_FRAME);

	IsMoving = 0;
	Trend = BAT_TREND;
}

void Bat::Update(GCamera *camera,int t)
{
	if (IsMoving != 0)
	{
		x += Vx;
		y = sin(x*0.03)*41.3 + 200;
		D3DXVECTOR2 pos = camera->Transform(x, y);

		if (pos.x <= 0) this->MoveRigh();
		if (pos.x >= G_ScreenWidth) this->MoveLeft();

		if (ObjectSprite->_index == 0)
			ObjectSprite->_index++;
		ObjectSprite->Update(t);
	}
	else ObjectSprite->SelectIndex(BAT_STOP_IMAGE);
}

void Bat::DrawObject(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (Trend == -1) ObjectSprite->Draw(pos.x, pos.y);
	else ObjectSprite->DrawFlipX(pos.x, pos.y);
}
