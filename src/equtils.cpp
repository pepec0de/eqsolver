#include "../include/equtils.h"

// Func to check if an element has the var
bool equtils::hasVar(string element) {
	for (unsigned int i = 0; i < element.size(); i++) {
        if (element[i] == VAR) {
            return true;
        }
    }
    return false;
}

// Func to check if an element has a pow with the var
bool equtils::hasVarWpow(string element) {
    // Suponemos que seria 1x^2: x^
    for (unsigned int i = 0; i < element.size(); i++) {
        if (element[i] == equtils::VAR && element[i+1] == '^') {
            return true;
        }
    }
    return false;
}

// Func to get the pow of the var
float equtils::getVarPow(string element) {
    string strPow;
    if (equtils::hasVarWpow(element)) {
        for (unsigned int i = 0; i < element.size(); i++) {
            // Obtenemos la posicion i localizando la variable
            if (element[i] == equtils::VAR) {
                for (unsigned int j = i+2; j < element.size(); j++) {
                    // Obtenemos todos los numeros despues del ^
                    strPow += element[j];
                }
                return stof(strPow);
            }
        }
    } else {
        return 1;
    }
    return 0;
}

float equtils::getElementVar(string element) {
    return 0;
}

float equtils::sum(vector<float> mVector) {
    float result = 0;
    for (unsigned int i = 0; i < mVector.size(); i++) {
        result += mVector[i];  
    }
    return result;
}

// Funcion para simplificar y ordenar una ecuacion/polinomio
vector<string> equtils::getTidied(vector<string> eqArr) {
    vector<string> simplified;
    
    vector<string> poly1, poly2;

    for (unsigned int i = 0; i < eqArr.size(); i++) {
        if (eqArr[i] == "=") {
            sameFind = true;
        }
    }
    return simplified;
}
