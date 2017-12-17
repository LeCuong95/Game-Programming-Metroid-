#ifndef _CPlay_H
#define _CPlay_H
#pragma once
#include"GSprite.h"
#include "Object.h"

class CPlay 
{
private:
	GTexture *GTObject;
	GSprite *GSObject;
public:
	CPlay();
	~CPlay();
	void Draw();
	void Update(int t);
	void Set();
};

#endif