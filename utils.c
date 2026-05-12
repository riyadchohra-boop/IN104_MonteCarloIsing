#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>


double calc_mean(double arr[], int N){
    double mean = 0.0;
    for (int i = 0; i < N; i++) {
        mean += arr[i];
    }
    return mean / N;
}

double calc_variance(double arr[], int N){
    double var = 0.0;
    double mean = calc_mean(arr ,N );
    for (int i = 0; i < N; i++) {
        var += (arr[i] - mean) * (arr[i] - mean);
    }
    return var / N;

}


double compute_autocorrelation(double *arr, int N, int tau) {
    if (tau >= N) return 0.0; // Sécurité

    double mean = calc_mean(arr, N);
    double var = calc_variance(arr, N);
    if (var == 0.0) return 0.0; 

    double autocov = 0.0;
    int n_pairs = N - tau; 
    
    for (int i = 0; i < n_pairs; i++) {
        autocov += (arr[i] - mean) * (arr[i + tau] - mean);
    }
    autocov /= n_pairs;

    return autocov / var;
}


