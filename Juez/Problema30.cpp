// Carlos Forriol Molina
//E23
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int resolverFinal(int n, int pot, int num) {
	int aux = n % 10;
	if (n== 0) {
		return num + pot * 10 * aux + pot * aux;
	}
	else {
		return resolverFinal(n / 10, pot * 100, num + pot * 10 * aux + pot * aux);
	}
}
int resolverNoFinal(int n, int pot) {

	int aux = n % 10;

	if (n == 0)
	{
		return pot * 10 * aux + pot * aux;
	}
	else
	{
		return resolverNoFinal(n / 10, pot * 100) + pot * 10 * aux + pot * aux;
	}
}





void resuelveCaso() {

	int n, pot = 1, num = 0;

	cin >> n;

	cout << resolverNoFinal(n,pot) << " " << resolverFinal(n, pot, num) << endl;
	// escribir sol

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