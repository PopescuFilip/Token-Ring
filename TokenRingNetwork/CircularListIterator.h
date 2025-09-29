#pragma once
#include "Node.h"

namespace tokenRingNetwork
{
    template <typename T>
    class CircularListIterator
    {
    public:
        CircularListIterator(std::shared_ptr<Node<T>> start) : m_current{ start } {};

        T& operator*() { return m_current->value; };

        CircularListIterator<T>& operator++();

    private:
        std::shared_ptr<Node<T>> m_current;
    };

    template<typename T>
    inline CircularListIterator<T>& CircularListIterator<T>::operator++()
    {
        if (m_current)
            m_current = m_current->next;
        return *this;
    }
}