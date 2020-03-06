#include <math.h>
#include "solve.h"
#include "interp.h"
#include "heapsort.h"
#include "f.h"
int point_cmp(struct point a, struct point b);
#define MAX_IT 10e6
#define NOT_FOUND (-1)

int point_cmp(struct point a, struct point b)
{
	if( fabs(a.y)>fabs(b.y) )
		return 1;
	if( fabs(a.y)<fabs(b.y) )
		return -1;
	return 0;
}

int solve(double (*f)(double), double a, double b, double eps, double *x)
{
	int it, i;
	double x_new;
	struct point p[3];

	p[0].x = a;
	p[1].x = b;
	p[2].x = (a + b)/2;
	for( i = 0; i<3; i++ )
		p[i].y = f(p[i].x);

	for( it = 0; it<MAX_IT; it++ )
	{
		if( fabs(p[0].x - p[1].x)<eps )
		{
			*x = p[0].x;
			return it;
		}

		x_new = interp(3, 0, p);

		heapsort(p, 3, &point_cmp);

		if( (x_new<=p[2].x) && (x_new>=p[2].x) )
			break;

		p[2].x = x_new;
		p[2].y = f(p[2].x);
	}

	return NOT_FOUND;
}
