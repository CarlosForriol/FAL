//Carlos Forriol Molina
//E23
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

char resolver(std::vector<char> const& presos, int const& ini, int const& fin, char const& prim, char const& ultim) {
	int medio = (ini + fin) / 2;
	if (ini >= (int)presos.size()) {
		return ultim;
	}
	if (ini > fin) {
		return presos[ini] - 1;
	}
	else{
		if (presos[medio]-prim == medio) {
			return resolver(presos,medio+1,fin,prim,ultim);
		}
		else {
			return resolver(presos,ini,medio-1,prim,ultim);
		}
	}
}





void resuelveCaso() {
	char prim, ultim;
	std::cin >> prim >> ultim;
	std::vector<char> presos;
	presos.reserve(ultim - prim);

	char aux;
	for (size_t i = 0; i < presos.capacity();++i) {
		std::cin >> aux;
		presos.push_back(aux);
	}
	char sol = resolver(presos, 0, presos.size() - 1, prim, ultim);
	// escribir sol
	std::cout << sol << "\n";
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
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}