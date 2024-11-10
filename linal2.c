#include "h.h"

void multiply_on_number(double **y, int n, int m, double c)
{
	int i, j;

	for(i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			y[i][j] *= c;
}