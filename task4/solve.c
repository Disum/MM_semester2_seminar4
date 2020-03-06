#include <math.h>
#include "solve.h"
#include "f.h"
#define MAX_IT 1e6
#define NOT_FOUND (-1)

int solve(double (*f)(double), double a, double b, double eps, double *x)
{
	int it;
	double c, val_c, val_a = f(a), val_b = f(b);

	if( fabs(val_a)<eps )
	{
		*x = a;
		return 0;
	}
	if( fabs(val_b)<eps )
	{
		*x = b;
		return 0;
	}

	for( it = 0; it<MAX_IT; it++ )
	{
		c = b - (b - a)*val_b/(val_b - val_a);
		val_c = f(c);

		if( fabs(val_c)<eps )
		{
			*x = c;
			return it;
		}

		a = b;
		val_a = val_b;
		b = c;
		val_b = val_c;
	}

	return NOT_FOUND;
}
