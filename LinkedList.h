#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

template <class T>
class LinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;

    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~LinkedList()
    {
        while (this->head != nullptr)
        {
            Node<T> *temp = this->head;
            this->head = this->head->next_node;
            delete temp;
        }
    }

    void add_node(T data)
    {
        Node<T> *node = new Node<T>(data);
        this->_add_to_end(node);
    }

    void print()
    {
        Node<T> *head = this->head;
        while (head != nullptr)
        {
            std::cout << head->data << " --> ";
            head = head->next_node;
        }
        std::cout << "NULL" << std::endl;
    }

private:
    void _add_to_end(Node<T> *node)
    {
        // if list is empty, add this node as head of the list
        if (this->head == nullptr)
            this->head = node;

        // if list is empty, add this node as tail of the list also
        if (this->tail == nullptr)
            this->tail = node;
        else
        {
            this->tail->next_node = node;
            this->tail = this->tail->next_node;
        }
    }
};

#endif