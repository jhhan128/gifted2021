#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../lib/hash.h"


void firstExec(void) {
    FILE *fp = fopen("../config.txt", "w");

    puts("gifted2021에 오신 것을 환영합니다.\n사용을 위해 할 일 목록을 만들어야 합니다.\n");
    puts("이 프로그램에서 사용할 할 일 목록을 입력해 주세요.\n할 일의 이름은 줄바꿈으로 구분하고, 15글자 미만으로 해 주세요.");
    puts("입력이 끝났다면 END를 입력해 주세요.\n");

    int number = 1;

    while (true) {
        printf("%d. ", number++);

        char str[46];
        fgets(str, sizeof(str), stdin);
        str[strlen(str) - 1] = '\0';

        if (strcmp(str, "END") == 0) break;

        fputs(str, fp);
        fputs("\n", fp);
    }

    number--;

    puts("\n이제 입력한 일들의 선후관계를 입력해야 합니다.");
    puts("만약 a번 일을 b번 일보다 먼저 해야 한다면 a b와 같이 입력해 주세요.");
    puts("줄바꿈으로 구분하고, 한 줄에는 수 두 개만 입력해 주세요.");
    puts("입력이 끝났다면 END를 입력해 주세요.\n");

    int a, b;

    while (true) {
        printf(">> ");

        int flag = scanf("%d %d", &a, &b);
        if (flag == EOF) break;

        if (a > number || b > number) {
            puts("번호가 범위에 맞지 않습니다. 다시 입력해 주세요.");
            continue;
        }

        fprintf(fp, "%d %d\n", a, b);
    }

    puts("감사합니다. gifted2021을 사용하기 위한 모든 준비가 끝났습니다.");
    puts("이제부터는 프로그램을 다시 열면 사용하실 수 있습니다.");
}





int main(int argc, char **argv) {
    FILE *fp = fopen("../config.txt", "r");
    
    if (fp == NULL) {
        firstExec();
        return 0;
    }

    
}
