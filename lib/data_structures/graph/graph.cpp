/*
 * lib/data_structures/graph/graph.cpp
 * Created by jhhan128.
 *
 *
 * An implementaion of graph.
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

#include "graph"

extern std::vector<int> today;
bool isInsideList(int);

// initialize visited
void __init_visited(void) {
    for (int i = 0; i < GRAPH_SIZE; i++) {
        visited[i] = 0;
    }
}


// Make and initialize graph
void graph_makeGraph(void) {
    for (int i = 0; i < GRAPH_SIZE; i++) {
        for (int j = 0; j < GRAPH_SIZE; j++) {
            adj[i][j] = 0;
        }
    }
}


// Add edge to graph
void graph_addEdge(int u, int v) {
    if (u >= GRAPH_SIZE || v >= GRAPH_SIZE) return;
    adj[u][v] = 1;
}


// Depth-Fisrt Search
void graph_dfs(int v) {
    visited[v] = 1;
    topo_res.push_back(v);

    for (int i = 0; i < GRAPH_SIZE; i++) {
        if (adj[v][i] && !visited[i] && isInsideList(i)) graph_dfs(i);
    }
}


// Topological Sort
std::vector<int> graph_topologicalSort(void) {
    for (int i = 0; i < GRAPH_SIZE; i++) {
        if (isInsideList(i)) graph_dfs(i);
    }

    return topo_res;
}