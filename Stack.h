#pragma once
#include <vector>
using namespace std;
template<typename T, typename Container = vector<T>>
class Stack
{
public:
	void push(const T& value)
	{
		m_Container.push_back(value);
	}
	// �ѹ��� ���� ���� ���� -> �����̽�
	// pop���� �����͸� ���� �� ������ �����͸� ������ �۾�, top�� pop�� ���� �۾� ���� �ʴ� ����.
	// ���� �̽� + exception �̽�
	// �����͸� �����ϸ� �� �̻� ��ȿ�� �����Ͱ� �ƴѵ� �̰� ������ �����ؼ� �Ѱ��ָ� ���� ������尡 �߻�.
	/*T pop()
	{
		T ret = m_Data[m_Size - 1];
		m_Size--;
		return ret;
	}*/

	void pop()
	{
		m_Container.pop_back();
	}

	T& top()
	{
		return m_Container.back();
	}

	bool empty() { return m_Container.empty(); }
	int size() { return m_Container.size(); }

private:
	//list<T> m_Container;
	//vector<T> m_Container;
	Container m_Container;
};