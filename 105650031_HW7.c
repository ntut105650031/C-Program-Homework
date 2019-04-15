#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

#define MAX 256

typedef struct NewRecord
{
    char* word;
    int number;
} Record;

void ToLower(char* str);
int GetNumberOfSpace(char* str);
void InitWords(Record* records, const int len);
void SaveWords(Record* records, const char* str);
int GetIndexOfRecords(Record* records, char* word, int len);

int main()
{
    int i;
    char input[MAX];
    // input string
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-1] = '\0';
    ToLower(&input);
    int recordsLen = GetNumberOfSpace(&input) + 1;
    Record words[recordsLen];
    InitWords(&words, recordsLen);
    SaveWords(&words, &input);
    for(i=0; i<recordsLen; i++)
    {
    	if(words[i].number > 0)
        {
            printf("\n%s %d", words[i].word, words[i].number);
            free(words[i].word);
        }
	}
    return 0;
}

void ToLower(char* str)
{
    int i;
    for(i=0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

int GetNumberOfSpace(char* str)
{
    int i, n = 0;
    for(i=0; str[i]; i++)
    {
        if(str[i]==' ') n++;
    }
    return n;
}

void InitWords(Record* records, const int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        records[i].word = NULL;
        records[i].number = 0;
    }
}

void SaveWords(Record* records, const char* str)
{
    int numberOfRecords = 0;
    char* cut = strtok(str, " ");
    while(cut != NULL)
    {
        int index = GetIndexOfRecords(records, cut, numberOfRecords);
        if(index < 0)
        {
            int len = strlen(cut) + 1;
            records[numberOfRecords].word = (char*)malloc(len * sizeof(char));
            memcpy(records[numberOfRecords].word, cut, len);
            records[numberOfRecords].number = 1;
            numberOfRecords++;
        }
        else
        {
            records[index].number++;
        }
        cut = strtok(NULL, " ");
    }
}

int GetIndexOfRecords(Record* records, char* word, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(strcmp(records[i].word, word)==0)
            return i;
    }
    return -1;
}
