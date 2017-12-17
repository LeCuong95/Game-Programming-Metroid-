#ifndef _CAMERAOBJ_H_
#define _CAMERAOBJ_H_

#include <d3dx9.h>
#include "GSprite.h"
#include "Object.h"

class CameraObj : public Object
{
	float w, h;
public:
	CameraObj();
	CameraObj(float x, float y, float w, float h);
	~CameraObj();
	void SetCameraObj(float x, float y, float w, float h);
	virtual float GetWidth();
	virtual float GetHeight();
};
#endif
