/*
 * src/today.cpp
 * Created by jhhan128.
 *
 *
 * THE PROGRAM'S MAIN JOB IS RUNNING IN THIS SOURCE.
 */

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <utility>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "../lib/function"
#include "../lib/data_structures/hash/hash"
#include "../lib/data_structures/graph/graph"

extern std::vector<int> today;


// do work!!
void run(void) {
    std::string str;

    generateHash();

    outputAll("lib/output/output1.txt");

    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, str);
        if (str == "END") break;

        int value = hash_find(str);

        if (value == -1) {
            outputAll("lib/output/output2.txt");
            continue;
        }

        today.push_back(value);
    }

    std::sort(today.begin(), today.end());

    std::vector<int> topo = graph_topologicalSort();
    std::cout << std::endl;

    for (int i = 0; i < (int)topo.size(); i++) {
        std::cout << inTable[topo[i]] << std::endl;
    }
}


// is inside JOBS??
bool isInsideList(int n) {
    return std::binary_search(today.begin(), today.end(), n);
}