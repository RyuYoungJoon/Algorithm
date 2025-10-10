#pragma once

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
            // ���� �۾�
            int newCapacity = static_cast<int>(m_Capacity * 1.5);
            if (newCapacity == m_Capacity)
                newCapacity++;

            reserve(newCapacity);
        }

        // ������ ����
        m_Data[m_Size] = value;

        // ������ ���� ����
        m_Size++;
    }

    void reserve(int capacity)
    {
        if (m_Capacity >= capacity)
            return;

        m_Capacity = capacity;

        T* newData = new T[m_Capacity];

        // ������ ����
        for (int i = 0; i < m_Size; ++i)
        {
            newData[i] = m_Data[i];
        }

        if (m_Data)
            delete[] m_Data;

        // ��ü
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
    int m_Size = 0;     // ���� ����� ������ ����
    int m_Capacity = 0; // �� �Ҵ� �� ������ ����
};
