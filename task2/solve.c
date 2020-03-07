#include <math.h>
#include "solve.h"
#include "f.h"
#include "d.h"
double mach_eps(void);
#define MAX_IT 1e6
#define NOT_FOUND (-1)

double mach_eps(void)
{
	double eps = 1;

	while( (1 + eps/2)>1 )
		eps /= 2;

	return eps;
}

int solve(double (*f)(double), double (*d)(double), double x0, double eps, double *x)
{
	int it;
	double prev_x = x0, foll_x, val_d, val_prev = f(x0), val_foll, m_eps = mach_eps();

	for( it = 0; it<MAX_IT; it++ )
	{
		val_d = d(prev_x);
		if( fabs(val_d)<m_eps )
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
