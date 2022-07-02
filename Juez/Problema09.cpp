// Nombre del alumno Carlos Forriol Molina
// Usuario del Juez E23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


int resolver( std::vector <int>&v, int w) {
	int sinHueco = 0;
	int conHueco = 0;
	int max;
	int sol = 0;
	for (int i = 0; i < v.size();++i) {
		if (v[i] == 1) ++sinHueco;
		else if (v[i] == 0) ++conHueco;
	}
	max = conHueco;
	for (int j = w; j < v.size(); ++j) {
		if (v[j - w] == 0) {
			--conHueco;
		}
		else if (v[j - w] == 1) {
			--sinHueco;
		}
		if (v[j] == 0) {
			++conHueco;
		}
		else if (v[j] == 0) {
			++sinHueco;
		}
		if (conHueco >= max) {
			max = conHueco;
			sol = j - w + 1;
		}
	}
	if (max == 0) sol = -1;
	return sol;
}
bool resuelveCaso() {
	int numElementos;
	std::cin >> numElementos;
	if (numElementos == 0) return false;

	int longitud, c;
	std::cin >> longitud;
	std::vector<int> v;
	for (int i = 0; i < numElementos; ++i) {
		std::cin >> c;
		v.push_back(c);
	}
	int sol = resolver(v, longitud);
	if (sol == -1) {
		std::cout << "No hace falta\n";

	}
	else {
		std::cout <<sol<< "\n";
	}
	return true;

}
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}