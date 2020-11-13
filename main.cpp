// Author: Pietro Malky
// Date: 11/09/2020
// Purpose:
// Algorithm for efficiently finding duplicate data in a collection of collections
// Proposed runtime: O(N) where N is the total number of items present in collection
// Notes:
// regex to find unique values in terminal output: ^(\(\d*\) -->  NULL)

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

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
        cout << "Node " << this << ": " << endl;
        cout << this->data << endl;
        cout << this->next_node << endl;
        cout << endl;
    }
};

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
            cout << head->data << " --> ";
            head = head->next_node;
        }
        cout << "NULL" << endl;
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

template <class T>
class Set
{
public:
    unordered_map<T, LinkedList<T> *> data;

    ~Set()
    {
        for (auto &pair : data)
            delete pair.second;
    }

    void add_item(T item)
    {
        // create new linked list object at selected key if one isn't already present
        if (data.find(item) == data.end())
            data.insert({item, new LinkedList<T>()});

        // pass data to list to create new node
        data.at(item)->add_node(item);
    }

    void print()
    {
        for (auto &pair : data)
            pair.second->print();
    }
};

int main(int argc, const char *argv[])
{
    Set<int> set = Set<int>();

    return 0;
}