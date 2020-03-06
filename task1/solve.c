#include "solve.h"
#include "f.h"
#define MAX_IT 1e6
#define NOT_FOUND (-1)

int solve(double (*f)(double), double a, double b, double eps, double *x)
{
	int it;
	double c, val_c, val_a = f(a);

	for( it = 0; it<MAX_IT; it++ )
	{
		c = (a + b)/2;

		if( (b - a)<eps )
		{
			*x = c;
			return it;
		}

		if( (a<=c && a>=c) || (b<=c && b>=c) )
			break;

		val_c = f(c);

		if( val_a*val_c<=0 )
		{
			b = c;
		} else
		{
			a = c;
			val_a = val_c;
		}
	}

	return NOT_FOUND;
}
