#pragma once

class Board;

class Player
{
	enum
	{
		MOVE_TICK = 100
	};

public:
	void	Init(Board* board);
	void	Update(uint64 deltaTick);

	void	SetPos(Pos pos) { m_Pos = pos; }
	Pos		GetPos() { return m_Pos; }

	bool	CanGo(Pos pos);

private:
	Pos			m_Pos = {};
	int32		m_Dir = DIR_UP;
	Board*		m_Board = nullptr;

	vector<Pos> m_Path;
	uint32		m_PathIndex = 0;
	uint64		m_SumTick = 0;
};

