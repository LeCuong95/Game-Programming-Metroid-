#ifndef _BULLET_H_
#define _BULLET_H_

#include <d3dx9.h>
#include "GSprite.h"
#include "Weapon.h"

#define BULLET_IMAGE_FILE "Resources/weapon/bullet.png"
#define BULLET_VX 8

class bullet : public Weapon
{
public:
	bullet();
	~bullet();
	virtual void Update(GCamera *camera, int t);
	virtual void Create(float sm_x, float sm_y, int sm_trend);
	
};
#endif

