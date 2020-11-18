// Author: Pietro Malky
// Date: 11/09/2020
// Purpose:
// Algorithm for efficiently finding duplicate data in a collection of collections
// Proposed runtime: O(N) where N is the total number of items present in collection
// Notes:
// regex to find unique values in terminal output: ^(\(\d*\) -->  NULL)

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <unordered_map>

#include "Set.h"

int main(int argc, const char *argv[])
{
    // seed random number generator
    srand(time(NULL));

    // instantiate new Set object
    Set<int> set = Set<int>();

    // add random integers to Set
    for (int i = 0; i < 1000; i++)
        set.add_item(rand() % 1000);

    set.print();

    std::vector<int> vals = set.get_unique_values();

    for (int i : vals)
        std::cout << i << std::endl;

    return 0;
}