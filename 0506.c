#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void Problem3();

int main(void) {
    Problem3();
    return 0;
}

void Problem3() {
    FILE *src, *dest;
    char c, srcName[256], destName[256];
    printf("輸入要讀取的檔案路徑: ");
    gets(srcName);
    src = fopen(srcName, "rb");
    if(src == NULL) {
        puts("檔案讀取失敗");
        exit(1);
    }
    printf("輸入要寫入的檔案路徑: ");
    gets(destName);
    dest = fopen(destName, "wb");
    if(dest == NULL) {
        fclose(src);
        puts("檔案寫入失敗");
        exit(1);
    }
    puts("檔案複製結束");
    while((c = fgetc(src)) != EOF) {
        fputc(toupper(c), dest);
    }
    fclose(src);
    fclose(dest);
}
