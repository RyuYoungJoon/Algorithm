#include <iostream>
#include "Vector.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

// [ ][ ][ ][ ][ ][ ][ ][ ]

// DFS (Depth First Search) 깊이 우선 탐색
// 일종의 전선이라고 생각한다면, 보스방이라고 생각한다면
// 0번방부터 입장한다. 그리고 1번방 잡고 2번방 잡고 그 길 없으면 1번 돌아와서 3번방 4번방 쭉쭉쭉 끝날때까지 깊게 들어감.


// BFS (Breadth First Search) 너비 우선 탐색
// 굉장히 신중한 아이
// 0번방 입장하면 1번방으로 들어감. 그 이후 더 이상 들어가지 않음.
// 다시 0번방으로 돌아가서 입구랑 연결되어있는 방으로 들어가서 보스를 잡으려고 한다.
// 안전하게 쉬운곳부터 격파하는 아이.

struct Vertex
{
    // int data;

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

vector<bool> visited;

void CreateGraph()
{
    vertices.resize(6);
    adjacent = vector<vector<int>>(6);

    // 인접 리스트
    adjacent[0].push_back(1);
    adjacent[0].push_back(3);
    adjacent[1].push_back(0);
    adjacent[1].push_back(2);
    adjacent[1].push_back(3);
    adjacent[3].push_back(4);
    adjacent[5].push_back(4);

    // 인접 행렬
    /*adjacent = vector<vector<int>>
    {
        {0,1,0,1,0,0},
        {1,0,1,1,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,0,0},
        {0,0,0,0,1,0},
    };*/
}

// DFS
// here : 시작 위치

// Dfs(0)
// - Dfs(1)
// -- Dfs(2)
// -- Dfs(3)
// -- Dfs(4)
// - Dfs(3)


void Dfs(int here)
{
    // 방문!
    visited[here] = true;
    cout << "Visited : " << here << endl;

    // 인접 리스트 version
    // 모든 인접 정점을 순회한다.
    /*for (int i = 0; i < adjacent[here].size(); ++i)
    {
        int there = adjacent[here][i];

        if (visited[there] == false)
        {
            Dfs(there);
        }
    }*/

    // 인접 행렬 버전
    // 모든 인접 정점을 순회한다.
    for (int there = 0; there < 6; there++)
    {
        if (adjacent[here][there] == 0)
            continue;

        // 아직 방문하지 않은 곳이 있으면 방문한다.
        if (visited[there] == false)
            Dfs(there);
    }
}

void DfsAll()
{
    visited = vector<bool>(6, false);

    for (int i = 0; i < 6; ++i)
    {
        if (visited[i] == false)
            Dfs(i);
    }
}

void CreateGraph_1()
{
    struct Vertex
    {
        vector<Vertex*> edges;
        // int data'
    };

    vector<Vertex> v;
    v.resize(6);

    v[0].edges.push_back(&v[1]);
    v[0].edges.push_back(&v[3]);

    v[1].edges.push_back(&v[0]);
    v[1].edges.push_back(&v[2]);
    v[1].edges.push_back(&v[3]);
    
    v[3].edges.push_back(&v[4]);
    
    v[5].edges.push_back(&v[4]);

    // Q 0번 -> 3번 정점이 연결되어 있나요?
    bool connected = false;
    for (Vertex* edge : v[0].edges)
    {
        if (edge == &v[3])
        {
            connected = true;
            break;
        }
    }

}

void CreateGraph_2()
{
    struct Vertex
    {
        // int data;
    };

    vector<Vertex> v;
    v.resize(6);

    // 연결된 목록을 따로 관리
    // adjacent[n] -> n번째 정점과 연결된 정점 목록
    vector<vector<int>> adjacent(6);

    adjacent[0] = { 1,3 };
    adjacent[1] = { 0,2,3 };
    adjacent[3] = { 4 };
    adjacent[5] = { 4 };

    // 정점이 100개
    // - 지하철 노선도 -> 서로 드문 드문 연결 (양옆, 환승역이라면 조금 더 ++)
    // - 페이스북 친구 -> 서로 빽빽하게 연결
    // 이러면 이 방법은 힘들다..

    // Q 0번 -> 3번 정점이 연결되어 있나요?
    bool connected = false;
    for (int vertex : adjacent[0])
    {
        if (vertex == 3)
        {
            connected = true;
            break;
        }
    }

    // STL
    vector<int>& adj = adjacent[0];
    bool connected2 = (std::find(adj.begin(), adj.end(), 3) != adj.end());
}

void CreateGraph_3()
{
    struct Vertex
    {
        // int data;
    };

    vector<Vertex> v;
    v.resize(6);

    // 연결된 목록을 따로 관리
    // 연결 되어있는건 o, 연결 안되어있는건 X
    // [X][O][X][O][X][X]
    // [0][X][O][O][X][X]
    // [X][X][X][X][X][X]
    // [X][X][X][X][0][X]
    // [X][X][X][X][X][X]
    // [X][X][X][X][O][X]
    //
    // 읽는 방법 : adjacant[from][to]
    // 행렬을 이용한 그래프 표현 (2차원 배열)
    // 메모리 소모가 심하지만, 빠른 접근이 가능하다.
    // 간선이 많은 경우 이점이 있다.

    vector<vector<bool>> adjacent(6, vector<bool>(6, false));
    adjacent[0][1] = true;
    adjacent[0][3] = true;
    adjacent[1][0] = true;
    adjacent[1][2] = true;
    adjacent[1][3] = true;
    adjacent[3][4] = true;
    adjacent[5][4] = true;

    // 정점이 100개
    // - 지하철 노선도 -> 서로 드문 드문 연결 (양옆, 환승역이라면 조금 더 ++)
    // - 페이스북 친구 -> 서로 빽빽하게 연결
    // 이러면 이 방법은 힘들다..

    // Q 0번 -> 3번 정점이 연결되어 있나요?
    bool connected = adjacent[0][3];

    // 가중치 버전
    vector<vector<int>> adjacent2 =
    {
        vector<int> {-1, 15, -1, 35, -1, -1},
        vector<int> {15, -1, 5, 10, -1, -1},
        vector<int> {-1, -1, -1, -1, -1, -1},
        vector<int> {-1, -1, -1, -1, 5, -1},
        vector<int> {-1, -1, -1, -1, -1, -1},
        vector<int> {-1, -1, -1, -1, 5, -1},
    };

}

int main()
{
    // 그래프
    CreateGraph_1();
    CreateGraph_2();
    CreateGraph_3();
    CreateGraph();

    //Dfs(0);
    DfsAll();
}

