/*
 * src/today.c
 * Created by jhhan128.
 *
 *
 * THE PROGRAM'S MAIN JOB IS RUNNING IN THIS SOURCE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../lib/function.h"
#include "../lib/data_structures/hash/hash.h"


extern int JOBCOUNT;
extern int *JOBS;
extern int JOBSIDX;


// Compare function for qsort
static int cmp(const void *first, const void *second) {
    int x = *((int *)first), y = *((int *)second);

    if (x > y) return 1;
    else if (x < y) return -1;
    else return 0;
}


// do work!!
void run(void) {
    char str[151];
    outputAll(fopen("lib/output/output1.txt", "r"));

    while (true) {
        printf(">> ");

        fgets(str, sizeof(str), stdin);
        if (strcmp(str, "END\n") == 0) break;

        int value = hash_find(str);

        if (value == -1) {
            outputAll(fopen("lib/output/output2.txt", "r"));
            continue;
        }

        JOBS[JOBSIDX] = value;
        JOBSIDX += 1;
    }

    qsort(JOBS, JOBSIDX, sizeof(int), cmp);
}


// is inside JOBS??
bool isInsideList(int n) {
    for (int i = 0; i < JOBSIDX; i++) {
        if (JOBS[i] == n) return true;
    }

    return false;
}