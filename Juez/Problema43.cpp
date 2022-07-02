//Carlos Forriol Molina
//E23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// el coste sera O(n) --> siendo numero de elementos del vector
bool resolver(std::vector<int> const& v, int ini, int fin, int& min, int& max) {
	if (ini >= fin) return true; // Si hay solo un elemento
	else if (ini + 1 == fin) {// 2 elementos
		if (v[ini] <= v[fin]) {
			 min=v[ini];
			 max =v[fin];
			return true;
		}
		else false;
	}
	else {
		int mitad = (ini + fin) / 2;
		int minizq, maxizq, minder, maxder;
		bool ladoIzq = resolver(v, ini, mitad, minizq, maxizq);
		bool ladoDer = resolver(v, mitad + 1, fin, minder, maxder);

		if (ladoDer && ladoIzq) {
			if (maxizq <= maxder && minizq <= minder) {
				max = maxder;
				min = minizq;
				return true;
			}
			else return false;
		}
		else return false;

	}
}


bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (num == 0) return false;

	std::vector<int> v;

	while (num != 0) {
		v.push_back(num);
		std::cin >> num;
	}

	int min, max;
	bool sol = resolver(v, 0, (int)v.size() - 1, min, max);

	// escribir sol
	if (sol) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

	return true;
}

int main() {
	
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt:
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