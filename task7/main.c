#include <stdio.h>
#include <time.h>
#include "solve.h"
#include "f.h"
#define ERROR_READ (-1)

int main(int argc, char **argv)
{
	double x0, eps, x;
	int it;
	clock_t time_beg;

	if( argc!=3 )
	{
		fprintf(stderr, "Error! Usage: %s x0 eps\n", argv[0]);
		return ERROR_READ;
	}
	if( sscanf(argv[1], "%lf", &x0)!=1 || sscanf(argv[2], "%lf", &eps)!=1 || eps<=0 )
	{
		fprintf(stderr, "Error! Can not read x0, eps: eps>0\n");
		return ERROR_READ;
	}

	time_beg = clock();
	it = solve(&f, x0, eps, &x);
	printf("Time: %.2lf seconds\n", (double)(clock() - time_beg)/CLOCKS_PER_SEC);
	if( it>=0 )
		printf("x = %lf\nit = %d\n", x, it);
	else
		printf("Can not find root!\n");

	return 0;
}
