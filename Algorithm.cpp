#include <iostream>
#include "Vector.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;


int main()
{
    //// TODO : 내가 직접 Vector 만들어보기
    //vector<int> v;

    //v.reserve(100);

    //v.resize(10);

    //for (int i = 0; i < 100; ++i)
    //{
    //    v.push_back(i);
    //    cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
    //}

    //v.resize(10);


    //v.clear();
    //cout << v.size() << " " << v.capacity() << endl;

    List<int> li;

    List<int>::iterator eraseIt;

    // 리스트 모양
    // [ ] <-> [ ] <-> [ ]
    for (int i = 0; i < 10; ++i)
    {
        if (i == 5)
        {
            eraseIt = li.insert(li.end(), i);
        }
        else
        {
            li.push_back(i);
        }
    }

    // TODO
    // 리스트가 중간삽입 삭제는 빠르다고 하는데 임의 접근은 안된다는게 모순적이지 않나?
    // 이거에 대해 찾아봐야겠다. 
    //
    li.pop_back();

    li.erase(eraseIt);

    for (List<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        cout << (*it) << endl;
    }

    // vector
    // - push_back
    // - push_front
    // [0][1][2][3][ ][ ]
    // list 임의 접근 불가
 

    // Queue

    ArrayQueue<int> q;

    for (int i = 0; i < 100; ++i)
        q.push(i);

    while (q.empty() == false)
    {
        int value = q.front();
        q.pop();
        cout << value << endl;
    }


    int size = q.size();

    // Stack

    Stack<int, list<int>> s;

    // 삽입
    s.push(1);
    s.push(2);
    s.push(3);

    // 최상위 원소

    while (s.empty() == false)
    {
        int data = s.top();

        // 최상위 원소 삭제
        s.pop();

        cout << data << endl;
    }

    //int size = s.size();
}

