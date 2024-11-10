#include "h.h"

int sort_lines_det(double **y, int n, int m)
{
	int i, j;
	double *t;
	int sign = 1;

	for (i = 0; i < n; ++i)
		for (j = 0; j < n - 1 - i; ++j)
		{
			if (f_to_sort(y[j], y[j + 1], m))
			{
				t = y[j];
				y[j] = y[j + 1];
				y[j + 1] = t;
				sign *= -1;
			}
		}
	return sign;
}


