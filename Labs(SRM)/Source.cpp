#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

void print(int n, int m, float** matrix)
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

bool ok(int n, int m, float** matrix)
{
    if (matrix[0][0] > matrix[0][1] + matrix[0][2] + matrix[0][3] + matrix[0][4] &&
        matrix[1][1] > matrix[1][0] + matrix[1][2] + matrix[1][3] + matrix[1][4] &&
        matrix[2][2] > matrix[2][1] + matrix[2][0] + matrix[2][3] + matrix[2][4] &&
        matrix[3][3] > matrix[3][1] + matrix[3][2] + matrix[3][0] + matrix[3][4] &&
        matrix[4][4] > matrix[4][1] + matrix[4][2] + matrix[4][3] + matrix[4][0])
        return 1;
    return 0;
}



//----------------------- main -----------------------------------------
int main()
{
    int i, j, n, m;

    n = 5;
    m = 6;
    float** matrix = new float* [n];
    for (i = 0; i < n; i++)
        matrix[i] = new float[m];

    matrix[0][0] = 5.18 + 0.25;
    matrix[0][1] = 1.12;
    matrix[0][2] = 0.95;
    matrix[0][3] = 1.32;
    matrix[0][4] = 0.83;
    matrix[0][5] = 6.19 + 0.25;

    matrix[1][0] = 1.12;
    matrix[1][1] = 4.28 - 0.25;
    matrix[1][2] = 2.12;
    matrix[1][3] = 0.57;
    matrix[1][4] = 0.91;
    matrix[1][5] = 3.21;


    matrix[2][0] = 0.95;
    matrix[2][1] = 2.12;
    matrix[2][2] = 6.13 + 0.25;
    matrix[2][3] = 1.29;
    matrix[2][4] = 1.57;
    matrix[2][5] = 4.28 - 0.5;

    matrix[3][0] = 1.32;
    matrix[3][1] = 0.57;
    matrix[3][2] = 1.29;
    matrix[3][3] = 4.57 - 0.25;
    matrix[3][4] = 1.25;
    matrix[3][5] = 6.25;

    matrix[4][0] = 0.83;
    matrix[4][1] = 0.91;
    matrix[4][2] = 1.57;
    matrix[4][3] = 1.25;
    matrix[4][4] = 5.21 + 0.25;
    matrix[4][5] = 4.95 + 0.25;

    float** copy = new float* [n];
    for (i = 0; i < n; i++)
        copy[i] = new float[m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            copy[i][j] = matrix[i][j];
        }
    }

    print(n, m, matrix);

    if (!ok(n, m, matrix))
        cout << endl << "ERRRROR" << endl << endl;
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;
    x1 = (matrix[5][0] - matrix[0][1] * x2 - matrix[0][2] * x3 - matrix[0][3] * x4 - matrix[0][4] * x5) / matrix[0][0];


    /* float  tmp;
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

     float* r = new float[n];
     for (i = 0; i < n; i++) {
         r[i] = copy[i][4] - (copy[i][0] * xx[0] + copy[i][1] * xx[1] + copy[i][2] * xx[2] + copy[i][3] * xx[3]);
     }*/

     /* cout << "Error:" << endl;
      for (i = 0; i < n; i++)
          cout << r[i] << " ";
      cout << endl;*/

    delete[] matrix;
    return 0;
}