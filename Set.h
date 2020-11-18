#ifndef SET_H
#define SET_H

#include <iostream>
#include <unordered_map>
#include "LinkedList.h"

template <class T>
class Set
{
public:
    std::unordered_map<T, LinkedList<T> *> data;

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

    std::vector<T> get_unique_values()
    {
        std::vector<T> result;
        for (auto &pair : data)
            if (pair.second->head->next_node == nullptr)
                result.push_back(pair.first);
        return result;
    }
};

#endif