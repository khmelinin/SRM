#include <iostream>
#include <iomanip>
using namespace std;

void output(int n, float** A);
float** E(int n);
void deviding(int n, int i, int j, float** M, float** A);
void multiply(int n, float** C, float** A, float** M);
void invM(int n, int i, float** Mo, float** A, float** e);
void reset(int n, float** A, float** D, float** M, float** e);
void printpolynom(int n, float** D);

int main()
{
	double t = 6;
	double a = 0.11 * t;
	double k = -7;
	double b = 0.02 * k;
	double g = 0.02 * k;
	double d = 0.015 * t;

	int n = 4;
	float** M = E(n);
	float** e = E(n);
	float** A = new float* [n];
	float** C = new float* [n];
	float** Mo = new float* [n];
	float** D = new float* [n];
	float* P = new float[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new float[n];
		C[i] = new float[n];
		Mo[i] = new float[n];
		D[i] = new float[n];
	}

	A[0][0] = 6.26 + a;
	A[0][1] = 1.10 - b;
	A[0][2] = 0.97 + g;
	A[0][3] = 1.24 - d;
	A[1][0] = 1.10 - b;
	A[1][1] = 4.16 - a;
	A[1][2] = 1.30;
	A[1][3] = 0.16;
	A[2][0] = 0.97 + g;
	A[2][1] = 1.30;
	A[2][2] = 5.44 + a;
	A[2][3] = 2.10;
	A[3][0] = 1.24 - d;
	A[3][1] = 0.16;
	A[3][2] = 2.10;
	A[3][3] = 6.10 - a;

	cout << "Input matrix = " << endl;
	output(n, A);
	int iter = 1;
	
	int i = n - 1; 
	int j = n - 2;
	while(i>=0 && j>=0){
	
		cout << "--------------------------------------------------------" << endl <<
			"Iteration " << iter++ << " Key element = " << A[i][j] << endl;
		deviding(n, i, j, M, A);
		cout << "M" << endl;
		output(n, M);
		multiply(n, C, A, M);
		cout << "C=A*M  " << endl;
		output(n, C);
		invM(n, i, Mo, A, e);
		cout << "M^(-1):" << endl;
		output(n, Mo);
		multiply(n, D, Mo, C);
		cout << "D = M^(-1) * A * M:" << endl;
		output(n, D);
		if (i != 1)
			reset(n, A, D, M, e);
		
		i--;
		j--;
	}
	cout << endl << "Polinom =  " << endl;
	printpolynom(n, D);
}

void output(int n, float** A)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(13) << A[i][j];
		}cout << endl;
	}cout << endl;
}

float** E(int n)
{
	float** E = new float* [n];
	for (int i = 0; i < n; i++) E[i] = new float[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) E[i][j] = 1;
			else E[i][j] = 0;
		}
	}
	return E;
}

void deviding(int n, int i, int j, float** M, float** A)
{
	for (int k = 0; k < n; k++) {
		if (A[i][j] != A[i][k]) M[i - 1][k] = (-1) * A[i][k] / A[i][j];
		else M[i - 1][k] = 1 / A[i][j];
	}
}

void multiply(int n, float** C, float** A, float** M)
{
	for (int k = 0; k < n; k++) {
		for (int a = 0; a < n; a++) {
			C[k][a] = 0;
			for (int b = 0; b < n; b++) {
				C[k][a] += A[k][b] * M[b][a];
			}
		}
	}
}

void invM(int n, int i, float** Mo, float** A, float** e)
{
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (a != i - 1) Mo[a][b] = e[a][b];
			else Mo[i - 1][b] = A[i][b];
		}
	}
}

void reset(int n, float** A, float** D, float** M, float** e)
{
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			A[a][b] = D[a][b];
			M[a][b] = e[a][b];
		}
	}
}

void printpolynom(int n, float** D)
{
	cout << endl;
	int i = n;
	int j = -1;
	while(i >= 0 || j < n)
	
	{
		if (i == n) {
			cout << "x^" << n;
		}
		else
		{
			if (D[0][j] < 0) {
				cout << " - (" << D[0][j] << " * x^" << i << ")";
			}
			else {
				cout << " - " << D[0][j] << " * x^" << i;
			}
			
		}
		i--;
		j++;
		
	}
	cout << " = 0" << endl;
	
	
}