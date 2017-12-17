#include "CameraObj.h"


CameraObj::CameraObj()
{
}

CameraObj::CameraObj(float x, float y, float w, float h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}


CameraObj::~CameraObj()
{
}

void CameraObj::SetCameraObj(float x, float y, float w, float h)
{
	this->x = x + w / 2;
	this->y = y - h / 2;
	this->w = w;
	this->h = h;
}

float CameraObj::GetWidth()
{
	return w;
}

float CameraObj::GetHeight()
{
	return h;
}
