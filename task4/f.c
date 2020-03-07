#include <math.h>
#include "f.h"

static int count = 0;

double f(double x)
{
	count++;
	return x*x*x - 2*x*x + x - 2;
}

int get_count(void)
{
	return count;
}
