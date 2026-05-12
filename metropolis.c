
#include "metropolis.h"


double boltzman_probability(double delta_E, double T) {
    return exp(-delta_E / T);
}


int move(ising *model, int *state) {
    int i = rand() % model->lat->Lx;
    int j = rand() % model->lat->Ly;
    int current_spin = model->lat->spins[i][j];

    int right = 0, left = 0, top = 0, bottom = 0;

  
    if (model->lat->pbc) {
        right  = model->lat->spins[(i + 1) % model->lat->Lx][j];
        left   = model->lat->spins[(i - 1 + model->lat->Lx) % model->lat->Lx][j];
        bottom = model->lat->spins[i][(j + 1) % model->lat->Ly];
        top    = model->lat->spins[i][(j - 1 + model->lat->Ly) % model->lat->Ly];
    } else {
        if (i + 1 < model->lat->Lx) right  = model->lat->spins[i + 1][j];
        if (i - 1 >= 0)             left   = model->lat->spins[i - 1][j];
        if (j + 1 < model->lat->Ly) bottom = model->lat->spins[i][j + 1];
        if (j - 1 >= 0)             top    = model->lat->spins[i][j - 1];
    }

    int sum_neighbors = right + left + top + bottom;

    double delta_E = 2.0 * model->J * current_spin * sum_neighbors;

    // 4 & 5. Évaluation de l'acceptation du mouvement
    if (delta_E < 0.0) {
        // L'énergie du système diminue : on accepte toujours le mouvement
        model->lat->spins[i][j] = -current_spin;
        return 1;
    } else {
        // L'énergie augmente : on accepte avec une probabilité e^(-delta_E / T)
        double r = (double)rand() / RAND_MAX; // Tirage aléatoire entre 0.0 et 1.0
        
        if (r < boltzman_probability(delta_E, model->T)) {
            model->lat->spins[i][j] = -current_spin;
            return 1;
        }
    }

    return 0;
}
