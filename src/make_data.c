/*
 * src/make_data.c
 * Created by jhhan128.
 *
 *
 * Read config.txt and make data with it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../lib/data_structures/hash/hash.h"
#include "../lib/function.h"


extern int JOBCOUNT;
extern int JOBS;
extern int JOBSIDX;


// Generate hash table with config.txt
void generateHash(void) {
    FILE *config = fopen("config.txt", "r");
    char str[151];
    int counter = 1;

    while (true) {
        fgets(str, sizeof(str), config);
        if (strcmp(str, "\n") == 0) break;

        hash_add(str, counter);
        counter += 1;
        JOBCOUNT += 1;
    }
}


// Generate Edges
void generateEdge(void) {
    FILE *config = fopen("config.txt", "r");
    char str[151], *end;
    int a, b;

    while (true) {
        char *flag = fgets(str, sizeof(str), config);
        if (flag == NULL) break;

        a = (int)strtol(str, &end, 10);
        b = (int)strtol(end, &end, 10);

        if (!isInsideList(a) || !isInsideList(b)) continue;

        graph_addEdge(a, b);
    }
}