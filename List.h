#pragma once
#include "List.h"
using namespace std;
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
    Node* m_Prev;
    Node* m_Next;
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
        while (m_Size > 0)
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
    Node<T>* m_Head;
    Node<T>* m_Tail;
    int         m_Size;

};