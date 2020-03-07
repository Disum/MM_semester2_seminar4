#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "solve.h"
#include "f.h"
#define ERROR_READ (-1)
#define ERROR_ALLOCATE (-2)

int main(int argc, char **argv)
{
	double a, b, eps, x, *d;
	int it, m;
	clock_t time_beg;

	if( argc!=5 )
	{
		fprintf(stderr, "Error! Usage: %s m a b eps\n", argv[0]);
		return ERROR_READ;
	}
	if( sscanf(argv[1], "%d", &m)!=1 || sscanf(argv[2], "%lf", &a)!=1 || sscanf(argv[3], "%lf", &b)!=1 || sscanf(argv[4], "%lf", &eps)!=1 || m<1 || eps<=0 || a>b )
	{
		fprintf(stderr, "Error! Can not read m, a, b, eps: m>0, eps>0, a<=b\n");
		return ERROR_READ;
	}
	if( !(d = (double *)malloc(3*(m + 1)*sizeof(double)) ))
	{
		fprintf(stderr, "Error! Can not allocate memory!\n");
		return ERROR_ALLOCATE;
	}

	time_beg = clock();
	it = solve(&f, m, d, a, b, eps, &x);
	printf("Time: %.2lf seconds\n", (double)(clock() - time_beg)/CLOCKS_PER_SEC);
	if( it>=0 )
		printf("x = %e\nit = %d\n", x, it);
	else
		printf("Can not find root!\n");

	free(d);
	return 0;
}
