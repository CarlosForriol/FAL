// CArlos Forriol MOlina
//E23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector<int> const& v, int const& ini, int const& fin) {
	if (ini == fin) return v[ini];
	else {
		int mitad = (fin + ini) / 2;

		if (v[mitad] > v[mitad + 1]) return resolver(v, mitad + 1, fin);
		else return resolver(v, ini, mitad);

	}
}
bool resuelveCaso() {
	int tam;

	std::cin >> tam;
	if (!std::cin) return false;

	std::vector<int> curva(tam);

	for (size_t i = 0; i < curva.size(); i++)
		std::cin >> curva[i];

	int sol = resolver(curva, 0, tam - 1);

	// escribir sol
	std::cout << sol << "\n";

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}