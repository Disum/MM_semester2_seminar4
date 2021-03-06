#include <math.h>
#include "solve.h"
#include "interp.h"
#include "heapsort.h"
#include "f.h"
int p(double a, double b);
#define MAX_IT 1e16
#define NOT_FOUND (-1)

int p(double a, double b)
{
	if( fabs(a)>fabs(b) )
		return 1;

	if( fabs(a)<fabs(b) )
		return -1;

	return 0;
}

int solve(double (*f)(double), int m, double *d, double a, double b, double eps, double *res)
{
	int it, i, j;
	double *x = d, *y = d + m + 1, *x_tmp = d + 2*(m + 1), dist, x_new, y_new;

	dist = (b - a)/m;
	for( i = 0; i<(m + 1); i++ )
	{
		x[i] = a + i*dist;
		y[i] = f(x[i]);
	}

	for( i = 0; i<(m + 1); i++ )
	{
		if( fabs(y[i])<eps )
		{
			*res = x[i];
			return 0;
		}
	}

	for( i = 0; i<(m + 1); i++ )
		for( j = i + 1; j<(m + 1); j++ )
			if( y[i]<=y[j] && y[i]>=y[j] )
				return NOT_FOUND;

	heapsort(x, y, (m + 1), &p);

	for( it = 1; it<MAX_IT; it++ )
	{
		for( i = 0; i<(m + 1); i++ )
			x_tmp[i] = x[i];

		x_new = interp(m + 1, 0, y, x_tmp);
		y_new = f(x_new);

		if( fabs(y_new)<eps )
		{
			*res = x_new;
			return it;
		}

		for( i = 0; i<(m + 1); i++ )
		{
			if( (y_new<=y[i]) && (y_new>=y[i]) )
				return NOT_FOUND;
		}

		for( i = m; i>=0; i-- )
		{
			if( fabs(y_new)>=fabs(y[i]) )
			{
				for( j = m; j>(i + 1); j-- )
				{
					x[j] = x[j - 1];
					y[j] = y[j - 1];
				}

				x[i + 1] = x_new;
				y[i + 1] = y_new;

				break;
			}
		}
		if( i==-1 )
		{
			for( j = m; j>0; j-- )
			{
				x[j] = x[j - 1];
				y[j] = y[j - 1];
			}

			x[0] = x_new;
			y[0] = y_new;
		}
	}

	return NOT_FOUND;
}
