#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "utils.h"
#include "lattice.h"
#include "model.h"
#include "metropolis.h"

int main() {

    // read params from file "config.txt"

    double T, B;
    int Lx, Ly, N_tot, N_eq;

    FILE *fp = fopen("config.txt", "r");
    fscanf(fp, "T %lf \n", &T);
    printf("Temperature T = %lf \n", T);
    
    fscanf(fp, "B %lf \n", &B);
    printf("External field B = %lf \n", B);
    
    fscanf(fp, "Lx %d \n", &Lx);
    fscanf(fp, "Ly %d \n", &Ly);
    printf("Square lattice Lx = %d Ly = %d \n", Lx, Ly);
    
    fscanf(fp, "N_tot %d \n", &N_tot);
    fscanf(fp, "N_eq %d \n", &N_eq);
    printf("Metropolis N_tot = %d \n", N_tot);
    printf("Metropolis N_eq = %d \n", N_eq);

    fclose(fp);



}


