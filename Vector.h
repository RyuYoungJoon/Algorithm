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
