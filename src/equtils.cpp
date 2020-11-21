#include "../include/equtils.h"
#include "../include/stringutils.h"

stringutils str;

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

// Funcion para obtener el valor que acompaña a una variable x
float equtils::getValueFromElVar(string element) {
    if (hasVar(element)) {
        string val = "";
        // Obtenemos todos los elementos antes de llegar a la x
        for (unsigned int i = 0; i < element.size(); i++) {
            if (element[i] == VAR) break;
            val += element[i];
        }
        // Hacemos un try por si el stof no reconoce numeros
        try {
            return stof(val);
        } catch(exception& e) {
            cout << "[DEBUG] stof no reconoce el numero : " << val << endl;
            // Devolvemos 1 por que ya sabemos que la variable esta
            return 1;
        }
        return 0;
    }
    return 0;
}

// Funcion para sumar todos los elementos de un vector
float equtils::sum(vector<float> mVector) {
    float result = 0;
    for (unsigned int i = 0; i < mVector.size(); i++) {
        result += mVector[i];  
    }
    return result;
}

// Funcion para obtener el grado de polinomio/ecuacion
float equtils::getGrade(vector<string> pArr) {
    float grade = 0;
    for (unsigned int i = 0; i < pArr.size(); i++) {
        float currPow = getVarPow(pArr[i]);
        if(currPow > grade && getValueFromElVar(pArr[i]) != 0) {
            grade = currPow;
        }
    }
    return grade;
}

// Funcion para simplificar y ordenar un polinomio de grado n
vector<float> equtils::tidyup(vector<string> eqArr) {
    // Tamaño del vector de vectores tiene que ser el grado
    // +1 para que los terminos independientes tengan hueco
    const unsigned int size = getGrade(eqArr)+1;
    vector<vector <float>> poly;
    for (unsigned int i = 0; i < size; i++) poly.push_back({0});
    // Inicializamos los vectores
    float sign = +1;
    for (unsigned int i = 0; i < eqArr.size(); i++) {
        /*
         * Iteramos por cada elemento y lo asignamos a un vector
         * de la matriz doble poly que este en el indice de su potencia
         * Los terminos independientes estaran en el indice 0
         */
        string element = eqArr[i];
        if (element == "=") {
            // Pasamos al otro vector para recoger el otro lado y cambiamos el
            // signo de los elementos.
            sign = -1;
            // Saltamos el bucle para no almacenar '='
            continue;
        }
        
        if (hasVar(element)) {
            // Añadimos el elemento al vector (indice : la potencia que tiene
            // la variable del elemento) de tipo numerico
            poly[(unsigned int)getVarPow(element)].push_back(getValueFromElVar(element)*sign);
            // Saltamos el bucle para pasar a otro elemento
            continue;
        }
        // Como no tiene variable lo añadimos a idx=0
        poly[0].push_back(stof(element)*sign);
    }

    // Iteramos del final hacia el principio
    // Cuando ya hemos añadido los todos elementos a sus respectivos
    // vectores hacemos la suma.
    vector<float> result;
    // Inicializamos el vector
    for (unsigned int i = 0; i < size; i++) result.push_back(0);
    for (unsigned int i = 0; i < size; i++) {
        // Limpiamos el vector y sumamos el vector
        result[i] = sum(poly[i]);
    }
    return result;
}

string equtils::getStrEq(vector<float> eq) {
    string result = "";
    for (int i = (eq.size()-1); i > -1; i--) {
        // Lo pasamos a formato: "ax^n +bx^n-k +cx +d = 0"
        if (i == 0) result += str.tostring(eq[i]);
        else if (i == 1) result += str.tostring(eq[i]) + "x";
        else result += str.tostring(eq[i]) + "x^" + str.tostring(i);
        if(i != 0) result += " ";
    }
    return result;
}
