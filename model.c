#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>  
#include "utils.h"
#include "lattice.h"
#include "model.h"


ising *define_model(double J, double B, double T, SquareLattice *lat){

    ising *model = malloc(sizeof(ising));

    model -> J = J;
    model -> B = B;
    model -> T = T;

    model -> lat = lat;

    return model;
}

