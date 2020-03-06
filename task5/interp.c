#include "interp.h"

double interp(int n, double x0, struct point *p)
{
	int i, j;
	double res = p[0].x;

	for( i = 0; i<(n - 1); i++ )
	{
		for( j = 0; j<(n - i - 1); j++ )
			p[j].x = ( p[j + 1].x - p[j].x )/( p[j + i + 1].y - p[j].y );

		res += (x0 - p[i].y)*p[0].x;
	}

	return res;
}
