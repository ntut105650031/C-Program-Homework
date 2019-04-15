#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum ConstantValue
{
    MAX_WORD = 46,
    MAX_STRING = 256,
    LEN_STRINGS = 30
};

void InputString(char* strings[], int* numberOfStrings, const char* word);
void PrintStrings(char* strings[], int len);
void CutWord(char* str, const char* word);
void SortDictionary(char* strings[], int len);
void ReleaseMemory(char* strings[], int len);

int main()
{
    char word[MAX_WORD] = {0};
    char* strings[LEN_STRINGS] = {0};
    int numberOfStrings = 0;
    // input word
    scanf("%s", word);

    InputString(strings, &numberOfStrings, word);
    SortDictionary(strings, numberOfStrings);
    PrintStrings(strings, numberOfStrings);
    ReleaseMemory(strings, numberOfStrings);
    return 0;
}

void ReleaseMemory(char* strings[], int len)
{
    int i;
    for(i=0; i<len; i++)
        free(strings[i]);
}

void CutWord(char* str, const char* word)
{
    char* substr = strstr(str, word);
    // nothing
    if(substr==NULL) return;
    // if str = word, then str = empty string
    if(strcmp(str, word)==0)
    {
        memset(str,'\0',sizeof(str)*strlen(str));
        return;
    }
    int lenStr, lenWord, lenTemp, index;
    lenStr = strlen(str), lenWord = strlen(word);
    index = lenStr - strlen(substr);
    // temp: string after word
    lenTemp = lenStr-lenWord-index+1;
    // initialize temp
    char temp[lenTemp];
    // set temp
    memcpy(temp, str+index+lenWord, lenTemp);
    // replace to temp
    memcpy(str+index, temp, lenWord+lenTemp);
}

void InputString(char* strings[], int* numberOfStrings, const char* word)
{
    while(1)
    {
        char input[MAX_STRING] = {0};
        scanf("%s", input);
        if(strlen(input)==2 && input[0]=='-'&&input[1]=='1'&&input[2]=='\0') return;
        CutWord(input, word);
        strings[*numberOfStrings] = (char*)calloc(strlen(input)+1, sizeof(char));
        memcpy(strings[*numberOfStrings], input, strlen(input)+1);
        ++*numberOfStrings;
        if(*numberOfStrings>=LEN_STRINGS) return;
    }
}

void PrintStrings(char* strings[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        puts(strings[i]);
    }
}

void SortDictionary(char* strings[], int len)
{
    if(len==0) return;
    int i;
    for(i=0; i<len-1; i++)
        if(strcmp(strings[i], strings[i+1]) > 0)
        {
            char* temp = strings[i];
            strings[i] = strings[i+1];
            strings[i+1] = temp;
        }
    SortDictionary(strings, len-1);
}
