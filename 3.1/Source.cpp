#include <iostream>
#include <cmath>
#include "norm.h"
#include "iterat.h"
using namespace std;

double** multipleMatrixes(double** A, double* X)
{

    double** res = new double* [5];
    for (int i = 0; i < 5; i++)
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

    }
    //
    //print(5, 6, res);
    return res;
}

    void PrintRVector(double* X, double** A) {
        double** matrix = multipleMatrixes(A, X);
        //
        //print(5, 6, matrix);
        double* r = new double[5];
        for (int i = 0; i < 5; i++) {
            r[i] = matrix[i][5] - matrix[i][0];

        }

        for (int i = 0; i < 5; i++) {
            cout << "r = " << r[i] << endl;
        }
    }

    void print(double A[5][5])
    {
        int N = 5;
        cout << "\nВаша матрица А:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }

int main()
{
    setlocale(LC_ALL, "");
    double eps=pow(10,-6), A[5][5], B[5];
    int N=5;
    int method;
  
    A[0][0] = 5.18 + 0.25;
    A[0][1] = 1.12;
    A[0][2] = 0.95;
    A[0][3] = 1.32;
    A[0][4] = 0.83;

    A[1][0] = 1.12;
    A[1][1] = 4.28 - 0.25;
    A[1][2] = 2.12;
    A[1][3] = 0.57;
    A[1][4] = 0.91;

    A[2][0] = 0.95;
    A[2][1] = 2.12;
    A[2][2] = 6.13 + 0.25;
    A[2][3] = 1.29;
    A[2][4] = 1.57;

    A[3][0] = 1.32;
    A[3][1] = 0.57;
    A[3][2] = 1.29;
    A[3][3] = 4.57 - 0.25;
    A[3][4] = 1.25;

    A[4][0] = 0.83;
    A[4][1] = 0.91;
    A[4][2] = 1.57;
    A[4][3] = 1.25;
    A[4][4] = 5.21 + 0.25;

    B[0] = 6.19 + 0.25;
    B[1] = 3.21;
    B[2] = 4.28 - 0.25;
    B[3] = 6.25;
    B[4] = 4.95 + 0.25;

    print(A);
    ///////////////////////////////////////
    int n = 5;
    double tmp, t;
    for (int i = 0; i < 1; i++)
    {
        tmp = A[i][i];
        for (int j = n - 1; j >= i; j--)
            A[i][j] /= tmp;
        B[i] /= tmp;
        for (int j = i + 1; j < n; j++)
        {
            print(A);
            tmp = A[j][i];
            for (int k = n - 1; k >= i; k--)
                A[j][k] -= tmp * A[i][k];
            B[j] -= tmp * B[i];
        }
        
    }

    //int n = 5;
    //double tmp, t;
    for (int i = 0; i < 1; i++)
    {
        tmp = A[i][i];
        for (int j = n - 1; j >= i; j--)
            A[i][j] /= tmp;
        B[i] /= tmp;
        for (int j = i + 1; j < n; j++)
        {
            print(A);
            tmp = A[j][i];
            for (int k = n - 1; k >= i; k--)
                A[j][k] -= tmp * A[i][k];
            B[j] -= tmp * B[i];
        }

    }

    //int n = 5;
   //double tmp, t;
    for (int i = 0; i < 1; i++)
    {
        tmp = A[i][i];
        for (int j = n - 1; j >= i; j--)
            A[i][j] /= tmp;
        B[i] /= tmp;
        for (int j = i + 1; j < n; j++)
        {
            print(A);
            tmp = A[j][i];
            for (int k = n - 1; k >= i; k--)
                A[j][k] -= tmp * A[i][k];
            B[j] -= tmp * B[i];
        }

    }
    //////////////////////////////////////
    print(A);
   
    /*cout << "\n(1 - Гаусс / 2 - Зейдель): ";
    cin >> method;*/
    cout << endl;
    iterat(A, B, N, eps, 2);
    return 0;
}