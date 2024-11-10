#include "h.h"

double det(double **x, int n)
{
	double **y;
	double res;
	int i, sign;

	y = copy_matrix(x, n, n);
	sign = sort_lines_det(y, n, n);
	diag(y, n, n);
	res = y[0][0];
	for (i = 1; i < n; ++i)
		res *= y[i][i];
	free_mas(y, n);
	return sign * res;
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


