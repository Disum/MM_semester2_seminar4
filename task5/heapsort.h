#ifndef STRUCT_POINT
#define STRUCT_POINT

struct point
{
	double x;
	double y;
};

#endif

#ifndef HEAPSORT_H
#define HEAPSORT_H

void heapsort(struct point *a, int n, int (*p)(struct point, struct point));

#endif
