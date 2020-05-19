#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double y[500], x[500], h, esp;
double D(double y, double);
void Runge_Kutte(int j);
void Adams();

int main()
{
	cout << "y' = 1 + 11.3 * y * sin(x) - y^2  \n[0, 6] \ny(0) = 0" << endl;
	x[0] = 0;
	y[0] = 0;
	h = 0.1;
	Runge_Kutte(0);
	cout << endl << endl;
	h = 0.1;
	Adams();
}
double D(double x, double y)
{
	double a = 1 + 0.4*26;
	return 1 + a * y * sin(x) - y*y;
}
void Runge_Kutte(int j)
{
	printf("\nRunge_Kutte\n");
	double K1, K2, K3, K4, check;
	int i = 0;
	printf("\n\n X\tY\t\tError\n");
	cout << " " << x[i] << "\t" << y[i] << "\t" << 0 << endl;

	do
	{
		if (j == 1 && i == 3)
		{
			break;
		}
		do
		{
			x[i + 1] = x[i] + h;
			K1 = D(x[i], y[i]);
			K2 = D(x[i] + h / 2, y[i] + h * K1 / 2);
			K3 = D(x[i] + h / 2, y[i] + h * K2 / 2);
			K4 = D(x[i] + h, y[i] + h * K3);
			check = abs((K2 - K3) / (K1 - K2));
			if (check > 0.09) {
				h /= 2;
			}
		} while (check > 0.09);
		y[i + 1] = y[i] + h / 6 * (K1 + 2 * K2 + 2 * K3 + K4);
		esp = abs(y[i + 1] - y[i]) / (pow(2, 4) - 1);
		printf(" %1.2f\t%1.6f\t%1.6f\n", x[i + 1], y[i + 1], esp);
		i++;
	} while (x[i] < 6);
}
void Adams() {
	printf("\nAdams\n");
	int i = 3;
	double check;
	double Y;
	printf("\n\n X\tY\t\tError\n");
	do {
		do
		{
			x[i + 1] = x[i] + h;
			y[i + 1] = y[i] + h / 24 * (55 * D(x[i], y[i]) - 59 * D(x[i - 1], y[i - 1]) + 37 * D(x[i - 2], y[i - 2]) - 9 * D(x[i - 3], y[i - 3]));
			Y = y[i] + h / 24 * (9 * D(x[i + 1], y[i + 1]) + 19 * D(x[i], y[i]) - 5 * D(x[i - 1], y[i - 1]) + D(x[i - 2], y[i - 2]));
			check = abs(Y - y[i + 1]);
			if (check > 0.09)
			{
				h /= 2;
			}
		} while (check > 0.09);
		esp = abs(y[i + 1] - y[i]) / (pow(2, 4) - 1);
		printf(" %1.2f\t%1.6f\t%1.6f\n", x[i + 1], y[i + 1], esp);
		i++;
	} while (x[i] < 6);
}
