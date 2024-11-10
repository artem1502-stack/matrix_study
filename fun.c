#include "h.h"

void	debug()
{
	static int i = 0;
	printf("HERE: %d\n", i);
	i++;
}

void print_mas(double **x, int n, int m)
{
	int i, j;

	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
		{
			printf("%.1lf\t", x[i][j]);
		}
		printf("\n");
	}
}

int check_zero(double a)
{
	return ABS(a) < EPS;
}

void free_mas(double **x, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		free(x[i]);
	free(x);
}

double **create_mas(int n, int m)
{
	double **x;
	int i;

	if (n * m == 0)
		return NULL;
	x = (double **)malloc(n * sizeof(double *));
	for (i = 0; i < n; ++i)
	{
		x[i] = (double *)malloc(m * sizeof(double));
	}
	return x;
}

void read_error(int error)
{
	if (error == -1)
		printf("File not found\n");
	else if (error == -2)
		printf("Wrong sizes in file\n");
	else if (error == -3)
		printf("Not enough values in file\n");
}

int read_mas(const char *sf, double ***x, int *n, int *m)
{
	FILE *f;
	int i, j;
	double a;

	f = fopen(sf, "r");
	if (!f)
		return -1;

	if (fscanf(f, "%d %d", n, m) != 2)
	{
		return -2;
	}
	*x = create_mas(*n, *m);
	for (i = 0; i < *n; ++i)
		for (j = 0; j < *m; ++j)
		{
			if (fscanf(f, "%lf", &a) != 1)
			{
				free_mas(*x, *n);
				*x = NULL;
				return -3;
			}
			(*x)[i][j] = a;
		}
	return 0;
}

double **copy_matrix(double **x, int n, int m)
{
	double **y;
	int i, j;

	y = create_mas(n, m);
	for(i = 0; i < n; ++i)
		for(j = 0; j < m; ++j)
			y[i][j] = x[i][j];

	return y;
}
