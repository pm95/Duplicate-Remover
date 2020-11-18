#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class Node
{
public:
    T data;
    Node<T> *next_node;

    Node(T data, Node<T> *next_node = nullptr)
    {
        this->data = data;
        this->next_node = next_node;
    }

    void print()
    {
        std::cout << "Node " << this << ": " << std::endl;
        std::cout << this->data << std::endl;
        std::cout << this->next_node << std::endl;
        std::cout << std::endl;
    }
};

#endif