
#ifndef _IRONMAN_H_
#define _IRONMAN_H_

#include <d3dx9.h>
#include "GSprite.h"
#include "Object.h"

#define IRONMAN_IMAGE_FILE "Resources/enemy/5.png"
#define IRONMAN_TREND 1
#define IRONMAN_FRAME 100
#define IRONMAN_STOP_IMAGE 3
#define IRONMAN_X 50
#define IRONMAN_Y 64

#define IRONMAN_VX 3.0f

#define IRONMAN_GRAVITY 20
#define IRONMAN_FALL 180
#define IRONMAN_VX_DAMAGED 150
#define IRONMAN_VY_DAMAGED 450

class IronMan : public Object
{
public:
	IronMan();
	IronMan(float x, float y);
	~IronMan();

	virtual void Update(GCamera *camera,int t);
	virtual void DrawObject(GCamera *camera);
};
#endif
