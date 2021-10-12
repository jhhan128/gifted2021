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



int main(int argc, char **argv) {

    FILE *config = fopen("config.txt", "r");

    if (config == NULL) {
        firstExec();
        return 0;
    }

    
}