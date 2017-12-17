#ifndef GFONT_H
#define GFONT_H

#include <d3dx9.h>
#include <iostream>
#include "Game.h"
#include "Global.h"
#include "GCamera.h"

using namespace std;

class GFont
{
private:
	LPD3DXFONT	_Font;
	RECT		_FontPosition;

	float x, y;
	int Number;
	int IsFinish;

public:
	GFont(int size = 22);
	GFont(int a, float x, float y);
	~GFont();
	void Initialize(int size = 22);
	void Render(char* text, float x, float y, D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255));
	void Render(GCamera *camera);
	int GetFinish();
	void Onlost();
};
#endif