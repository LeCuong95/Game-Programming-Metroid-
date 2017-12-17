#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <d3dx9.h>
#include "GSprite.h"
#include "GCamera.h"
#include "Weapon.h"

class Object
{
protected:
	int id;
	float x;	// Vị trí theo trục X
	float y;	// Vị trí theo trục Y

	int IsGoing;		// Đang di chuyển = 1; Đứng yên = 0;
	int IsAttacking;
	int IsStopping;
	int IsJumping;
	int IsSitting;
	int IsLookAbove;
	int IsFalling;
	int DefaultTrend;
	int Trend;		// Phương hướng, trái = -1, phải = 1;
	int PreAtk;
	int IsHurting;
	int EndHurt;

	int IsDraw;

	Weapon* weapon;
	int Type; //Loại đối tượng

	int DTrend;
	float Dx;
	float Dy;

public:
	GTexture* Size;
	GSprite* ObjectSprite;

	float Vx;	// Vận tốc theo trục X
	float Vy;	// Vận tốc theo trục Y

	int Water;
	Object();
	~Object();	// Hàm hủy Object

	int GetID();
	float GetX();
	float GetY();
	virtual float GetWidth();
	virtual float GetHeight();

	void SetX(float);
	void SetY(float);

	float GetVx();
	float GetVy();

	int GetMoving();
	void SetMoving(int a);

	int GetAttacking();

	int GetTrend();
	void SetTrend(int a);
	int GetFalling();
	int GetJumping();
	int GetType();
	int GetAlive();
	void SetAlive(int t);

	void SetId(int a);
	virtual void ResetObj();
	virtual void Stop();
	virtual void Sit();
	virtual void StandUp();
	virtual void Fall();
	virtual void StopFall(float y);
	virtual void Jump();
	virtual void Go();
	virtual void Attack(Weapon *weapon = NULL);
	virtual void MoveLeft();
	virtual void MoveRigh();
	virtual void LookAbove();
	virtual void Update(GCamera *camera, int t);
	virtual void DrawObject(GCamera *camera);

	void FitPosision();
	void Hurting();
	void SetAnimation(float Vx, float Vy, int Frame);

	int GetHurt();
	void SetHurt(int i = 30);

	virtual int CreateWeapon();
	virtual void SetCreateWeapon();
	virtual void GetSMPositionForBoss(float x, float y, int Trend);

	virtual void ResetPosition();
	virtual void BackupPosition();
	int Health;
	int DHealth;

};

#endif
