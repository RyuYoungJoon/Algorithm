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
	// 한번에 하지 않은 이유 -> 성능이슈
	// pop에서 데이터를 제거 후 제거한 데이터를 꺼내는 작업, top과 pop을 섞은 작업 하지 않는 이유.
	// 성능 이슈 + exception 이슈
	// 데이터를 제거하면 더 이상 유효한 데이터가 아닌데 이걸 데이터 복사해서 넘겨주면 복사 오버헤드가 발생.
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