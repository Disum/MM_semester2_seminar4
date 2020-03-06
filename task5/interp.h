#ifndef STRUCT_POINT
#define STRUCT_POINT

struct point
{
	double x;
	double y;
};

#endif

#ifndef INTERP_H
#define INTERP_H

double interp(int n, double x0, struct point *p);

#endif
