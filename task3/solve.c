#include <math.h>
#include "solve.h"
#include "f.h"
#define MAX_IT 1e6
#define NOT_FOUND (-1)

int solve(double (*f)(double), double a, double b, double eps, double *x)
{
	int it;
	double c, val_c, val_a = f(a), val_b = f(b);

	for( it = 1; it<MAX_IT; it++ )
	{
		c = a - val_a*(b - a)/(val_b - val_a);

		val_c = f(c);

		if( fabs(val_c)<eps )
		{
			*x = c;
			return it;
		}

		if( (a<=c && a>=c) || (b<=c && b>=c) )
			break;

		if( val_a*val_c<=0 )
		{
			b = c;
			val_b = val_c;
		}
		else
		{
			a = c;
			val_a = val_c;
		}
	}

	return NOT_FOUND;
}
