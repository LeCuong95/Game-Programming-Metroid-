#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <d3dx9.h>
#include "GSprite.h"
#include "GCamera.h"


class Weapon
{
protected:
	float samus_x, samus_y;
	float Vx;	// Vận tốc theo trục X
	float Vy;	// Vận tốc theo trục Y

	float Speed; // Tốc độ

	int Trend;		// Phương hướng, trái = -1, phải = 1;
	int DefaultTrend;

	int IsFinish;
	int TypeWeapon;

public:
	float x;	// Vị trí theo trục X
	float y;	// Vị trí theo trục Y#pragma once
	Weapon();
	~Weapon();							// Hàm hủy Weapon

	GSprite* WeaponSprite;
	GTexture* Size;

	int GetTrend();
	void SetTrend(int a);

	virtual void Create(float sm_x, float sm_y, int sm_trend);
	virtual void Update(GCamera *camera, int t);
	
	virtual void DrawWeapon(GCamera *camera);
	virtual void SetXY(float x, float y);

	virtual void SetTypeMorningStar(int i = -1);
	virtual int GetTypeMorningStar();

	virtual int GetFinish();
	virtual void SetFinish();

	int GetType();

	virtual void Boom();

	int BumeranColide;

	int IsFalling; //Dùng trong con rắn medusa

	virtual void BumeranBack(); // Dùng khi bumeran va chạm với tường
};

#endif
