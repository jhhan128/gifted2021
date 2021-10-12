/*
 * src/main.c
 * Created by jhhan128.
 *
 *
 * Main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../lib/data_structures/hash/hash.h"
#include "../lib/function.h"

// Counts of important elements.
int JOBS[151];      // Array of Jobs
int JOBSIDX = 0;    // Index of JOBS


int main(int argc, char **argv) {
    FILE *config = fopen("config.txt", "r");

    if (config == NULL) {
        firstExec();
        return 0;
    }

    
    run();
    
}