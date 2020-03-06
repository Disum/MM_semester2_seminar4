#include <math.h>
#include "solve.h"
#include "f.h"
#include "d.h"
#define MAX_IT 10e6
#define EPS_D 10e-8
#define NOT_FOUND (-1)

int solve(double (*f)(double), double (*d)(double), double x0, double eps, double *x)
{
	int it;
	double prev_x = x0, foll_x, val_d;

	for( it = 0; it<MAX_IT; it++ )
	{
		val_d = d(prev_x);
		if( fabs(val_d)<EPS_D )
			break;

		foll_x = prev_x - f(prev_x)/val_d;

		if( fabs(foll_x - prev_x)<eps )
		{
			*x = foll_x;
			return it;
		}

		prev_x = foll_x;
	}

	return NOT_FOUND;
}
