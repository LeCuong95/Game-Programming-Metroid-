#include "Zoomer.h"

Zoomer::Zoomer()
{
	this->x = ZOOMER_X;
	this->y = ZOOMER_Y;

	Vx = 0;
	Vy = 0;
	this->Vx = ZOOMER_VX;

	Size = new GTexture(ZOOMER_IMAGE_FILE, 2, 1, 2);
	ObjectSprite = new GSprite(Size, ZOOMER_FRAME);

	IsGoing = 0;
	Trend = ZOOMER_TREND;
}
Zoomer::Zoomer(float x, float y)
{
	this->x = x;
	this->y = y;
	Vx = 0;
	Vy = 0;
	this->Vx = ZOOMER_VX;

	Size = new GTexture(ZOOMER_IMAGE_FILE, 2, 1, 2);
	ObjectSprite = new GSprite(Size, ZOOMER_FRAME);

	IsGoing = 0;
	Trend = -1;
}

void Zoomer::Update(GCamera *camera,int t)
{
	x += Vx;
	y += Vy;
	
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (IsGoing != 0)
	{
		
		if (pos.x <= 0) this->MoveRigh();
		if (pos.x >= G_ScreenWidth) this->MoveLeft();
		
		ObjectSprite->Update(t);
	}

}

void Zoomer::DrawObject(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (Trend == -1) ObjectSprite->Draw(pos.x, pos.y);
	else ObjectSprite->DrawFlipX(pos.x, pos.y); 
	
}

