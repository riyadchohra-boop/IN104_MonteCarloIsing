#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double pi(int N){
    int n_cercle = 0;
    for(int i= 0; i<N; i++){
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        if ((1/2-x)*(1/2-x)+(1/2-y)*(1/2-y)<=1){
            n_cercle=n_cercle+1;
        }
    }
    double pi = (4.0*n_cercle)/N;
    printf("%.5f\n", pi);
    return pi;
}

double gauss(int N){
    int n_gauss = 0;
    double R=6.0;
    for(int i= 0; i<N; i++){
        double x = R*(double)rand()/RAND_MAX;
        x = x-3;
        double y = (double)rand()/RAND_MAX;
        if (exp(-(x*x))>=y){
            n_gauss=n_gauss+1;
        }
    }
    double gauss = R*n_gauss/N;
    printf("%.5f = %.5f\n", gauss, sqrt(3.1415));
    return gauss;
}

double integrale(int N){
    int n_integ = 0;
    double R=5.0;
    for(int i= 0; i<N; i++){
        double x = R*(double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        if (exp(-x)/(1+(x-1)*(x-1))>=y){
            n_integ++;
        }
    }
    double integ = R*n_integ/N;
    printf("%.5f\n", integ);
    return integ;
}

int main(){
    int N=1000000;
    FILE *fpi = fopen("pi.dat", "w");
    FILE *fgauss = fopen("gauss.dat", "w");
    for(int n=10; n<10000; n=n+100){
        double pi_val = pi(n);
        double gauss_val = gauss(n);
        fprintf(fpi, "%.4f %d\n", pi_val, n);
        fprintf(fgauss, "%.4f %d\n", gauss_val, n);
    }
    fclose(fpi);
    fclose(fgauss);
    pi(N);
    gauss(N);
    integrale(N);   
}

