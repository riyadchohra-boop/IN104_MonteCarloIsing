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
    
    int **spins;  
    
} SquareLattice;


SquareLattice create_lattice(int Lx, int Ly, bool pbc);
void free_lattice(SquareLattice *lat); 



double compute_energy(SquareLattice *lat, double J);
double compute_magnetization(SquareLattice *lat);

double compute_autocorrelation(double *obs, int n_steps, int tau);

#endif
