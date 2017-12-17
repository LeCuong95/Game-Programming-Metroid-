#ifndef _MAP_H_
#define _MAP_H_

#include <stdio.h>
#include <conio.h>
#include "GSprite.h"
#include "GTexture.h"
#include "GCamera.h"
#include "Global.h"

class Map
{
private:
	GTexture *TileTexture;

	int ScreenColumn;
	int ScreenRow;
	int RowMatrix;
	int ColumnMatrix;
	int ColTile;
	int RowTile;
	int CountTileFrame;
	int TileMap[500][500];

	int row, column;
	int x, y;

public:
	GSprite *Tile;
	Map();
	~Map();
	void ReadMatrix(char * filename);
	void LoadMap();
	void DrawMap(GCamera *camera);
};

#endif
