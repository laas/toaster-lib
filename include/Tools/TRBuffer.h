//
//  TRBuffer.h
//
//  Created by Grégoire Milliez on 07/01/2014.
//
//  This class is using circular_buffer from boost
//  to implement a timed ring buffer (TRBuffer).

#ifndef TRBUFFER_H
#define TRBUFFER_H

#include <boost/circular_buffer.hpp>
#include <iostream>

template <typename T> class TRBuffer {
    boost::circular_buffer<unsigned long> m_TimeBuffer;
    boost::circular_buffer<T> m_DataBuffer;

public:

    TRBuffer() {
        m_TimeBuffer.set_capacity(100);
        m_DataBuffer.set_capacity(100);
    }

    TRBuffer(const size_t capacity) {
        m_TimeBuffer.set_capacity(capacity);
        m_DataBuffer.set_capacity(capacity);
    }

    ~TRBuffer() {
    }

    // Get the number of elements currently stored in the TRBuffer.

    boost::circular_buffer<unsigned long>::size_type size() {
        return m_TimeBuffer.size();
    }
    // Get the maximum number of elements stored in the TRBuffer.

    boost::circular_buffer<unsigned long>::size_type capacity() {
        return m_TimeBuffer.capacity();
    }

    boost::circular_buffer<unsigned long>::size_type max_size() {
        return m_TimeBuffer.max_size();
    }

    bool empty() {
        return m_TimeBuffer.empty();
    }

    bool full() {
        return m_TimeBuffer.full();
    }

    // Insert a new element at the end of the TRBuffer.
    // If TRBuffer is full, the first element will be removed.
    // If the capacity is 0, nothing will be inserted.

    void push_back(unsigned long time, const T &data) {
        m_TimeBuffer.push_back(time);
        m_DataBuffer.push_back(data);
    }

    // Remove the first element from the TRBuffer.

    void pop_front() {
        m_TimeBuffer.pop_front();
        m_DataBuffer.pop_front();
    }

    // Remove all stored elements from the TRBuffer.

    void clear() {
        m_TimeBuffer.clear();
        m_DataBuffer.clear();
    }

    T& back() {
        return m_DataBuffer.back();
    }

    T& front() {
        return m_DataBuffer.front();
    }

    bool getData(unsigned long time, T &data) {
        int result;
        result = getIndex(time);
        if (result < 0)
            return false;
        else {
            data = getDataFromIndex(result);
            return true;
        }
    }

    // Here after means strictly greater time.

    bool getDataAfter(unsigned long time, T &data) {
        int result;
        result = getIndexAfter(time);
        if (result < 0)
            return false;
        else {
            data = getDataFromIndex(result);
            return true;
        }
    }

    int getIndex(unsigned long time) {
        if (!m_TimeBuffer.empty()) {
            for (int i = 0; i < m_TimeBuffer.size() && i <= time; i++) {
                if (m_TimeBuffer[i] == time)
                    return i;
                else if (m_TimeBuffer[i] > time) {
                    std::cout << "[TRBuffer][Warning] No data was found at time " << time << std::endl;
                    return -1;
                }
            }
        }
    }

    // Here after means strictly greater time.

    int getIndexAfter(unsigned long time) {
        if (!m_TimeBuffer.empty()) {
            for (unsigned int i = 0; i < m_TimeBuffer.size(); i++) {
                if (m_TimeBuffer[i] > time)
                    return i;
            }
            std::cout << "[TRBuffer][Warning] No data were found after time " << time << std::endl;
            return -1;
        } else {
            std::cout << "[TRBuffer][Warning] Looking for index in empty buffer!" << std::endl;
            return -1;
        }
    }

    long getTimeFromIndex(unsigned int index) {
        return m_TimeBuffer[index];
    }

    T getDataFromIndex(unsigned int index) {
        return m_DataBuffer[index];
    }
};

//#include "TRBuffer.hpp"
#endif
