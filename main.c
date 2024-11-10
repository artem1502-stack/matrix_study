#include "h.h"

int main()
{
	double **x;
	double t;
	int n, m, error;

	error = read_mas("data", &x, &n, &m);
	if (error)
	{
		read_error(error);
		return 0;
	}

	print_mas(x, n, m);
	printf("\n");
	double **z;

	z = inverse_matrix(x, n);

	print_mas(z, n, n);
	free_mas(x, n);
	free_mas(z, n);

	return 0;
}