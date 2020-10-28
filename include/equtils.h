#ifndef EQUTILS_H
#define EQUTILS_H

#include <iostream>
#include <vector>

using namespace std;

class equtils {
    public:
        char VAR = 'x';
        bool hasVar(string element);
        bool hasVarWpow(string element);
        float getVarPow(string element);

        float getElementVar(string element);

        float sum(vector<float> mVector);
        /*
        equtils();
        virtual ~equtils();
        */
    protected:

    private:
};

#endif // EQUTILS_H
