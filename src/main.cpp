/*
 * src/main.cpp
 * Created by jhhan128.
 *
 *
 * Main.cpp
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


int adj[151][151];
bool visited[151];

std::vector<int> today;
std::vector<int> topo_res;
std::unordered_map<std::string, int> table;
std::vector<std::string> inTable = { "DUMMY", };


int main(int argc, char **argv) {
    std::ifstream config("config.txt");

    if (config.fail()) {
        firstExec();
        return 0;
    }
    
    run();
}