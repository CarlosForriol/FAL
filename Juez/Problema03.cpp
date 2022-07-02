// Nombre del alumno Carlos Forriol Molina
// Usuario del Juez E23


follow 👉@aestheticfitgods
follow 👉@aestheticfitgods


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
struct tDatos {
	int sumtotal = 0;
	int numElem = 0;
};


// Función que resuelve el problema
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma
tDatos resolver(vector<int> v) {
	// Inicialización de variables
	tDatos datos;
	int numMenor = v[0], m = 0;

	// Codigo del alumno

	for (int i = 1; i < v.size(); ++i) { // 1
		// Aqui el código del alumno
		// No deben hacerse más bucles
		datos.sumtotal += v[i];
		if (numMenor > v[i] || numMenor == v[i]) {
			if (numMenor == v[i]) {
				m++;
			}
			else {
				m = 1;
				numMenor = v[i];
			}
		}


	}
	datos.numElem = v.size() - m;
	datos.sumtotal += -m * numMenor;

	return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	tDatos datos;
	// Lectura de los datos
	int numElem;
	std::cin >> numElem;
	std::vector<int> v(numElem);
	for (int& i : v) std::cin >> i;
	// LLamar a la función resolver
	datos = resolver(v);
	// Escribir los resultados
	std::cout << datos.sumtotal << ' ' << datos.numElem << '\n';
}

int main() {
	// Para la entrada por fichero. Comentar para mandar a acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	// Para restablecer entrada. Comentar para mandar a acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}