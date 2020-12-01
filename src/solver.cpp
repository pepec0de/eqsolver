#include "../include/solver.h"

// Funcion para determinar las raices de un polinomio (alg. de Horner)
vector<int> solver::getHornerRoots(vector<float> eq) {
    vector<int> roots;
    for (int x = 1; x < 10; x++) {
        if (func(eq, x) == 0) roots.push_back(x);
        if (func(eq, x*(-1)) == 0) roots.push_back(x*(-1));
    }

    return roots;
}

// Funcion para hallar la 'y' del polinomio dada la 'x'
float solver::func(vector<float> eq, int x) {
    // Hacemos el sumatorio
    float sum = 0;
    for (unsigned int i = 0; i < eq.size(); i++) {
        if (i == 0) {
            sum += eq[i];
        } else {
            sum += eq[i]*pow(x, i);
        }
    }
    return sum;
}
