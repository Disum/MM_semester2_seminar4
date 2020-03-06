#ifndef STRUCT_POINT
#define STRUCT_POINT

struct point
{
	double x;
	double y;
};

#endif

#ifndef SOLVE_H
#define SOLVE_H

int solve(double (*f)(double), double a, double b, double eps, double *x);

#endif
