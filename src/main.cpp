#include <iostream>
#include <vector>

#include "../include/equtils.h"
#include "../include/stringutils.h"

using namespace std;

void solveEq(vector<float> eq);

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
    string simplifiedStr = eqUtils.getStrEq(eqUtils.tidyup(eqArr));
    cout << "Su ecuación simplificada es: " << simplifiedStr << " = 0;\n";
    solveEq(eqUtils.tidyup(eqArr));
}

void solveEq(vector<float> eq) {
	switch (eq.size()-1) { // Ecuacion de distintos grados
		case 1: { // ECUACION DE PRIMER NIVEL
            float a = eq[0]*-1;
            float b = eq[1];
            cout << eqUtils.VAR << " = " << a << " / " << b << " = " << a/b << endl;
        }break;
		
		case 2: { // ECUACION DE SEGUNDO GRADO
			/* Aplicamos la ecuacion para : 
             * a = arr[2]; b = arr[1]; c = arr[0];
             * x1 = (-b + d) / 2*a;
             * x2 = (-b - d) / 2*a; 
             * Siendo d >= 0
             * d = b^2 -4*a*c
             */

        }break;

        case 3: { // TERCER GRADO
                
        }break;
	}
}
