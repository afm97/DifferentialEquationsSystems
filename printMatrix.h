#include <stdio.h>

void printMatrix(int rows, double matrix[rows][3])
{
    for (int i = 0; i < rows; i++)
    {
        printf("%f, %f, %f \n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}