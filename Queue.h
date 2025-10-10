#pragma once
#include <list>
#include <vector>

using namespace std;

class Queue
{
public:
	Queue();
	~Queue();
};

template<typename T>
class ListQueue
{
public:
	void push(const T& value)
	{
		m_Container.push_back(value);
	}

	void pop()
	{
		m_Container.pop_front();
	}

	T& front()
	{
		return m_Container.front();
	}

	bool empty() { return m_Container.empty(); }
	int size() { return m_Container.size(); }

private:
	list<T> m_Container;
};


// [front][back][][][][][][][][][][]
// 순환구조로 만들거임
template<typename T>
class ArrayQueue
{
public:
	ArrayQueue()
	{
		//m_Container.resize(100);
	}

	void push(const T& value)
	{
		// TODO : 다 찼는지 체크
		if (m_Size == m_Container.size())
		{
			// 증설 작업
			int newSize = max(1, m_Size * 2);
			vector<T> newData;
			newData.resize(newSize);

			// 데이터 복사

			for (int i = 0; i < m_Size; ++i)
			{
				int index = (m_Front + i) % m_Container.size();
				newData[i] = m_Container[index];
			}

			m_Container.swap(newData);
			m_Front = 0;
			m_Back = m_Size;
		}


		m_Container[m_Back] = value;

		// 사이즈가 다 차도 나머지 연산으로 맨 처음으로 돌아가게 만듬 
		m_Back = (m_Back + 1) % m_Container.size();
		m_Size++;
	}

	void pop()
	{
		m_Front = (m_Front + 1) % m_Container.size();
		m_Size--;
	}

	T& front()
	{
		// TODO : 데이터가 있는지 예외체크

		return m_Container[m_Front];
	}

	bool empty() { return m_Size == 0; }
	int size() { return m_Size; }

private:
	vector<T> m_Container;

	int m_Front = 0; // 배열의 인덱스를 나타냄.
	int m_Back = 0;
	int m_Size = 0;
};