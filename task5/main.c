#include <stdio.h>
#include <time.h>
#include "solve.h"
#include "f.h"
#define ERROR_READ (-1)

int main(int argc, char **argv)
{
	double a, b, eps, x;
	int it;
	clock_t time_beg;

	if( argc!=4 )
	{
		fprintf(stderr, "Error! Usage: %s a b eps\n", argv[0]);
		return ERROR_READ;
	}
	if( sscanf(argv[1], "%lf", &a)!=1 || sscanf(argv[2], "%lf", &b)!=1 || sscanf(argv[3], "%lf", &eps)!=1 || eps<=0 || a>b )
	{
		fprintf(stderr, "Error! Can not read a, b, eps: eps>0, a<=b\n");
		return ERROR_READ;
	}

	time_beg = clock();
	it = solve(&f, a, b, eps, &x);
	printf("Time: %.2lf seconds\n", (double)(clock() - time_beg)/CLOCKS_PER_SEC);
	printf("count = %d\n", get_count());
	if( it>=0 ) {
		printf("x = %e\nit = %d\n", x, it);
		printf("f(x) = %e\n", f(x));
	} else
		printf("Can not find root!\n");

	return 0;
}
