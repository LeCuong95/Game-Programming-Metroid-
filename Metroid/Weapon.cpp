#include "Weapon.h"

Weapon::Weapon()
{
	IsFinish = 1;
}

Weapon::~Weapon()
{
	delete WeaponSprite;
	delete Size;
}

void Weapon::Update(GCamera *camera, int t)
{

}

void Weapon::Create(float sm_x, float sm_y, int sm_trend)
{
	this->x = sm_x;
	this->y = sm_y;
	Trend = sm_trend;
	IsFinish = 0;
	WeaponSprite->Reset();

}

void Weapon::DrawWeapon(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (Trend == DefaultTrend) WeaponSprite->Draw(pos.x, pos.y);
	else WeaponSprite->DrawFlipX(pos.x, pos.y);
}

int Weapon::GetTrend()
{
	return Trend;
}

void Weapon::SetTrend(int a)
{
	Trend = a;
}

void Weapon::SetXY(float x, float y)
{
	samus_x = x;
	samus_y = y;
}

void Weapon::SetTypeMorningStar(int i)
{
}

int Weapon::GetTypeMorningStar()
{
	return 0;
}

int Weapon::GetFinish()
{
	return IsFinish;
}

void Weapon::SetFinish()
{
	IsFinish = 1;
}

int Weapon::GetType()
{
	return TypeWeapon;
}

void Weapon::Boom()
{
}

void Weapon::BumeranBack()
{
}

