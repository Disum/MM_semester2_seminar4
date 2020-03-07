#include <math.h>
#include "solve.h"
#include "f.h"
#define MAX_IT 1e6
#define NOT_FOUND (-1)

int solve(double (*f)(double), double a, double b, double eps, double *x)
{
	int it;
	double gold = (1 + sqrt(5))/2, x1, x2, val1, val2;

	x1 = a + (b - a)/(gold + 1);
	x2 = b - (b - a)/(gold + 1);
	val1 = f(x1);
	val2 = f(x2);
	for( it = 0; it<MAX_IT; it++ )
	{
		if( val1<val2 )
		{
			a = x1;
			x1 = x2;
			val1 = val2;
			x2 = b - (b - a)/(gold + 1);
			val2 = f(x2);
		} else
		{
			b = x2;
			x2 = x1;
			val2 = val1;
			x1 = a + (b - a)/(gold + 1);
			val1 = f(x1);
		}

		if( fabs(b - a)<eps )
		{
			*x = (a + b)/2;
			return it;
		}
	}

	return NOT_FOUND;
}
