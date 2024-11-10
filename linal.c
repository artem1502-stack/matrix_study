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

double  **transponent(double **y, int n, int m)
{
	int i, j;

	double **z;

	z = create_mas(m, n);
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			z[j][i] = y[i][j];
	return z;
}

double **minor(double **y, int n, int m, int a, int b)
{
	double **z;
	int i, j;

	z = create_mas(n - 1, m - 1);
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
		{
			if ((i != a) && (j != b))
				z[i - (i > a)][j - (j > b)] = y[i][j];
		}
	return z;
}

double algebra_addition(double **y, int n, int a, int b)
{
	double **z;
	double res;

	z = minor(y, n, n, a, b);
	printf("%d : %d\n", a, b);
	if ((a == 4) && (b == 0))
		print_mas(z, n - 1, n - 1);
	res = det(z, n - 1);
	//debug();
	free_mas(z, n - 1);
	//debug();
	return res * (1 - 2 * ((a + b) % 2));
}

double **inverse_matrix(double **y, int n)
{
	double res;
	double **z, **mas;
	int i, j;


	res = det(y, n);
	if (check_zero(res))
		return NULL;
	z = create_mas(n, n);
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			z[i][j] = algebra_addition(y, n, i, j);

	mas = transponent(z, n, n);
	free_mas(z, n);

	multiply_on_number(mas, n, n, 1/res);
	return mas;
}
