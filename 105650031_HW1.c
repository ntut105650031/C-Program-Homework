#include<stdio.h>
#include<stdlib.h>

#define N 10

int IsLine(int board[N][N], int row, int col);

int main()
{
    int i, j;
    int board[N][N] = {0};
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            scanf("%d", &board[i][j]);
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            if(IsLine(board, i, j))
                printf("%d %d\n", i, j);
    return 0;
}

int IsLine(int board[N][N], int row, int col)
{
    if(board[row][col] != 0) return 0;
    int i, j;
    int h, v, r, l;
    for(i=0; i<5; i++)
    {
        h = v = r = l = 1;

        for(j=0; j<5; j++)
        {
            if(i != j)
            {
                if(col+j-i<0 || col+j-i>=N) h = 0;
                else h *= board[row][col+j-i];

                if(row+j-i<0 || row+j-i>=N) v = 0;
                else v *= board[row+j-i][col];

                if(col+j-i<0 || col+j-i>=N || row-j+i<0 || row-j+i>=N) r = 0;
                else r*= board[row-j+i][col+j-i];

                if(col+j-i<0 || col+j-i>=N || row+j-i<0 || row+j-i>=N) l = 0;
                l*= board[row+j-i][col+j-i];
            }
        }
        if(h || v || r || l) return 1;
    }
    return 0;
}
