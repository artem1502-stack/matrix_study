#ifndef H_H
#define H_H

#define N 5

#define ABS(x) (x * (x >= 0) - x * (x < 0))

#define EPS 1.e-15

#include <stdio.h>
#include <stdlib.h>

//		fun.c
void	debug();
int		read_mas(const char *sf, double ***x, int *n, int *m);
void	read_error(int error);
void	print_mas(double **x, int n, int m);
void	free_mas(double **x, int n);
double	**create_mas(int n, int m);
double	**copy_matrix(double **x, int n, int m);
int		check_zero(double a);


//		gauss.c
int		f_to_sort(double *x, double *y, int n);
void	sort_lines(double **y, int n, int m);
void	delta_lines(double *a, double *b, int n, double c);
int		count_nonzero(double **y, int n, int m);


//		det.c
int		sort_lines_det(double **y, int n, int m);


//		linal.c
int		find_rank(double **x, int n, int m);
void	diag(double **y, int n, int m);
double	det(double **x, int n);
double  **transponent(double **y, int n, int m);
double	**minor(double **y, int n, int m, int a, int b);
double	algebra_addition(double **y, int n, int a, int b);
double	**inverse_matrix(double **y, int n);


//		linal2.c
void multiply_on_number(double **y, int n, int m, double c);

#endif
