#include <math.h>
#include "solve.h"
#include "heapsort.h"
#include "f.h"
double mach_eps(void);
int p(double a, double b);
#define MAX_IT 1e6
#define NOT_FOUND (-1)

int p(double a, double b)
{
	if( a>b )
		return 1;

	if( a<b )
		return -1;

	return 0;
}

double mach_eps(void)
{
	double eps = 1;

	while( (1 + eps/2)>1 )
		eps /= 2;

	return eps;
}

int solve(double (*f)(double), double a, double b, double eps, double *res)
{
	int it, i, j;
	double x[3], y[3], g_x0_x1, g_x1_x2, g_x0_x1_x2, x_new, y_new, m_eps = mach_eps();

	x[0] = a;
	x[1] = (a + b)/2;
	x[2] = b;
	for( i = 0; i<3; i++ )
	{
		y[i] = f(x[i]);
	}
	heapsort(x, y, 3, &p);

	for( it = 0; it<MAX_IT; it++ )
	{
		if( fabs(x[2] - x[1])<eps )
		{
			*res = x[2];
			return it;
		}

		g_x0_x1 = (y[1] - y[0])/(x[1] - x[0]);
		g_x1_x2 = (y[2] - y[1])/(x[2] - x[1]);
		g_x0_x1_x2 = (g_x1_x2 - g_x0_x1)/(x[2] - x[0]);

		if( fabs(g_x0_x1_x2)<m_eps )
		{
			*res = x[2];
			return it;
		}
		x_new = -( g_x0_x1 - (x[0] + x[1])*g_x0_x1_x2 )/( 2*g_x0_x1_x2 );
		for( i = 0; i<3; i++ )
		{
			if( x_new<=x[i] && x_new>=x[i] )
			{
				*res = x[2];
				return it;
			}
		}
		y_new = f(x_new);

		if( y_new<=y[0] )
			break;

		for( i = 1; i<3; i++ )
		{
			if( y_new<=y[i] )
			{
				for( j = 0; j<(i - 1); j++ )
				{
					x[j] = x[j + 1];
					y[j] = y[j + 1];
				}

				x[i - 1] = x_new;
				y[i - 1] = y_new;

				break;
			}
		}
		if( i==3 )
		{
			for( j = 0; j<2; j++ )
			{
				x[j] = x[j + 1];
				y[j] = y[j + 1];
			}

			x[2] = x_new;
			y[2] = y_new;
		}
	}

	return NOT_FOUND;
}
