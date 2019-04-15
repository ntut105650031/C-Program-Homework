#include<stdio.h>
#define MAX 10

typedef struct NewMatrix
{
    int row, col;
    int data[MAX][MAX];
} Matrix;

void InputError();
int SetMatrix(Matrix* m);
void AddMatrix(Matrix* m1, Matrix* m2);
void SubMatrix(Matrix* m1, Matrix* m2);
void ProductMatrix(Matrix* m1, Matrix* m2);

int main(void)
{
    int isInputError = 0;
    Matrix m1, m2;
    isInputError += SetMatrix(&m1);
    printf("\n");
    isInputError += SetMatrix(&m2);
    printf("\n");
    if(isInputError)
    {
        InputError();
        return 0;
    }
    AddMatrix(&m1, &m2);
    printf("\n");
    SubMatrix(&m1, &m2);
    printf("\n");
    ProductMatrix(&m1, &m2);
    printf("\n");
    return 0;
}

void InputError()
{
    printf("ERROR\n\nERROR\n\nERROR\n");
}

int SetMatrix(Matrix* m)
{
    scanf("%d %d", &m->row, &m->col);
    if(m->row < 1 || m->col < 1 || m->col>MAX || m->row>MAX) return 1;
    int i, j;
    for(i=0; i< m->row; i++)
        for(j=0; j< m->col; j++)
            scanf("%d",&m->data[i][j]);
    return 0;
}

void AddMatrix(Matrix* m1, Matrix* m2)
{
    if(m1->row != m2->row || m1->col != m2->col)
    {
        printf("ERROR");
        return;
    }

    int i, j;
    for(i=0; i<m1->row; i++)
    {
        for(j=0; j<m1->col; j++)
            printf("%d ", m1->data[i][j]+m2->data[i][j]);
        printf("\n");
    }
}

void SubMatrix(Matrix* m1, Matrix* m2)
{
    if(m1->row != m2->row || m1->col != m2->col)
    {
        printf("ERROR");
        return;
    }
    int i, j;
    for(i=0; i<m1->row; i++)
    {
        for(j=0; j<m1->col; j++)
            printf("%d ", m1->data[i][j]-m2->data[i][j]);
        printf("\n");
    }
}

void ProductMatrix(Matrix* m1, Matrix* m2)
{
    if(m1->col != m2->row)
    {
        printf("ERROR");
        return;
    }
    int i, j, k, prod;
    for(i=0; i<m1->row; i++)
    {
        for(j=0; j<m2->col; j++)
        {
            prod = 0;
            for(k=0; k<m1->col; k++)
            {
                prod += m1->data[i][k] * m2->data[k][j];
                //printf(" %d * %d = %d\n", m1->data[i][k], m2->data[k][j], m1->data[i][k] * m2->data[k][j]);
            }
            printf("%d ", prod);
        }
        printf("\n");
    }
}
