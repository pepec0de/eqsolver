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
        if (element[i] == VAR && element[i+1] == '^') {
            return true;
        }
    }
    return false;
}

// Func to get the pow of the var
float equtils::getVarPow(string element) {
    string strPow;
    if (hasVarWpow(element)) {
        for (unsigned int i = 0; i < element.size(); i++) {
            // Obtenemos la posicion i localizando la variable
            if (element[i] == VAR) {
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

// Funcion para obtener el grado de polinomio/ecuacion
float equtils::getGrade(vector<string> pArr) {
    float grade;
    for (unsigned int i = 0; i < pArr.size(); i++) {
        float currPow = getVarPow(pArr[i]);
        if(currPow > grade) {
            grade = currPow;
        }
    }
    return grade;
}
// Funcion para simplificar y ordenar un polinomio de grado n
vector<string> equtils::tidyup(vector<string> eqArr) {
    vector<string> simplified;
    
    vector<float> polyVar, polyVal; 
    bool isEqSymbFound = false;
    for (unsigned int i = 0; i < eqArr.size(); i++) {
        string element = eqArr[i];
        if (element == "=") {
            // Pasamos al otro vector para recoger el otro lado
            isEqSymbFound = true;
            // Saltamos la rutina para no almacenar '='
            continue;
        }
        if (!isEqSymbFound) {
            // Añadimos el elemento al vector de tipo numerico
            if (hasVar(element)) {

            }
        } else {

        }
    }
    return simplified;
}
