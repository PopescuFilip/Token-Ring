#pragma once

#include <memory>

namespace tokenRingNetwork
{
    template <typename T>
    struct Node
    {
        Node() : next{ nullptr } {};
        Node(const T& value) : next{ nullptr }, value{ value } {};

        T value;
        std::shared_ptr<Node<T>> next;
    };
}