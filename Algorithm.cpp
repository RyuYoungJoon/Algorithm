#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
class Vector
{
public:
    Vector()
    {

    }
    ~Vector()
    {
        if (m_Data)
            delete[] m_Data;
    }

    // [ ][ ][ ][ ][ ][ ][ ]
    // [ ][ ][ ][ ][ ]
    void push_back(const T& value)
    {
        if (m_Size == m_Capacity)
        {
            // 증설 작업
            int newCapacity = static_cast<int>(m_Capacity * 1.5);
            if (newCapacity == m_Capacity)
                newCapacity++;

            reserve(newCapacity);
        }

        // 데이터 저장
        m_Data[m_Size] = value;

        // 데이터 개수 증가
        m_Size++;
    }

    void reserve(int capacity)
    {
        if (m_Capacity >= capacity)
            return;

        m_Capacity = capacity;

        T* newData = new T[m_Capacity];

        // 데이터 복사
        for (int i = 0; i < m_Size; ++i)
        {
            newData[i] = m_Data[i];
        }

        if (m_Data)
            delete[] m_Data;

        // 교체
        m_Data = newData;
    }

    T& operator[](const int pos) { return m_Data[pos]; }

    int size() { return m_Size; }
    int capacity() { return m_Capacity; }

    void clear()
    {
        if (m_Data)
        {
            delete[] m_Data;
            m_Data = new T[m_Capacity];
        }

        m_Size = 0;
    }

private:
    T* m_Data = nullptr;
    int m_Size = 0;     // 현재 사용한 데이터 개수
    int m_Capacity = 0; // 총 할당 된 데이터 개수
};

template<typename T>
class Node
{
public:
    Node() : m_Prev(nullptr), m_Next(nullptr), m_Data(T())
    {

    }
    Node(const T& value) : m_Prev(nullptr), m_Next(nullptr), m_Data(value)
    {

    }

public:
    Node*   m_Prev;
    Node*   m_Next;
    T       m_Data;
};

template<typename T>
class Iterator
{
public:
    Iterator() : m_Node(nullptr)
    {

    }

    Iterator(Node<T>* node) : m_Node(node)
    {

    }

    // ++it
    Iterator& operator++()
    {
        m_Node = m_Node->m_Next;
        return *this;
    }


    // it++
    Iterator operator++(int)
    {
        Iterator<T> temp = *this;
        m_Node = m_Node->m_Next;
        return temp;
    }

    // --it
    Iterator& operator--()
    {
        m_Node = m_Node->m_Prev;
        return *this;
    }

    // it--
    Iterator operator--(int)
    {
        Iterator<T> temp = *this;
        m_Node = m_Node->m_Prev;
        return temp;
    }

    // *it
    T& operator*()
    {
        return m_Node->m_Data;
    }

    bool operator==(const Iterator& other)
    {
        return m_Node == other.m_Node;
    }

    bool operator!=(const Iterator& other)
    {
        return m_Node != other.m_Node;
    }

public:
    Node<T>* m_Node;
};

template<typename T>
class List
{
public:
    List() : m_Size(0)
    {
        // [head] <-> ... <-> [tail]
        m_Head = new Node<T>();
        m_Tail = new Node<T>();
        m_Head->m_Next = m_Tail;
        m_Tail->m_Prev = m_Head;
    }

    ~List()
    {
        while (m_Size> 0)
        {
            pop_back();
        }

        delete m_Head;
        delete m_Tail;
    }

    void push_back(const T& value)
    {
        AddNode(m_Tail, value);
    }

    void pop_back()
    {
        RemoveNode(m_Tail->m_Prev);
    }

private:

    // [head] <-> [1] <-> [2] <-> [prevNode] <-> [before] <->... <-> [tail]
    // [head] <-> [1] <-> [2] <-> [prevNode] <-> [newNode] <-> [before] <->... <-> [tail]

    Node<T>* AddNode(Node<T>* before, const T& value)
    {
        Node<T>* newNode = new Node<T>(value);
        Node<T>* prevNode = before->m_Prev;

        prevNode->m_Next = newNode;
        newNode->m_Prev = prevNode;

        before->m_Prev = newNode;
        newNode->m_Next = before;

        m_Size++;

        return newNode;
    }

    // [head] <-> [1] <-> [prevNode] <-> [Node] <-> [nextNode] <->... <-> [tail]
    // [head] <-> [1] <-> [prevNode] <-> [nextNode] <->... <-> [tail]
    Node<T>* RemoveNode(Node<T>* node)
    {
        Node<T>* prevNode = node->m_Prev;
        Node<T>* nextNode = node->m_Next;

        prevNode->m_Next = nextNode;
        nextNode->m_Prev = prevNode;

        delete node;

        m_Size--;

        return nextNode;
    }

    int size() { return m_Size; }

public:
    using iterator = Iterator<T>;

    iterator begin() { return iterator(m_Head->m_Next); }
    iterator end() { return iterator(m_Tail); }

    // it 앞에 추가.
    iterator insert(iterator it, const T& value)
    {
        Node<T>* node = AddNode(it.m_Node, value);
        return iterator(node);
    }

    iterator erase(iterator it)
    {
        Node<T>* node = RemoveNode(it.m_Node);
        return iterator(node);
    }

private:
    Node<T>*    m_Head;
    Node<T>*    m_Tail;
    int         m_Size;

};


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
    
}

