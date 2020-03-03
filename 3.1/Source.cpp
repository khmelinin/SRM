#include <iostream>
#include <cmath>
#include "norm.h"
#include "iterat.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    double eps=pow(10,-6), A[10][10], B[10];
    int N=5, i, j;
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
            tmp = A[j][i];
            for (int k = n - 1; k >= i; k--)
                A[j][k] -= tmp * A[i][k];
            B[j] -= tmp * B[i];
        }
    }

    cout << "\nВаша матрица А:" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
   
    cout << "\nВыберите метод решения системы (1 - Гаусс / 2 - Зейдель): ";
    cin >> method;
    cout << endl;
    iterat(A, B, N, eps, method);
    return 0;
}