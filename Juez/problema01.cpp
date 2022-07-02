// Nombre y apellidos del alumno Carlos Forriol Molina
// Usuario del juez de clase E23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado


// Funcion que lee de la entrada, resuelve el problema y escribe la salida
void resuelveCaso() {
	int n;
	std::cin >> n;
	int reps = 0;
	int max = n;
	// Declaración de variables
	// Codigo del alumno

	while (n != 0) {

		// Aqui codigo del alumno
		if (max == n) {
			reps++;
		}
		else if(max < n){
			reps = 1;
			max = n;
			
		}


		std::cin >> n;
	}

	// Escribir el resultado
	// Codigo del alumno
	cout << max << " " << reps<< endl;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}