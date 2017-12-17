#include "Gfont.h"
#include "Game.h"
#include <string>
using namespace std;

GFont::GFont(int size)
{
	_Font = NULL;
	Initialize(size);
}

GFont::GFont(int a, float x, float y)
{
	_Font = NULL;
	Initialize(22);
	this->Number = a;
	this->x = x;
	this->y = y;
	IsFinish = -30;
}

GFont::~GFont()
{
	if (_Font != NULL)
	{
		_Font->Release(); //release font
		_Font = NULL;
	}
}

void GFont::Initialize(int size)
{
	_FontPosition.top = 0;
	_FontPosition.left = 0;
	_FontPosition.right = G_ScreenWidth;
	_FontPosition.bottom = G_ScreenHeight;
	D3DXFONT_DESC FontDesc = { size,
		0,
		400,
		0,
		false,
		DEFAULT_CHARSET,
		OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_PITCH, "Arial" };

	//create font
	D3DXCreateFontIndirect(G_Device, &FontDesc, &_Font);
}

void GFont::Onlost()
{
	_Font->OnLostDevice();
	_Font->OnResetDevice();
}

void GFont::Render(char* text, float x, float y, D3DCOLOR color)
{
	_FontPosition.left = x;
	_FontPosition.top = y;
	_Font->DrawText(NULL,
		text,
		-1,
		&_FontPosition,
		NULL,
		color); //draw text
}

void GFont::Render(GCamera *camera)
{
	Onlost();
	IsFinish++;
	D3DXVECTOR2 pos = camera->Transform(x, y);
	_FontPosition.left = pos.x;
	_FontPosition.top = pos.y;
	_Font->DrawText(NULL,
		(char*)to_string(/*Number*/1000).c_str(),
		-1,
		&_FontPosition,
		NULL,
		D3DCOLOR_ARGB(255, 255, 255, 255)); //draw text
}

int GFont::GetFinish()
{
	if (IsFinish > 0) return 1;
	return 0;
}