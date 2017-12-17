#include "SceneMain.h"
#include <string>

string FullNumber(int a, int max)
{
	string result = to_string(a);
	for (int i = to_string(a).length(); i < max; i++)
	{
		result = "0" + result;
	}
	return result;
}


SceneMain::SceneMain(int _nCmdShow) : CGame(_nCmdShow)
{

}

SceneMain::~SceneMain(void)
{
}


void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	d3ddv->ColorFill(G_BackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));

	// Không đc thay đổi cấu trúc này Samus update => v Samus => v cam 
	
	
	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	map->DrawMap(camera);

	
	if (State == 1)
	{	
		samus->Update(camera, t);
		camera->SetVCam(samus->GetVx());
		camera->SetFolowPos(samus->GetX(), samus->GetY());
		camera->UpdateCamera();

		//if (samus->GetAttacking() == 1) 
		{ 
			_bullet->DrawWeapon(camera);
			_bullet->Update(camera, t); 
		}

		zoomer1->Update(camera, t);
		zoomer2->Update(camera, t);

		

		samus->DrawObject(camera);
		zoomer1->DrawObject(camera);
		zoomer2->DrawObject(camera);
	}

	
	Arial->Render((char*)FullNumber(samus->GetY(), 2).c_str(), 80, 100);
	Arial->Render((char*)FullNumber(samus->GetX(), 2).c_str(), 25, 100);
	Arial->Render((char*)FullNumber(_bullet->GetTrend(), 2).c_str(), 200, 100);
	

	G_SpriteHandler->End();
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	if (State == 0)
	{
		if (IsKeyDown(DIK_RETURN))
		{
			State = 1;
			LoadScene1();
			return;
		}
		return;
	}

	if (IsKeyDown(DIK_LEFT))
		{
			samus->MoveLeft();
			samus->Go();//Đang đánh thì ko được di chuyển hay đổi hướng
		}
	else
			if (IsKeyDown(DIK_RIGHT))
				{
					samus->MoveRigh();
					samus->Go();
				}
			else
				{
					samus->Stop();
				}


	if (IsKeyDown(DIK_NUMPADENTER) || IsKeyDown(DIK_A))
		{
				_bullet->Create(samus->GetX(), samus->GetY(), samus->GetTrend());
				samus->Attack(_bullet);		
		}

	if (IsKeyDown(DIK_UP))
	{
		samus->LookAbove();

	}
	/*if (IsKeyDown(DIK_DOWN))
	{
		samus->Sit();

	}*/
	if (IsKeyDown(DIK_S))
		{
		samus->Jump();
		samus->SamusFall = 0;
		}
}

void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	if (State == 0) LoadScene0();
	if (State == 1) LoadScene1();

	Arial = new GFont();
	
}

void SceneMain::OnKeyDown(int KeyCode)
{
	if (IsKeyDown(DIK_DOWN))
	{
		samus->Sit();
	}
	if (IsKeyDown(DIK_LEFT) || IsKeyDown(DIK_RIGHT) || IsKeyDown(DIK_A) || IsKeyDown(DIK_S) || IsKeyDown(DIK_UP) || IsKeyDown(DIK_DOWN)) LoadSamus = 1;
}



void SceneMain::LoadScene0()
{
	State = 0;
	map = new Map();
	CObj = new CameraObj();
}

void SceneMain::LoadScene1()
{
	CObj = new CameraObj();
	map = new Map();
	camera = new GCamera();
	camera->SetSizeMap(G_MapWidth, 0);

	samus = new Samus();
	
	_bullet = new bullet();
	
	zoomer1 = new Zoomer();
	zoomer1->Go();
	zoomer2 = new Zoomer(1000,100);
	zoomer2->Go();

}