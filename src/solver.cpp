#include "../include/solver.h"

// Funcion para determinar las raices de un polinomio (alg. de Horner)
vector<int> solver::getHornerRoots(vector<float> eq) {
    vector<int> roots;
    return roots;
}

// Funcion para hallar la 'y' del polinomio dada la 'x'
float solver::func(vector<float> eq, int x) {
    // Hacemos el sumatorio
    float sum;
    for (unsigned int i = 0; i < eq.size(); i++) {
        if (i == 0) {
            sum += eq[i];
        } else {
            sum += eq[i]*pow(x, i);
        }
    }
    return sum;
}
