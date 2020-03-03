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
        {
            if(j==4)
            cout << matrix[i][j] << "  | ";
            else
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool converge(double* xk, double* xkp)
{
    double norm = 0;
    for (int i = 0; i < 5; i++)
        norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);
    return (sqrt(norm) < pow(10,-6));
}
//
//bool ok(int n, int m, float** matrix)
//{
//    if (matrix[0][0] > matrix[0][1] + matrix[0][2] + matrix[0][3] + matrix[0][4] &&
//        matrix[1][1] > matrix[1][0] + matrix[1][2] + matrix[1][3] + matrix[1][4] &&
//        matrix[2][2] > matrix[2][1] + matrix[2][0] + matrix[2][3] + matrix[2][4] &&
//        matrix[3][3] > matrix[3][1] + matrix[3][2] + matrix[3][0] + matrix[3][4] &&
//        matrix[4][4] > matrix[4][1] + matrix[4][2] + matrix[4][3] + matrix[4][0])
//        return 1;
//    return 0;
//
//}



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

    print(n, m, matrix);

    double x[5], p[5];
    for (int i = 0; i < 5; i++)
    {
        x[i] = 0;
        p[i] = 0;
    }

    do
    {
        for (int i = 0; i < n; i++)
            p[i] = x[i];
        for (int i = 0; i < n; i++)
        {
            double var = 0;
            for (int j = 0; j < i; j++)
                var += (matrix[i][j] * x[j]);
            for (int j = i + 1; j < n; j++)
                var += (matrix[i][j] * p[j]);
            x[i] = (matrix[i][5] - var) / matrix[i][i];
        }
    } while (!converge(x, p));


    cout << "result: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << x[i] << endl;
    }


    delete[] matrix;
    return 0;
}