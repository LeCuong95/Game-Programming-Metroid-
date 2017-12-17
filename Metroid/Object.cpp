#include "Object.h"

Object::Object()
{

}

Object::~Object()
{
	if (ObjectSprite) delete ObjectSprite;
	if (Size) delete Size;
}

int Object::GetID() { return id; }
float Object::GetX() { return x; }
float Object::GetY() { return y; }
float Object::GetWidth() { return Size->FrameWidth; }
float Object::GetHeight() { return Size->FrameHeight; }
void Object::SetX(float a) { x = a; }
void Object::SetY(float b) { y = b; }

float Object::GetVx()
{
	if (IsGoing == 1) return Vx;
	return 0;
}
float Object::GetVy()
{
	if (IsFalling == 1 || IsJumping == 1) return Vy;
	return 0;
}

int Object::GetMoving() { return IsGoing; }
void Object::SetMoving(int a) { IsGoing = a; }

int Object::GetTrend() { return Trend; }
void Object::SetTrend(int a) { Trend = a; }

int Object::GetFalling()
{
	return IsFalling;
}
int Object::GetJumping()
{
	return IsJumping;
}

int Object::GetType() { return Type; }

int Object::GetAlive()
{
	return Health;
}

void Object::SetAlive(int t)
{

}

void Object::Update(GCamera *camera, int t) {}

void Object::DrawObject(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (IsHurting)
	{
		IsHurting--;
		if (Type == 40)  
		{
			if (!IsDraw)
			{
				IsDraw = true;
				return;
			}
			else
			{
				IsDraw = false;
			}
		}
	}
	else EndHurt = 1;

	if (Trend == -1) ObjectSprite->Draw(pos.x, pos.y);
	else ObjectSprite->DrawFlipX(pos.x, pos.y);
}

int Object::GetAttacking()
{
	return IsAttacking;
}

void Object::LookAbove()
{
	IsLookAbove = 1;
	IsSitting = 0;
}

void Object::MoveLeft()
{
	Trend = -1;
}

void Object::MoveRigh()
{
	Trend = 1;
}

void Object::Stop()
{
	
	IsGoing = 0;
	Vx = 0;
}

void Object::Sit()
{
	IsSitting = 1;
	IsFalling = 0;
	IsJumping = 0;
	IsAttacking = 0;
}

void Object::StandUp()
{
	IsFalling = 0;
	IsJumping = 0;
	IsGoing = 0;
}

void Object::Fall()
{
	IsFalling = 1;
	IsJumping = 0;
	
}

void Object::StopFall(float y)
{
}

void Object::Jump()
{
	IsJumping = 1;
	IsFalling = 0;
	IsSitting = 0;
}

void Object::Attack(Weapon *weapon)
{
	IsAttacking = 1;
	if (weapon) weapon->Create(x, y, Trend);
}

void Object::Go()
{
	IsFalling = 0;
	IsJumping = 0;
	IsGoing = 1;
}

void Object::SetId(int a)
{
	id = a;
}


void Object::ResetObj()
{
	Trend = DTrend;
	x = Dx;
	y = Dy;
}


void Object::Hurting()
{
	IsDraw = true;
	IsHurting = 1;
}

void Object::SetAnimation(float Vx, float Vy, int Frame)
{
	this->Vx = Vx*Trend;
	this->Vy = Vy;
	this->ObjectSprite->_timeAni = Frame;
}


int Object::GetHurt()
{
	if (IsHurting) return 1;
	return 0;
}

void Object::SetHurt(int i)
{
	IsHurting = i;
}

int Object::CreateWeapon()
{
	return 0;
}

void Object::SetCreateWeapon()
{
}

void Object::GetSMPositionForBoss(float x, float y, int Trend)
{
}

void Object::ResetPosition()
{
	x = Dx;
	y = Dy;
	Trend = DTrend;
	Stop();
}

void Object::BackupPosition()
{
	Dx = x;
	Dy = y;
	DTrend = Trend;
}



