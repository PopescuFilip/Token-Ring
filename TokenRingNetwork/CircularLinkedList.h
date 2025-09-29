#pragma once

#include <iostream>

#include "CircularListIterator.h"

namespace tokenRingNetwork
{
    template <typename T>
    class CircularLinkedList
    {
    public:
        CircularListIterator<T> begin() const { return CircularListIterator(m_tail->next); }

        void Print() const;

        void AddNode(const T& value);

    private:
        std::shared_ptr<Node<T>> m_tail;
    };

    template<typename T>
    inline void CircularLinkedList<T>::Print() const
    {
        if (!m_tail)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }

        std::shared_ptr<Node<T>> aux{ m_tail->next };
        do
        {
            std::cout << aux->value << '\n';
            aux = aux->next;
        } while (aux != m_tail->next);
        std::cout << std::endl;
    }

    template<typename T>
    inline void CircularLinkedList<T>::AddNode(const T& value)
    {
        std::shared_ptr<Node<T>> newNode{ std::move(new Node(value)) };

        if (!m_tail)
        {
            m_tail = newNode;
            m_tail->next = m_tail;
            return;
        }

        newNode->next = m_tail->next;
        m_tail->next = newNode;
        m_tail = newNode;
    }
}