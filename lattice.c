#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#include "lattice.h"


SquareLattice create_lattice(int Lx, int Ly, bool pbc) {
    SquareLattice lat;
    lat.Lx = Lx;
    lat.Ly = Ly;
    lat.L = Lx * Ly;
    lat.pbc = pbc;

    //on creer le tableau
    lat.spins = (int **)malloc(Lx * sizeof(int *));
    
    for (int i = 0; i < Lx; i++) {
        // chaque ligne on créer une colonne (liste dans liste)
        lat.spins[i] = (int *)malloc(Ly * sizeof(int));
        
        // au hasard -1 ou 1
        for (int j = 0; j < Ly; j++) {
            int pile_ou_face = rand() % 2;
            if (pile_ou_face == 0) {
                lat.spins[i][j] = -1;
            } else {
                lat.spins[i][j] = 1;
            }
        }
    }
    return lat;
}

void free_lattice(SquareLattice *lat) {
    for (int i = 0; i < lat->Lx; i++) {
        free(lat->spins[i]);
    }
    free(lat->spins);
}



double compute_autocorrelation(double *obs, int n_steps, int tau) {
    if (tau >= n_steps) return 0.0; // Sécurité

    double mean = 0.0;
    double var = 0.0;
    
    // espérence
    for (int i = 0; i < n_steps; i++) {
        mean += obs[i];
    }
    mean /= n_steps;

    // variance
    for (int i = 0; i < n_steps; i++) {
        var += (obs[i] - mean) * (obs[i] - mean);
    }
    var /= n_steps;

    if (var == 0.0) return 0.0; 

    // Covariance (numérateur de la formule) [cite: 109]
    double autocov = 0.0;
    int n_pairs = n_steps - tau; 
    
    for (int i = 0; i < n_pairs; i++) {
        autocov += (obs[i] - mean) * (obs[i + tau] - mean);
    }
    autocov /= n_pairs;

    return autocov / var;
}
