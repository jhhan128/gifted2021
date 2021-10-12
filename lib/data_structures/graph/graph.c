/*
 * lib/data_structures/graph/graph.c
 * Created by jhhan128.
 *
 *
 * An implementaion of graph.
 */



#include "graph.h"


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
    res[idx++] = v;

    for (int i = 0; i < GRAPH_SIZE; i++) {
        if (adj[v][i] && !visited[i]) graph_dfs(i);
    }
}


// Topological Sort
int *graph_topologicalSort(int *sz) {
    int ret[GRAPH_SIZE];
    int index = 0;


    for (int i = 0; i < GRAPH_SIZE; i++) {
        if (!isInsideList(i)) graph_dfs(i);
    }

    for (int i = idx - 1; i >= 0; i--) {
        ret[index++] = res[i];
    }

    *sz = index;
    return ret;
}