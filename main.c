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

	t = det(x, n);
	printf("%lf\n", t);

	free_mas(x, n);

	return 0;
}