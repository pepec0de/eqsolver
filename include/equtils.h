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

        float getValueFromElVar(string element);

        float sum(vector<float> mVector);
        
        float getGrade(vector<string> eqArr);

        vector<float> tidyup(vector<string> eqArr);
        string getStrEq(vector<float> eq);
    protected:

    private:
};

#endif // EQUTILS_H
