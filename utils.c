#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>



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



    
    double autocov = 0.0;
    int n_pairs = n_steps - tau; 
    
    for (int i = 0; i < n_pairs; i++) {
        autocov += (obs[i] - mean) * (obs[i + tau] - mean);
    }
    autocov /= n_pairs;

    return autocov / var;
}


