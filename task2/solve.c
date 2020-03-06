#include <math.h>
#include "solve.h"
#include "f.h"
#include "d.h"
#define MAX_IT 1e6
#define EPS_D 1e-8
#define NOT_FOUND (-1)

int solve(double (*f)(double), double (*d)(double), double x0, double eps, double *x)
{
	int it;
	double prev_x = x0, foll_x, val_d, val_prev = f(x0), val_foll;

	for( it = 0; it<MAX_IT; it++ )
	{
		val_d = d(prev_x);
		if( fabs(val_d)<EPS_D )
			break;

		foll_x = prev_x - val_prev/val_d;

		val_foll = f(foll_x);
		if( fabs(val_foll)<eps )
		{
			*x = foll_x;
			return it;
		}

		prev_x = foll_x;
		val_prev = val_foll;
	}

	return NOT_FOUND;
}
