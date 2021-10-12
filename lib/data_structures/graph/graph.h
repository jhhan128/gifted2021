/*
 * lib/data_structures/graph/graph.h
 * Created by jhhan128.
 *
 *
 * A Header for graph implementation.
 */

#ifndef __GRAPH__
#define __GRAPH__


#include <stdbool.h>

#define GRAPH_SIZE (151)

int adj[GRAPH_SIZE][GRAPH_SIZE];
bool visited[GRAPH_SIZE];

int res[GRAPH_SIZE];
int idx = 0;


#endif
