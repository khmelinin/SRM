#include "iterat.h"
#include <iostream>
#include <cmath>
#include "norm.h"
#include "okr.h"

using namespace std;

double iterat(double A[5][5], double B[5], int N, double eps, int method=2)
{
    //if (thirdNorm(A, N, N) > 1) {
        int k = 0;
        int i, j;
        double X[5];
        double Y[5];
        double s;
        double g;

        for (i = 0; i < N; i++) {
            X[i] = B[i];
        }
        do {
            s = 0; k++;
            /*if (method != 1 && method != 2) {
                while (method != 1 && method != 2) {
                    cerr << "Неверное значение!" << endl;
                    cout << "\nВыберите метод решения системы (1 - Гаусс / 2 - Зейдель): ";
                    cin >> method;
                    cout << endl;
                }
            }*/
            //if (method == 1) { // Решаем систему методом Гаусса.
            //    for (i = 0; i < N; i++) {
            //        Y[i] = B[i];
            //        for (j = 0; j < N; j++) {
            //            Y[i] = Y[i] + A[i][j] * X[j];
            //        }
            //        s += (X[i] - Y[i]) * (X[i] - Y[i]);
            //    }
            //    for (i = 0; i < N; i++) {
            //        X[i] = Y[i];
            //    }
            //}
            /*else */if (method == 2) { // Решаем систему методом Зейделя.
                for (i = 0; i < N; i++) {
                    g = B[i];
                    for (j = 0; j < N; j++) {
                        g = g + A[i][j] * X[j];
                    }
                    s += (X[i] - g) * (X[i] - g);
                    X[i] = g;
                }
            }
        } while (sqrt(s) >= eps * (1 - thirdNorm(A, N, N)) / thirdNorm(A, N, N));

        if (method == 1 || method == 2) {
            cout << "Решение системы:" << endl;
            for (i = 0; i < N; i++) {
                cout << "X" << i << " = " << okr(X[i], eps) << endl;
            }
            cout << "Число итераций: " << k - 1 << endl;
            cout << "Первая норма матрицы A: " << firstNorm(A, N, N) << endl;
            cout << "Вторая норма матрицы A: " << secondNorm(A, N, N) << endl;
            cout << "Третья норма матрицы A: " << thirdNorm(A, N, N) << endl;
        }

   /* }
    else {
        cerr << "Условие сходимости по евклидовой метрике не выполняется!" << endl;
    }*/

    return 0;
}