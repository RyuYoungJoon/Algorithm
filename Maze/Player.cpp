#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	m_Pos = board->GetEnterPos();
	m_Board = board;

	Pos pos = m_Pos;

	m_Path.clear();
	m_Path.push_back(pos);

	// 목적지 도착하기 전에는 계속 실행
	Pos dest = board->GetExitPos();

	while (pos != dest)
	{
		// 1. 현재 바라보는 방향을 기준으로 오른쪽으로 갈 수 있는지 확인
		int32 newDir = (m_Dir - 1 + DIR_COUNT) % DIR_COUNT;

		Pos front[4] =
		{
			Pos {-1, 0},	 // UP
			Pos {0, -1},	// LEFT
			Pos {1, 0},		// DOWN
			Pos {0, 1}		// RIGHT
		};

		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전
			m_Dir = newDir;

			// 앞으로 한 보 전진
			pos += front[m_Dir];

			m_Path.push_back(pos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인.
		else if (CanGo(pos + front[m_Dir]))
		{
			// 앞으로 한 보 전진
			pos += front[m_Dir];

			m_Path.push_back(pos);
		}
		else
		{
			// 왼쪽 방향으로 90도 회전.
			m_Dir = (m_Dir + 1) % DIR_COUNT;
		}
	}


}

void Player::Update(uint64 deltaTick)
{
	if (m_PathIndex >= m_Path.size())
		return;

	m_SumTick += deltaTick;
	if (m_SumTick >= MOVE_TICK)
	{
		m_SumTick = 0;

		m_Pos = m_Path[m_PathIndex];
		m_PathIndex++;
	}

}

bool Player::CanGo(Pos pos)
{
	TileType tileType = m_Board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}
