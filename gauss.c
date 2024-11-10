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

void diag(double **y, int n, int m)
{
	int i, j, k;

	for (i = 0; i < n - 1; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			if (!check_zero(y[i][j]))
			{
				for (k = i + 1; k < n; ++k)
				{
					if (!check_zero(y[k][j]))
						delta_lines(y[k], y[i], m, -y[k][j] / y[i][j]);
				}
				break;
			}
		}
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

int find_rank(double **x, int n, int m)
{
	double **y;
	int res;

	y = copy_matrix(x, n, m);
	sort_lines(y, n, m);
	diag(y, n, m);
	res = count_nonzero(y, n, m);
	free_mas(y, n);
	return res;
}
