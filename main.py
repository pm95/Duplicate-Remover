# Author: Pietro Malky
# Date: 11/09/2020
# Purpose:
# Algorithm for efficiently finding duplicate data in a collection of collections
# Proposed runtime: O(N) where N is the total number of items present in collection
# Notes:
# regex to find unique values in terminal output: ^(\(\d*\) -->  NULL)

from typing import Dict
from random import randint


class Node:
    '''
    Node class to act as LinkedList node
    Current implementation: unidirectional
    '''

    def __init__(self, data: object = None, next_node: "Node" = None):
        self.data: object = data
        self.next_node: Node = next_node


class LinkedList:
    '''
    LinkedList class
    HEAD pointer allows for ease of printing and iterating from start of list
    TAIL pointer allows for constant-time appending to end of list
    '''

    def __init__(self):
        self.head: Node = None
        self.tail: Node = None

    def _add_to_end(self, node: Node):
        # if list is empty, add this node as head of the list
        if self.head == None:
            self.head = node

        # if list is empty, add this node as the tail of the list
        if self.tail == None:
            self.tail = node
        else:
            self.tail.next_node = node
            self.tail = self.tail.next_node

    def add_to_end(self, data: object):
        self._add_to_end(Node(data))

    def print(self):
        head: Node = self.head
        result = ""
        while head != None:
            result += f"({str(head.data)}) --> "
            head = head.next_node
        print(result + " NULL")


class Set:
    ''' 
    Set class  to extract unique values from a collection of objects
    call get_unique_values() to get list of unique values in Set
    '''

    def __init__(self) -> None:
        self.data: Dict[object, LinkedList] = {}

    def add_data(self, item: object) -> None:
        if item not in self.data:
            self.data[item] = LinkedList()
        self.data[item].add_to_end(item)

    def print(self):
        for key in self.data:
            self.data[key].print()

    def get_unique_values(self) -> list:
        result = []
        for key in self.data:
            if self.data[key].head.next_node is None:
                result.append(key)
        return result


s = Set()
for _ in range(10000):
    s.add_data(randint(0, 1000000))
s.print()
unique_values = s.get_unique_values()
print(unique_values)
