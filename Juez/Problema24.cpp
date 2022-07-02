
// Nombre Carlos Forriol Molina
//Usuario E23

#include <iostream>
#include <fstream>
#include <string>
using namespace std;





unsigned  long int resolver(unsigned long int n) {
	if (n < 10) {
		if (n % 2 != 0) {
			return n;
		}
		else {
			return 0;
		}
	}
	else {
		int rest = n % 10;
		if (rest % 2 != 0) {
			return resolver(n / 10) * 10 + rest;
		}
		else {
			return resolver(n / 10);
		}
	}
	

}

bool resuelveCaso() {
	unsigned long int n;
	std::cin >>n;
	if (!std::cin) return false;
	unsigned long int solucion = resolver(n);
	std::cout << solucion << '\n';
	return true;
}

int main() {
# ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .txt
# endif
	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}