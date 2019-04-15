#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void FindLongSubString(char* str1, char* str2, char* found);

int main()
{
    char a[MAX], b[MAX], c[MAX];
    scanf("%s", a);
    scanf("%s", b);
    FindLongSubString(&a, &b, &c);
    printf("%s", c);
    return 0;
}

void FindLongSubString(char* str1, char* str2, char* found)
{
    int i, j, len;
    char* shortStr, *longStr;
    // Find short and long string
    if(strlen(str1) < strlen(str2))
    {
        shortStr = str1;
        longStr = str2;
    }
    else
    {
        shortStr = str2;
        longStr = str1;
    }

    len = strlen(shortStr);
    // length of short string
    for(i=len; i>0; i--)
    {
        // index of start of short string
        for(j=0; j+i <= len; j++)
        {
            // chars + '\0'
            char match[i+1];
            memcpy(match, shortStr+j, i+1);
            if(strstr(longStr, match))
            {
                memcpy(found, match, i+1);
                return;
            }
        }
    }
}
