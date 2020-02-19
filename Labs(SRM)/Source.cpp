#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

void print(int n, int m, float**matrix)
{
    cout << "matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int i, j, n, m;

    n = 4;
    m = 5;
    float** matrix = new float* [n];
    for (i = 0; i < n; i++)
        matrix[i] = new float[m];

    matrix[0][0] = 3.81;
    matrix[0][1] = 0.25;
    matrix[0][2] = 1.28;
    matrix[0][3] = 1.25;
    matrix[0][4] = 4.21;

    matrix[1][0] = 2.25;
    matrix[1][1] = 1.32;
    matrix[1][2] = 5.08;
    matrix[1][3] = 0.49;
    matrix[1][4] = 6.97;

    matrix[2][0] = 5.31;
    matrix[2][1] = 6.78;
    matrix[2][2] = 1.48;
    matrix[2][3] = 1.04;
    matrix[2][4] = 2.38;

    matrix[3][0] = 9.89;
    matrix[3][1] = 2.45;
    matrix[3][2] = 3.35;
    matrix[3][3] = 2.28;
    matrix[3][4] = 10.98;

    /*for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)
        {
            cout << " Element " << "[" << i + 1 << " , " << j + 1 << "]: ";

            cin >> matrix[i][j];
        }*/


    print(n, m, matrix);

   /* cout << "matrix: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;*/

    float  tmp;
    int k;
    float* xx = new float[m];

    for (i = 0; i < n; i++)
    {
        tmp = matrix[i][i];
        for (j = n; j >= i; j--)
            matrix[i][j] /= tmp;
        for (j = i + 1; j < n; j++)
        {
            tmp = matrix[j][i];
            for (k = n; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
        print(n, m, matrix);
    }

    xx[n - 1] = matrix[n - 1][n];
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j];
    }

    for (i = 0; i < n; i++)
        cout << xx[i] << " ";
    cout << endl;

    delete[] matrix;
    system("pause");
    return 0;
}