// Carlos forriol Molina
//E23

#include <iostream>
#include <iomanip>
#include <fstream>
using lli = long long int;

lli resolver(int num, lli a, lli b) {

	if (num == 0) return b;
	else if (num == 1) return a;

	else return resolver(num - 1, a + b, a);
}
bool resuelveCaso() {
	int num;
	std::cin >> num;

	if (!std::cin) return false;

	// escribir sol (recursividad simple):
	std::cout << resolver(num, 1, 0) << "\n";

	// escribir sol (recursividad multiple):
	// std::cout << resolverMultiple(num) << "\n";

	return true;
}
int main() {
# ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .txt
# endif
	while (resuelveCaso())
		;
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	// system (" PAUSE ");
# endif
	return 0;
}