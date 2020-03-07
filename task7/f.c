#include <math.h>
#include "f.h"

static int count = 0;

double f(double x)
{
	count++;
	return x*x/10;
}

int get_count(void)
{
	return count;
}
