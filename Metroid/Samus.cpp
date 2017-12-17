#include "Samus.h"

Samus::Samus()
{
	Vx = 0;
	Vy = 0;
	
	Size = new GTexture(SAMUS_IMAGE_FILE, 29, 1, 29);
	ObjectSprite = new GSprite(Size, SAMUS_FRAME);

	this->x = SAMUS_X;  
	this->y = SAMUS_Y;

	this->Vx = SAMUS_VX;
	IsGoing = 0;
	Trend = SAMUS_TREND;
}

Samus::~Samus() {}

void Samus::Update(GCamera *camera,int t)
{
	if (IsAttacking == 1) //Đang ở trạng thái tấn công
	{
		ObjectSprite->Update(t);
		if (IsGoing == 1) //Tấn công khi đang di
		{
			x += Vx;
			D3DXVECTOR2 pos = camera->Transform(x, y);
			if (pos.x <= Size->FrameWidth / 4 || pos.x > G_ScreenWidth - Size->FrameWidth / 4) x -= Vx;
			if (IsLookAbove == 1)
			{
				if (ObjectSprite->_index > 26)
				{
					//ObjectSprite->_index = 24;
					IsAttacking = 0;
					IsLookAbove = 0;
				}
			}
			else
			if (IsJumping == 1) //Tấn công khi đang nhay
			{
				Vx *= IsGoing;
				y += Vy;
				Vy = Vy - SAMUS_GRAVITY;
				if (y == SAMUS_Y) IsJumping = 0;
				ObjectSprite->SelectIndex(SAMUS_JUMP_ATK_IMAGE);
				IsAttacking = 0;
			}
			else
			{
				if (ObjectSprite->_index > 21)
				{
				ObjectSprite->_index = 19;
				IsAttacking = 0;
				}
			}
		}
		else
			if (IsJumping == 1) //Tấn công khi đang nhay
			{
				Vx *= IsGoing;
				y += Vy;
				Vy = Vy - SAMUS_GRAVITY;
				if (y == SAMUS_Y) IsJumping = 0;
				ObjectSprite->SelectIndex(SAMUS_JUMP_ATK_IMAGE);
				IsAttacking = 0;
			}
			else
				if (IsLookAbove == 1)
				{
					ObjectSprite->SelectIndex(SAMUS_LOOK_ABOVE_IMAGE);
					IsLookAbove = 0;
				}
				else
				{
					if (ObjectSprite->_index != 18) IsAttacking = 0;
					ObjectSprite->SelectIndex(SAMUS_STAND_ATK_IMAGE);
				
				}
	}
	else
	{
		if (IsJumping == 1)
		{
			y += Vy;
			x += Vx;
			Vy = Vy - SAMUS_GRAVITY;
			ObjectSprite->SelectIndex(SAMUS_JUMP_IMAGE);
			if (y == SAMUS_Y) IsJumping = 0;
			//if (y > 50) IsJumping = 0;
		}
		else
			if (IsFalling == 1)
			{
				x += Vx;
				y += Vy;
				Vy = Vy - SAMUS_GRAVITY;
				ObjectSprite->SelectIndex(SAMUS_STOP_IMAGE);
				
			}
			else
				if ((IsGoing == 1)&&(IsAttacking == 0))
				{
					x += Vx;
					D3DXVECTOR2 pos = camera->Transform(x, y);
					if (pos.x <= Size->FrameWidth / 4 || pos.x > G_ScreenWidth - Size->FrameWidth / 4) x -= Vx;
					ObjectSprite->Update(t);
					if (IsFalling == 0 && IsJumping == 0 && IsLookAbove == 0 && IsSitting == 0) ObjectSprite->_index = ObjectSprite->_index % 3 + 6;

				
					if (IsLookAbove == 1)
					{
						ObjectSprite->_index = ObjectSprite->_index % 3 + 24;
						IsLookAbove = 0;
					}
					if (IsSitting == 1)
					{
						if (ObjectSprite->_index > 17) ObjectSprite->_index = 14;
					}
				}
				else
					if (IsSitting == 1)
					{
						ObjectSprite->Update(t);
						if (ObjectSprite->_index > 17) ObjectSprite->_index = 14;
						
					}
					else
						if (IsLookAbove == 1) 
						{
							ObjectSprite->SelectIndex(SAMUS_LOOK_ABOVE_IMAGE);
							IsLookAbove = 0;
						}
						else
						{
							if (LoadSamus == 0)
							{ 

								ObjectSprite->Update(1.9);
								if (ObjectSprite->_index > 3)
								{

									ObjectSprite->SelectIndex(3);
								}
							}
							else
							ObjectSprite->SelectIndex(SAMUS_STOP_IMAGE);
						}
	}
}

void Samus::DrawObject(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (Trend == -1) ObjectSprite->DrawFlipX(pos.x, pos.y);
	else ObjectSprite->Draw(pos.x, pos.y);
}
void Samus::Jump()
{
	if ( IsJumping == 0 && IsFalling == 0)
	{
		if (IsJumping == 0)
		{
			Vy = SAMUS_VJUMP;
			ObjectSprite->SelectIndex(SAMUS_JUMP_IMAGE);
			Object::Jump();
		}
	}
}
void Samus::Fall()
{
	if (IsAttacking == 0 && IsJumping == 1 && IsFalling == 0)
	{
		if (IsFalling == 0)
		{
			Vy = -SAMUS_VJUMP;
			ObjectSprite->SelectIndex(SAMUS_STOP_IMAGE);
			Object::Fall();
		}
	}
}
void Samus::Sit()
{
	if (IsSitting == 0) {
		ObjectSprite->SelectIndex(SAMUS_SIT_IMAGE);
		Object::Sit();
	}
	else ObjectSprite->SelectIndex(14);
}
void Samus::StandUp()
{
	ObjectSprite->SelectIndex(SAMUS_STOP_IMAGE);
	Object::StandUp();
}
void Samus::Go()
{
	if (IsJumping == 1 || IsFalling == 1) return;
	this->Vx = SAMUS_VX*Trend;
	Object::Go();
}
void Samus::Stop()
{
	//if (IsAttacking == 0)
	{
		//if (IsSitting == 1) this->StandUp();
		Object::Stop();
		return;
	}
}
void Samus::Attack(Weapon *w)
{
	if (IsSitting == 1) return;
	if (EndHurt == 0 && IsFalling == 1) return;
	if (IsAttacking == 1) return;
	if (IsFalling == 1) return;

	if (IsGoing == 1)
	{
		
		if(IsLookAbove == 1) ObjectSprite->SelectIndex(24);
		else
			ObjectSprite->SelectIndex(SAMUS_GO_ATK_IMAGE);
	}
	else
		
		ObjectSprite->SelectIndex(SAMUS_STAND_ATK_IMAGE);
	Object::Attack(w);
}
void Samus::StopFall(float y)
{
	IsAttacking = 0;
	IsFalling = 0;
	this->y = y;
	if (SamusFall) this->Sit();
	else
		if (IsGoing == 1) this->Go();
		else this->StandUp();
		Vy = 0;
}
int Samus::IntoCastle(int t)
{
	this->Stop();
	ObjectSprite->SelectIndex(0);
	WaitingCount = WaitingCount + t;
	if (WaitingCount > 2200) return 1;
	return 0;
}
void Samus::LookAbove()
{
	if (IsAttacking == 1 && IsGoing == 1 && IsLookAbove == 1) ObjectSprite->SelectIndex(24);
	Object::LookAbove();
}