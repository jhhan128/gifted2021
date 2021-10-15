/*
 * src/make_data.cpp
 * Created by jhhan128.
 *
 *
 * Read config.txt and make data with it.
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

#include "../lib/data_structures/hash/hash"
#include "../lib/function"


extern std::vector<int> today;

// Generate hash table with config.txt
void generateHash(void) {
    std::ifstream config("config.txt");
    std::string str;
    int counter = 1;

    while (true) {
        std::getline(config, str);
        if (str == "") break;

        hash_add(str, counter++);
    }

    int a, b;

    while (std::getline(config, str)) {
        char *end;
        int a = (int)strtol(str.c_str(), &end, 10);
        int b = (int)strtol(end, &end, 10);

        if (!isInsideList(a) || !isInsideList(b)) continue;

        graph_addEdge(a, b);
    }
}