#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void Problem3();

int main(void) {
    Problem3();
    return 0;
}

void Problem3() {
    FILE *src, *dist;
    char c, srcName[256], distName[256];
    //printf("��J�nŪ�����ɮ׸��|: ");
    printf("Input source file path : ");
    gets(srcName);
    src = fopen(srcName, "r");
    if(src == NULL) {
        //puts("�ɮ�Ū������");
        puts("File read fail.");
        exit(1);
    }
    //printf("��J�n�g�J���ɮ׸��|: ");
    printf("Input source file path : ");
    gets(distName);
    dist = fopen(distName, "w");
    if(dist == NULL) {
        fclose(src);
        puts("�ɮ׼g�J����");
        exit(1);
    }
    while((c = fgetc(src)) != EOF) {
        fputc(toupper(c), dist);
    }
    fclose(src);
    fclose(dist);
}
