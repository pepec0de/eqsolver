#include <iostream>
#include <vector>

#include "../include/equtils.h"
#include "../include/stringutils.h"

using namespace std;

float getEqGrade(vector<string> eqArr);
void solveEq(vector<string> eqArr);

equtils eqUtils;
stringutils strUtils;

int main() {
    cout << "Ecuación a resolver: ";
	// String para almacenar ecuacion
	string eqStr;
    // Hacemos un getline porque cin tan solo toma los datos hasta que
    // encuentra un espacio.
	getline(cin, eqStr);
	if (eqStr == "") {
		//eqStr = "4x = 2";
		eqStr = "1x^2 +1x -2 = 0";
	}

    cout << "Indique la incógnita: ";
    cin >> eqUtils.VAR;

	cout << "Su ecuación: " << eqStr << endl;
	
	// Comprobamos que es una ecuacion por el caracter '='
	for (unsigned int i = 0; i < eqStr.size(); i++) {
		if (eqStr[i] == '=') {
			break;
		}
		if (i == eqStr.size()) {
			cout << "Ecuación inválida!" << endl;
			exit(0);
		}
	}
	
	// Dividimos la string en ' ' para recoger los elementos y guardarlos en un vector
	vector<string> eqArr = strUtils.splitString(eqStr, ' ');
	cout << "Su ecuación es de nivel: "	<< eqUtils.getGrade(eqArr) << endl;
	//solveEq(eqArr);
    vector<string> simplifiedArr = eqUtils.tidyup(eqArr);
    string simplifiedStr = simplifiedArr[0];
    for (unsigned int i = 1; i < simplifiedArr.size(); i++) {
        simplifiedStr += " "+simplifiedArr[i];
    }
    simplifiedStr += " = 0;";
    cout << "Su ecuación simplificada es: " << simplifiedStr << endl;

}

void solveEq(vector<string> eqArr) {
	switch ((int)eqUtils.getGrade(eqArr)) {
		case 1: { // ECUACION DE PRIMER NIVEL
			// Hacemos dos vectores de polinomios
			// Uno con los elementos del primer lado y el otro con los del otro lado
			vector<float> polyVar, polyVal;
			bool isEqSymbFound = false;
			for (unsigned int i = 0; i < eqArr.size(); i++) {
                string element = eqArr[i];
				if (element == "=") {
					// Pasamos al otro vector
					isEqSymbFound = true;
					continue;
				}
                if (!isEqSymbFound) {
                    if (eqUtils.hasVar(element)) {
                        polyVar.push_back(stof(strUtils.getSubstring(element, -1)));
                    } else {
                        polyVal.push_back(stof(element)*(-1));
                    }
                } else {
                    if (eqUtils.hasVar(element)) {
                        polyVar.push_back(stof(strUtils.getSubstring(element, -1))*(-1));
                    } else {
                        polyVal.push_back(stof(element));
                    }
                }
            }
            cout << eqUtils.VAR << " = " << eqUtils.sum(polyVal) << " / " << eqUtils.sum(polyVar) << " = " << eqUtils.sum(polyVal)/eqUtils.sum(polyVar) << endl;
        }break;
		
		case 2: { // ECUACION DE SEGUNDO GRADO
			
        }break;
	}
}
