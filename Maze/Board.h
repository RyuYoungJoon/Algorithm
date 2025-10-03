#pragma once

#include "ConsoleHelper.h"

class Player;

enum
{
	BOARD_MAX_SIZE = 100
};

enum class TileType
{
	NONE = 0,
	EMPTY,
	WALL,
};

class Board
{
public:
	Board();
	~Board();

	void			Init(int32 size, Player* player);
	void			Render();
	
	void			GenerateMap();
	TileType		GetTileType(Pos pos);
	ConsoleColor	GetTileColor(Pos pos);

	Pos				GetEnterPos() { return Pos{ 1,1 }; }
	Pos				GetExitPos() { return Pos{ m_Size - 2, m_Size - 2 }; }


private:
	TileType m_Tile[BOARD_MAX_SIZE][BOARD_MAX_SIZE];
	int32 m_Size = 0;
	Player* m_Player = nullptr;
};

