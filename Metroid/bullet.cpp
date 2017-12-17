#include "bullet.h"


bullet::bullet()
{
	//TypeWeapon = 1;
	Size = new GTexture(BULLET_IMAGE_FILE);
	WeaponSprite = new GSprite(Size, 0);
	DefaultTrend = 1;
	
}

bullet::~bullet()
{
}

void bullet::Update(GCamera *camera, int t)
{
	x += Vx;
	WeaponSprite->Update(t);
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (pos.x > G_ScreenWidth || pos.x < -50 || pos.y > G_ScreenHeight + 20) IsFinish = 1;
	
}

void bullet::Create(float sm_x, float sm_y, int sm_trend)
{
	Weapon::Create(sm_x, sm_y, sm_trend);
	Vx = BULLET_VX*Trend;
	
}


