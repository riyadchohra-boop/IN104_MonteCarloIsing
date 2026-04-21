#ifndef LATTICE_H
#define LATTICE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    
    int Lx;
    int Ly;
    int L;
    bool pbc;

}SquareLattice;



#endif