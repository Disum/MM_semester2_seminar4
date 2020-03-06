#include <stdio.h>
#include <math.h>
#include "solve.h"
#include "interp.h"
#include "heapsort.h"
#include "f.h"
int p(double a, double b);
#define MAX_IT 10e6
#define NOT_FOUND (-1)

int p(double a, double b)
{
	if( fabs(a)>fabs(b) )
		return 1;

	if( fabs(a)<fabs(b) )
		return -1;

	return 0;
}

int solve(double (*f)(double), double a, double b, double eps, double *res)
{
	int it, i;
	double x_new, y_new, x[3], y[3], x_tmp[3];

	x[0] = a;
	x[1] = b;
	x[2] = (a + b)/2;
	for( i = 0; i<3; i++ )
		y[i] = f(x[i]);

	for( it = 0; it<MAX_IT; it++ )
	{
		if( fabs(y[0])<eps )
		{
			*res = x[0];
			return it;
		}

		for( i = 0; i<3; i++ )
			x_tmp[i] = x[i];

		x_new = interp(3, 0, y, x_tmp);
		y_new = f(x_new);

		for( i = 0; i<3; i++ )
		{
			if( (y_new<=y[i]) && (y_new>=y[i]) )
				return NOT_FOUND;
		}

		heapsort(x, y, 3, &p);

		x[2] = x_new;
		y[2] = f(x[2]);
	}

	return NOT_FOUND;
}
