#ifndef _Samus_H_
#define _Samus_H_

#include <d3dx9.h>
#include "GSprite.h"
#include "Object.h"
#include "bullet.h"

#define SAMUS_IMAGE_FILE "Resources/p1.png"
#define SAMUS_TREND 0
#define SAMUS_FRAME 30


#define SAMUS_STOP_IMAGE 5
#define SAMUS_LOOK_ABOVE_IMAGE 4
#define SAMUS_STAND_ATK_IMAGE 18
#define SAMUS_GO_ATK_IMAGE 19
#define SAMUS_SIT_IMAGE 9
#define SAMUS_JUMP_IMAGE 9
#define SAMUS_JUMP_ATK_IMAGE 22

#define SAMUS_X 1300
#define SAMUS_Y 110

#define SAMUS_VX 8.0f
#define SAMUS_VJUMP 30
#define SAMUS_GRAVITY 3
#define SAMUS_FALL 10
#define SAMUS_VX_DAMAGED 150
#define SAMUS_VY_DAMAGED 450

class Samus : public Object
{
	
public:
	int WaitingCount; //dùng trong intro
	int IntoCastle(int t);

	int SamusFall = 0;
	Samus();
	~Samus();

	virtual void LookAbove();
	virtual void Sit();
	virtual void StandUp();
	virtual void Jump();
	virtual void Fall();
	virtual void Go();
	virtual void Stop();
	virtual void StopFall(float y);
	virtual void Attack(Weapon *weapon = NULL);
	virtual void Update(GCamera *camera,int t);
	virtual void DrawObject(GCamera *camera);
};
#endif
