#include "loShuMagicSquare.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateSquare(int matrix[3][3]) 
{
    int values[9] = {0};
    for (int i = 0; i < 9; i++) 
    {
        int value;
        do 
        {
            value = rand() % 9 + 1;
        } while (values[value - 1]);
        values[value - 1] = 1;
        matrix[i / 3][i % 3] = value;
    }
}

int checkSquare(int matrix[3][3]) 
{
    int sum = matrix[0][0] + matrix[0][1] + matrix[0][2];

    for (int i = 0; i < 3; i++) 
    {
        int rowSum = 0;
        int colSum = 0;
        for (int j = 0; j < 3; j++) 
        {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != sum || colSum != sum) 
        {
            return 0;
        }
    }

    int diagonalSum1 = matrix[0][0] + matrix[1][1] + matrix[2][2];
    int diagonalSum2 = matrix[0][2] + matrix[1][1] + matrix[2][0];

    return (diagonalSum1 == sum && diagonalSum2 == sum);
}

void printSquare(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) 
    {
        printf("[");
        for (int j = 0; j < 3; j++) 
        {
            //printf("%d ", matrix[i][j]);
            printf("%d", matrix[i][j]);
            if(j != 2)
                printf(" ");
            else
                printf("]");
        }
        printf("\n");
    }
}

int main() 
{
    srand(time(0));
    int square[3][3];
    int count = 0;

    while (1) {
        generateSquare(square);
        if (checkSquare(square)) {
            break;
        }

        count++;
    }

    printf("Total number of squares generated and tested before success: %d\n", count);
    printf("Lo Shu Magic Square:\n");
    printSquare(square);

    return 0;
}