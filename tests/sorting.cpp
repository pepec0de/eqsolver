#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> val) { 
    for (unsigned int i = 0; i < val.size(); i++) {
        cout << val[i] << endl;
    }
}

// Trabajamos mejor con vectores ya que son mas dinamicos
vector<int> sort(vector<int> arr) {
    // Ponemos 6 ceros
    vector<int> result (6, 0);
    // Vamos a hacer un algoritmo que ordene valores de MAYOR a MENOR
    // Primero obtenemos el indice del primer valor
    for (unsigned int i = 0; i < arr.size(); i++) {
        int max_idx = i;
        // Buscamos un valor mas grande en lo que queda de lista
        for (unsigned int j = i+1; j < arr.size(); j++) {
            if (arr[max_idx] < arr[j]) {
                max_idx = j;
            }
        }
        // Ahora swapeamos el elemento encontrado con el otro
        int temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
    return arr;
}

int main() {
    vector<int> n = {4, 3, 5, 1, 0, 2};
    printVector(n);
    cout << "SORTED" << endl;
    printVector(sort(n));
}
