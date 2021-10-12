/*
 * src/first_exec.c
 * Created by jhhan128.
 *
 *
 * Setup program for first execution.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../lib/header/constants.h"
#include "../lib/header/functions.h"


// Get an read-only file pointer, and put whole file to stdout.
void outputAll(FILE *filePointer) {
    char str[BUFFER_SZ];

    while (fgets(str, sizeof(str), filePointer) != NULL) {
        fputs(str, stdout);
    }

    puts("");
}


// For first execution, run this function to set up.
void firstExec(void) {
    char str[BUFFER_SZ], *end;
    FILE *filePointer = fopen("config.txt", "w");
    int counter = 1, a, b;

    // output firstexec_1 and get input; jobs
    outputAll(fopen("lib/output/firstexec_1.txt", "r"));

    while (true) {
        printf("%d. ", counter++);
        fgets(str, sizeof(str), stdin);

        if (strcmp(str, "END\n") == 0) break; // if str is END, break
        fputs(str, filePointer);
    }

    counter -= 2;
    fputs("\n", filePointer);


    // output firstexec_2 and get input; relationship
    outputAll(fopen("lib/output/firstexec_2.txt", "r"));

    while (true) {
        printf(">> ");

        fgets(str, sizeof(str), stdin);
        if (strcmp(str, "END\n") == 0) break; // if str is END, break

        // parse integer from string
        a = (int)strtol(str, &end, 10);
        b = (int)strtol(end, &end, 10);

        // if a and b is bigger than counter(= not in normal range)
        if (a > counter || b > counter) {
            outputAll(fopen("lib/output/firstexec_3.txt", "r"));
            continue;
        }

        fprintf(filePointer, "%d %d\n", a, b);
    }

    
    outputAll(fopen("lib/output/firstexec_4.txt", "r"));
}
