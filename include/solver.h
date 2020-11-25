#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class solver {
    public:
        vector<int> getHornerRoots(vector<float> eq);
        float func(vector<float> eq, int x);
    protected:
    private:
};

#endif // SOLVER_H
