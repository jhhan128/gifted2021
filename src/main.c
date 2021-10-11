#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../lib/hash.h"


void outputAll(const FILE *fp) {
    char str[151];
    
    while (fgets(str, sizeof(str), fp) != NULL) {
        fputs(str, stdout);
    }
}


void firstExec(void) {
    char str[151];
    FILE *fp, *output;
    int counter = 1, a, b;

    fp = fopen("../config.txt", "w");

    outputAll(fopen("../lib/output/firstexec_1.txt", "r"));
    
    while (true) {
        printf("%d. ", counter++);
        fgets(str, sizeof(str), stdin);

        if (strcmp(str, "END\n") == 0) break;
        fputs(str, fp);
    }

    counter -= 2;

    outputAll(fopen("../lib/output/firstexec_2.txt", "r"));

    while (true) {
        printf(">> ");

        int flag = scanf("%d %d", &a, &b);
        if (flag == EOF) break;

        if (a > counter || b > counter) {
            puts("번호가 범위에 맞지 않습니다. 다시 입력해 주세요.");
            continue;
        }

        fprintf(fp, "%d %d\n", a, b);
    }

    outputAll(fopen("../lib/output/firstexec_3.txt", "r"));
}





int main(int argc, char **argv) {
    FILE *fp = fopen("../config.txt", "r");
    
    if (fp == NULL) {
        firstExec();
        return 0;
    }

    
}
