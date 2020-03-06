prog: main.o solve.o f.o d.o
	gcc -Wall main.o solve.o f.o d.o -o prog
main.o: main.c solve.h f.h
	gcc -Wall -c main.c -o main.o
solve.o: solve.c solve.h f.h
	gcc -Wall -c solve.c -o solve.o
f.o: f.c f.h
	gcc -Wall -c f.c -o f.o
d.o: d.c d.h
	gcc -Wall -c d.c -o d.o

prog_optimize: main_optimize.o solve_optimize.o f_optimize.o d_optimize.o
	gcc -Wall -O3 main_optimize.o solve_optimize.o f_optimize.o  d_optimize.o -o prog_optimize
main_optimize.o: main.c solve.h f.h
	gcc -Wall -O3 -c main.c -o main_optimize.o
solve_optimize.o: solve.c solve.h f.h
	gcc -Wall -O3 -c solve.c -o solve_optimize.o
f_optimize.o: f.c f.h
	gcc -Wall -O3 -c f.c -o f_optimize.o
d_optimize.o: d.c d.h
	gcc -Wall -O3 -c d.c -o d_optimize.o

prog_debug: main_debug.o solve_debug.o f_debug.o d_debug.o
	gcc -Wall -g main_debug.o solve_debug.o f_debug.o d_debug.o -o prog_debug
main_debug.o: main.c solve.h f.h
	gcc -Wall -g -c main.c -o main_debug.o
solve_debug.o: solve.c solve.h f.h
	gcc -Wall -g -c solve.c -o solve_debug.o
f_debug.o: f.c f.h
	gcc -Wall -g -c f.c -o f_debug.o
d_debug.o: d.c d.h
	gcc -Wall -g -c d.c -o d_debug.o
