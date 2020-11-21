#include <iostream>
#include <vector>
#include <math.h>

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
            cout << eqUtils.VAR << " = " << a << "/" << b << " = " << a/b << endl;
        }break;
		
		case 2: { // ECUACION DE SEGUNDO GRADO
            float a = eq[2];
            float b = eq[1];
            float c = eq[0];
            float d = b*b-4*a*c;
            float sd = sqrt(d);
            if (d == 0) {
                cout << eqUtils.VAR << " = " << -b << "/" << 2*a << " = " << -b/2*a << endl;
            } else if (d > 0) {
                cout << eqUtils.VAR << "1 = (" << -b << " + " << sd << ")/" << 2*a << 
                    " = " << (-b+sd)/2*a << endl;
                cout << eqUtils.VAR << "2 = (" << -b << " - " << sd << ")/" << 2*a << 
                    " = " << (-b-sd)/2*a << endl;
            } else {
                cout << eqUtils.VAR << " = Irreal answer!" << endl;
            }
        }break;

        case 3: { // TERCER GRADO
                
        }break;
	}
}
