#include "Map.h"

Map::Map()
{
	LoadMap();
}

Map::~Map()
{
}

void Map::ReadMatrix(char * filename)
{
	int i, j;
	FILE *file;
	file = fopen(filename, "r");

	fscanf(file, "%d %d %d %d %d %d", &RowMatrix, &ColumnMatrix, &ColTile, &RowTile, &CountTileFrame);
	for (i = 0; i < RowMatrix; i++)
	{
		for (j = 0; j < ColumnMatrix; j++)
		{
			fscanf(file, "%d", &TileMap[i][j]);
		}
	}
	fclose(file);
}

void Map::LoadMap()
{
	
	if (State == 0)
	{
		TileTexture = new GTexture("Resources/intro.png");
	}

	if (State == 1)
	{
		ReadMatrix("Resources/11.B");
		TileTexture = new GTexture("Resources/11.S", ColTile, RowTile, 0);
	}
	
	
	G_MapWidth = (TileTexture->FrameWidth)*(ColumnMatrix*(State > 0) + (State == 0)) + 50;
	G_MapHeight = (TileTexture->FrameHeight)*(RowMatrix*(State > 0) + (State == 0));


	ScreenColumn =(G_ScreenWidth) / TileTexture->FrameWidth + 2;
	ScreenRow = (G_ScreenHeight) / TileTexture->FrameHeight; 
	
	Tile = new GSprite(TileTexture, 0);
	
}

void Map::DrawMap(GCamera* camera)
{
	if (State == 0)
	{
		Tile->DrawRaw(0, 0);
		return;
	}
	row = int(camera->viewport.y) / TileTexture->FrameWidth;
	column = int(camera->viewport.x) / TileTexture->FrameHeight;

	x = -(int(camera->viewport.x) % TileTexture->FrameHeight);
	y = -(int(camera->viewport.y) % TileTexture->FrameHeight);

	for (int i = 0; i < ScreenRow; i++)
	{
		{
			for (int j = 0; j < ScreenColumn; j++)
			{
				if (!(RowMatrix - row + i < 0 || RowMatrix - row + i > RowMatrix))
				{
					Tile->SelectIndex(TileMap[RowMatrix - row + i][column + j]);
					Tile->DrawRaw(x, y);
					x = x + TileTexture->FrameWidth;
				}
			}
		}
		y += TileTexture->FrameHeight;
		x = -int(camera->viewport.x) % TileTexture->FrameHeight;
	}
}




