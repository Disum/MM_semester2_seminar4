#include <math.h>
#include "solve.h"
#include "f.h"
#define MAX_IT 10e6
#define NOT_FOUND (-1)

int solve(double (*f)(double), double a, double b, double eps, double *x)
{
	int it;
	double c, val_c, val_a = f(a), val_b = f(b);

	for( it = 0; it<MAX_IT; it++ )
	{
		c = b - (b - a)*val_b/(val_b - val_a);

		if( (a<=c && a>=c) || (b<=c && b>=c) )
		{
			*x = c;
			return it;
		}

		if( fabs(b - a)<eps )
		{
			*x = c;
			return it;
		}

		val_c = f(c);

		a = b;
		val_a = val_b;
		b = c;
		val_b = val_c;
	}

	return NOT_FOUND;
}
