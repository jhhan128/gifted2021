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


#include "../lib/header/constants.h"
#include "../lib/header/hash.h"
#include "../lib/header/functions.h"


void outputAll(FILE *filePointer) {
    char str[BUFFER_SZ];

    while (fgets(str, sizeof(str), filePointer) != NULL) {
        fputs(str, stdout);
    }

    puts("");
}


int main(int argc, char **argv) {
    firstExec(); // segfault -- why???


}
