// Nombre del alumno Carlos Forriol Molina
// Usuario del Juez E23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
/*
coste = maximo ente coste de sus dos bucles
Primero=O(n) n= num valores
Segundo =O(max) 
O(max(n,max))
*/

std::vector<int> resolver(std::vector <int> const& v, int max) {
	std::vector <int> repeticiones(max + 1);
	std::vector<int> a;
	int maxVeces =0 ;
	for (int i = 0; i < v.size();++i) {
		repeticiones[v[i]]++;
		if (repeticiones[v[i]] > maxVeces) {
			maxVeces = repeticiones[v[i]];
		}
	}
	for (int i = repeticiones.size() - 1; i > 0; --i) {
		if (repeticiones[i] == maxVeces) {
			a.push_back(i);
		}
	}
	return a;
}
bool resuelveCaso() {
	int numtiradas, max;
	std::cin >> numtiradas >> max;
	if (numtiradas == -1) return false;
	std::vector <int> v(numtiradas);
	for (int& i : v) std::cin >> i;
	std::vector <int> res = resolver(v, max);
	for (int i = 0; i < res.size(); ++i) {
		std::cout << res[i] << ' ';
	}
	std::cout << "\n";
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