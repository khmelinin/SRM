#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

void print(int n, int m, double** matrix)
{
    cout << "matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 4)
                cout << matrix[i][j] << "  | ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_res(double *x)
{
    cout << "result: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << x[i] << endl;
    }
}

double** multipleMatrixes(double** A, double* X)
{

    double** res = new double*[5];
    for(int i = 0; i < 5;i++)
    {
        res[i] = new double[1];
    }
    int n = 4;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                res[i][j] += A[i][k] * X[k];
            }
        }
        
    }print(5, 6, res);

    return res;
}

int iterations = 0;

void PrintRVector(double* X, double**A) {
    double**matrix = multipleMatrixes(A, X);
    double* r = new double[5];
    for (int i = 0; i < 5; i++) {
        r[i] = matrix[i][5] - matrix[i][0];
        
    }
   
    for (int i = 0; i < 5;i++) {
        cout << "r = " << r[i] << endl;
    }
}

bool converge(double* xk, double* xkp)
{
    double norm = 0;
    for (int i = 0; i < 5; i++)
        norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);
    return (sqrt(norm) < pow(10,-6));
}

//----------------------- main -----------------------------------------
int main()
{
    int i, j, n, m;

    n = 5;
    m = 6;
    double** matrix = new double* [n];
    for (i = 0; i < n; i++)
        matrix[i] = new double[m];

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
        iterations++;
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
        PrintRVector(x, matrix);
        cout << endl;
    } while (!converge(x, p));

    print_res(x);


    cout << endl << "iterations = " << iterations << endl;

    cout << endl << "";
    delete[] matrix;
    return 0;
}