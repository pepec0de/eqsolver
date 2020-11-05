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
		eqStr = "4x = 2";
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
	cout << "Su ecuación es de nivel: "	<< getEqGrade(eqArr) << endl;
	solveEq(eqArr);
}

float getEqGrade(vector<string> eqArr) {
	float grade = 0;
	for (unsigned int i = 0; i < eqArr.size(); i++) {
		if (eqUtils.hasVar(eqArr[i])) {
			if (eqUtils.getVarPow(eqArr[i]) > grade) {
				grade = eqUtils.getVarPow(eqArr[i]);
			}
		}
	}
	return grade;
}

void solveEq(vector<string> eqArr, int level) {
	switch (getEqGrade(eqArr)) {
		case 1: // ECUACION DE PRIMER NIVEL
			// Hacemos dos vectores de polinomios
			// Uno con los elementos del primer lado y el otro con los del otro lado
			vector<string> poly1, poly2;
			bool sameFind = false;
			for (unsigned int i = 0; i < eqArr.size(); i++) {
				if (eqArr[i] == "=") {
					// Pasamos al otro vector
					sameFind = true;
					continue;
				}
				if (sameFind) {
					poly2.push_back(eqArr[i]);
				} else {
					poly1.push_back(eqArr[i]);
				}
			}
			// Creamos otros dos vectores para almacenar las cifras
			// En el primero guardaremos las Xs y en el segundo los independientes
			vector<float> polyVar, polyVal;
			for (unsigned int i = 0; i < poly1.size(); i++) {
				if (eqUtils.hasVar(poly1[i])) {
					polyVar.push_back(stof(strUtils.getSubstring(poly1[i], -1)));
				} else {
					polyVal.push_back(stof(poly1[i])*(-1));
				}
			}
			for (unsigned int i = 0; i < poly2.size(); i++) {
				if (eqUtils.hasVar(poly2[i])) {
					polyVar.push_back(stof(strUtils.getSubstring(poly1[i], -2))*(-1));
				} else {
					polyVal.push_back(stof(poly2[i]));
				}
			}
			// Ahora solo tenemos que imprimir : sum(polyVal)/sum(polyVar)
			cout << "Resultado: " << eqUtils.VAR << " = " << eqUtils.sum(polyVal)/eqUtils.sum(polyVar) << endl;
		break;
		
		case 2: // ECUACION DE SEGUNDO GRADO
			
		break;
	}
}
