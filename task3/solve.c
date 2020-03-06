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
		if( (b - a)<eps )
		{
			*x = (a + b)/2;
			return it;
		}

		c = a - val_a*(b - a)/(val_b - val_a);

		if( (a<=c && a>=c) || (b<=c && b>=c) )
			break;

		val_c = f(c);

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
