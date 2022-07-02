#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool resolver(std::vector<int> const& v, int ini, int fin, int& suma) {

	if (ini >= fin) return true; //Si hay un solo elemento;

	else if (ini + 1 == fin) { //Si hay 2 elementos;
		//Guardamos la suma
		suma = v[ini] + v[fin];
		
		if (v[ini] < v[fin]) return true;
		else return false;
	}

	else { //Si hay mss de 2 elementos;
		int mitad = (ini + fin) / 2;
		int sumaIz = 0, sumaDr = 0;

		bool ladoIz = resolver(v, ini, mitad, sumaIz);
		bool ladoDe = resolver(v, mitad + 1, fin, sumaDr);

		//Comprobamos la condicion y actualizamos el acumulado tras 
		//cada nivel de profundidad de la recursion:
		if (ladoIz && ladoDe && sumaIz < sumaDr) {
			suma = sumaIz + sumaDr;
			return true;
		}
		else return false;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int filas;
	std::cin >> filas;

	if (!std::cin) return false;

	int columnas;
	std::cin >> columnas;

	//Declaramos la matriz:
	std::vector<std::vector<int>> v(filas);

	//Rellenamos la matriz:
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			int aux;
			std::cin >> aux;
			v[i].push_back(aux);
		}
	}

	bool sol = true;

	for (int i = 0; sol && (i < filas); ++i) {
		int suma = 0;
		sol = resolver(v[i], 0, columnas - 1, suma);
	}

	// escribir sol
	if (sol) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}