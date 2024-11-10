#include "h.h"

int f_to_sort(double *x, double *y, int n)
{
	int x_0 = 0, y_0 = 0;

	for (x_0 = 0; (x_0 < n) && (ABS(x[x_0]) < EPS); ++x_0)
		;
	for (y_0 = 0; (y_0 < n) && (ABS(y[y_0]) < EPS); ++y_0)
		;
	return x_0 > y_0;
}

void sort_lines(double **y, int n, int m)
{
	int i, j;
	double *t;

	for (i = 0; i < n; ++i)
		for (j = 0; j < n - 1 - i; ++j)
		{
			if (f_to_sort(y[j], y[j + 1], m))
			{
				t = y[j];
				y[j] = y[j + 1];
				y[j + 1] = t;
			}
		}
}

void delta_lines(double *a, double *b, int n, double c)
{
	int i;

	for (i = 0; i < n; ++i)
	{
		a[i] += b[i] * c;
	}
}

int count_nonzero(double **y, int n, int m)
{
	int i;

	for (i = n - 1; i >= 0; --i)
	{
		if (!check_zero(y[i][m - 1]))
			return i + 1;
	}
	return 0;

}
