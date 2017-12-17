#ifndef _SCENEMAIN_H_
#define _SCENEMAIN_H_

#include <vector>
#include "Game.h"
#include "GSprite.h"
#include "Object.h"
#include "Samus.h"
#include "Map.h"
#include "GCamera.h"
#include "Zoomer.h"
#include "bullet.h"
#include "CameraObj.h"
#include "Gfont.h"


class SceneMain : public CGame
{
public:
	GFont *Arial;

	int LevelTime;
	CameraObj *CObj;
	GCamera *camera;
	Map *map;
	Samus * samus;
	vector<Weapon*> Weapons;
	

	Zoomer * zoomer1;
	Zoomer * zoomer2;
	bullet * _bullet;
	SceneMain(int _nCmdShow);
	~SceneMain();

protected:
	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t);
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);

	virtual void OnKeyDown(int KeyCode);

	void LoadScene0();
	void LoadScene1();
};

#endif