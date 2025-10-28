#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <stack>

void Player::Init(Board* board)
{
	m_Pos = board->GetEnterPos();
	m_Board = board;

	//RightHand();
	Bfs();
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

void Player::RightHand()
{
	
	Pos pos = m_Pos;

	m_Path.clear();
	m_Path.push_back(pos);

	// 목적지 도착하기 전에는 계속 실행
	Pos dest = m_Board->GetExitPos();

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

	stack<Pos> s;

	for (int i = 0; i < m_Path.size() - 1; ++i)
	{
		// s.top() == m_Path[i+1]의 의미
		// 내가 가는길을 stack에 옮기고 있었다.
		// 근데 가는 길에서 다음 다음번째 길이 s.top()과 같다?
		// 이 말은 다음 길로 갔는데 그 길이 막다른 길이어서 다시 뒤로 갔다.
		// 즉 다다음번 길이 top이랑 같다.
		// 그럼 이건 다시 되돌아오고 있다는 뜻이니까 다 pop을 해줘서 없애버린다!
		if (s.empty() == false && s.top() == m_Path[i + 1])
			s.pop();
		else
			s.push(m_Path[i]);
	}

	// 목적지 도착
	if (m_Path.empty() == false)
		s.push(m_Path.back());

	vector<Pos> path;
	while (s.empty() == false)
	{
		path.push_back(s.top());
		s.pop();
	}

	std::reverse(path.begin(), path.end());

	m_Path = path;
}

void Player::Bfs()
{
	Pos pos = m_Pos;

	m_Path.clear();
	m_Path.push_back(pos);

	// 목적지 도착하기 전에는 계속 실행
	Pos dest = m_Board->GetExitPos();
	
	Pos front[4] =
	{
		Pos {-1, 0},	 // UP
		Pos {0, -1},	// LEFT
		Pos {1, 0},		// DOWN
		Pos {0, 1}		// RIGHT
	};

	const int32 size = m_Board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size,false));

	//vector<vector<Pos>> parent;
	
	// parent[A] = B; -> A는 B로 인해 발견함
	map<Pos, Pos> parent;

	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		// 방문!
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < 4; dir++)
		{
			Pos nextPos = pos + front[dir];
			// 갈 수 있는 지역은 맞는지 확인.
			if (CanGo(nextPos) == false)
				continue;

			// 이미 발견한 지역인지 확인.
			if (discovered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos] = pos;
		}
	}
	
	// TODO
	m_Path.clear();
	
	// 거꾸로 거슬러 올라간다.
	pos = dest;
	while (true)
	{
		m_Path.push_back(pos);

		// 시작점은 자신이 곧 부모이다.
		if (pos == parent[pos])
			break;

		pos = parent[pos];
	}


	std::reverse(m_Path.begin(), m_Path.end());
	
}
