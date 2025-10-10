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
// ��ȯ������ �������
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
		// TODO : �� á���� üũ
		if (m_Size == m_Container.size())
		{
			// ���� �۾�
			int newSize = max(1, m_Size * 2);
			vector<T> newData;
			newData.resize(newSize);

			// ������ ����

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

		// ����� �� ���� ������ �������� �� ó������ ���ư��� ���� 
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
		// TODO : �����Ͱ� �ִ��� ����üũ

		return m_Container[m_Front];
	}

	bool empty() { return m_Size == 0; }
	int size() { return m_Size; }

private:
	vector<T> m_Container;

	int m_Front = 0; // �迭�� �ε����� ��Ÿ��.
	int m_Back = 0;
	int m_Size = 0;
};