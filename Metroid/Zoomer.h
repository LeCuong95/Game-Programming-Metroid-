
#ifndef _IRONMAN_H_
#define _IRONMAN_H_

#include <d3dx9.h>
#include "GSprite.h"
#include "Object.h"

#define ZOOMER_IMAGE_FILE "Resources/enemy/0.png"
#define ZOOMER_TREND 1
#define ZOOMER_FRAME 100
#define ZOOMER_X 1350
#define ZOOMER_Y 85
#define ZOOMER_VX 3.0f
#define ZOOMER_GRAVITY 20
#define ZOOMER_FALL 180
#define ZOOMER_VX_DAMAGED 150
#define ZOOMER_VY_DAMAGED 450

class Zoomer : public Object
{
public:
	Zoomer();
	Zoomer(float x, float y);
	~Zoomer();

	virtual void Update(GCamera *camera,int t);
	virtual void DrawObject(GCamera *camera);
};
#endif
