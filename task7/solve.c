#include <math.h>
#include "solve.h"
#include "f.h"
#define MAX_IT 1e6
#define NOT_FOUND (-1)

int solve(double (*f)(double), double x0, double eps, double *x)
{
	int it;
	double x_new;

	for( it = 0; it<MAX_IT; it++ )
	{
		x_new = f(x0);

		if( fabs(x_new - x0)<eps )
		{
			*x = x0;
			return it;
		}

		x0 = x_new;
	}

	return NOT_FOUND;
}
