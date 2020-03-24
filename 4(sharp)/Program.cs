using System;

namespace SBM_LAB4
{
    class Program
    {
        static void Main(string[] args)
        {
            double t = 6;
            double a = 0.11 * t;
            double k = -9+2;
            double b = 0.02 * k;
            double g = 0.02 * k;
            double d = 0.015 * t;
            int n = 4;
            double[][] M = E(n);
            double[][] e = E(n);
            double[][] C = new double[n][];
            double[][] Mo = new double[n][];
            double[][] D = new double[n][];
            double[] P = new double[n];
            for (int i = 0; i < n; i++)
            {
                C[i] = new double[n];
                Mo[i] = new double[n];
                D[i] = new double[n];
                C[i] = new double[n];
            }

            double[][] A = new double[][]
            {
                new double[] {6.26 + a, 1.10 - b, 0.97 + g, 1.24 - d},
                new double[] {1.10 - b, 4.16 - a, 1.30, 0.16},
                new double[] {0.97 + g, 1.30, 5.44 + a, 2.10},
                new double[] {1.24 - d, 0.16, 2.10, 6.10 - a},
            };
            Console.Write("Вхiдна матриця\n");
            PrintMatrix(A);
            int iter = 1;
            int l = n - 1;
            int j = n - 2;
            while (l >= 0 && j >= 0)
            {
                Console.Write("----------------------------------------------------------\n");
                Console.WriteLine("IТЕРАЦIЯ " + iter++ + " Ключовий елемент = " + A[l][j] + "\n");
                Deviding(n, l, j, M, A);
                Console.Write("M" + "\n");
                PrintMatrix(M);
                Multiply(n, C, A, M);
                Console.WriteLine();
                Console.Write("C = A * M ");
                Console.WriteLine();
                PrintMatrix(C);
                invM(n, l, Mo, A, e);
                Console.WriteLine();
                Console.Write("M^(-1):");
                Console.WriteLine();
                PrintMatrix(Mo);
                Multiply(n, D, Mo, C);
                Console.WriteLine();
                Console.Write(" D = M^(-1) * A * M:");
                Console.WriteLine();
                PrintMatrix(D);
                if (l != 1)
                    reset(n, A, D, M, e);

                l--; j--;
            }
            Console.WriteLine();
            Console.Write("Polinom: " + "\n");
            PrintPolynom(n, D);

        }

        static void PrintMatrix(double[][] A)
        {
            for (int i = 0; i < A.GetUpperBound(0) + 1; i++)
            {
                for (int j = 0; j < A.GetUpperBound(0) + 1; j++)
                {
                    Console.Write(A[i][j] + "  \t");
                }

                Console.WriteLine();
            }
        }

        static double[][] E(int n)
        {
            double[][] E = new double[n][];
            for (int i = 0; i < n; i++)
                E[i] = new double[n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j) E[i][j] = 1;
                    else E[i][j] = 0;
                }
            }

            return E;
        }

        static void Deviding(int n, int i, int j, double[][] M, double[][] A)
        {
            for (int k = 0; k < n; k++)
            {
                if (A[i][j] != A[i][k])
                    M[i - 1][k] = (-1) * A[i][k] / A[i][j];
                else M[i - 1][k] = 1 / A[i][j];
            }
        }

        static void Multiply(int n, double[][] C, double[][] A, double[][] M)
        {
            for (int k = 0; k < n; k++)
            {
                for (int a = 0; a < n; a++)
                {
                    C[k][a] = 0;
                    for (int b = 0; b < n; b++)
                    {
                        C[k][a] += A[k][b] * M[b][a];
                    }
                }
            }
        }

        static void invM(int n, int i, double[][] Mo, double[][] A, double[][] e)
        {
            for (int a = 0; a < n; a++)
            {
                for (int b = 0; b < n; b++)
                {
                    if (a != i - 1) Mo[a][b] = e[a][b];
                    else Mo[i - 1][b] = A[i][b];
                }
            }
        }

        static void reset(int n, double[][] A, double[][] D, double[][] M, double[][] e)
        {
            for (int a = 0; a < n; a++)
            {
                for (int b = 0; b < n; b++)
                {
                    A[a][b] = D[a][b];
                    M[a][b] = e[a][b];
                }
            }
        }

        static void PrintPolynom(int n, double[][] D)
        {
            int j = -1;
            int i = n;
            while (i >= 0 && j < n)
            {
                if (i == n) Console.Write("x^ " + n);
                else
                {
                    if (D[0][j] < 0)
                    {
                        Console.Write(" - (" + D[0][j] + " * x^" + i + ")");
                    }
                    else
                    {
                        Console.Write(" - " + D[0][j] + " * x^" + i);
                    }

                }

                i--;
                j++;
            }
            Console.Write(" = 0");
            Console.WriteLine();
        }
    }
}