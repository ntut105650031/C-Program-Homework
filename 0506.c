#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void Problem3();

int main(void) {
    Problem3();
    return 0;
}

void Problem3() {
    char c;
    char srcName[] = "test.txt";
    char destName[] = "copy_test.txt";
    FILE *src, *dest;
    src = fopen(srcName, "r");
    dest = fopen(destName, "w");
    if(src == NULL || dest == NULL) {
        puts("Fail.");
        exit(1);
    }
    while((c = fgetc(src)) != EOF) {
        fputc(toupper(c), dest);
    }
    puts("Success.");
    fclose(src);
    fclose(dest);
}
