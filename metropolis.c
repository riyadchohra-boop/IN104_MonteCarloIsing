#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h> 

#include "lattice.h"
#include "utils.h"
#include "model.h"





double boltzman_probability(double energy, double T){
    int i = rand()%model->lat->Lx;
    int j = rand()%model->lat->Ly;
    int current_spin = model->lat->spins[i][j];

    int right = 0, left = 0, bottom = 0, top = 0;
    
}
