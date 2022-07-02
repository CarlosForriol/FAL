//Carlos Forriol Molina
//E23
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void escribir(std::vector <int> const& v) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 0) {
			cout << "azul ";
		}
		if (v[i] == 1) {
			cout << "rojo ";
		}
		if (v[i] == 2) {
			cout << "verde ";
		}

	}
	std::cout << '\n';
}
void resolver(int m, int k, std::vector <int>& sol) {
	for (int i = 0; i < 3 ; ++i) {
		sol[k] = i;
		if (k == m - 1) { // Es solucion
			escribir(sol);
		}
		else { // Sigue completando la soluci´on
			resolver(m,k + 1, sol);
		}
	}
}
bool resuelveCaso() {
	// Lectura de los datos de entrada
	int m; std::cin >> m;
	
	if (m==0) return false;
	// Generar las soluciones
	std::vector <int > sol(m);
	resolver(m, 0, sol);
	cout << endl;
	return true;
	
}



int main() {
# ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos . txt
# endif
	while (resuelveCaso()) {} // Resolvemos todos los casos
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);

	system("PAUSE");
# endif
	return 0;
}