//Carlos Forriol Molina
//E23
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
bool esValida(int k, std::vector <int>& sol) {
	if (sol.size() - 1 != 0 && sol[k] == 2 && sol[k] == sol[k - 1]){ //no dos verdes seguidos
		return false;
	}
}
void escribir(std::vector <int> const& v) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 0) {
			cout << "azul " << endl;
		}
		if (v[i] == 1) {
			cout << "rojo " << endl;
		}
		if (v[i] == 2) {
			cout << "verde " << endl;
		}

	}
	std::cout << '\n';
}
void resolver(int m, int k, std::vector <int>& sol) {
	sol[0] = 1;
	for (int i = 0; i < 3; ++i) {
		sol[k] = i;
		if (esValida(k, sol)) {
			if (k == m - 1) { // Es solucion
				escribir(sol);
			}
			else { // Sigue completando la soluci´on
				resolver(m, k + 1, sol);
			}
		}
	}
	
}
bool resuelveCaso() {
	// Lectura de los datos de entrada
	int m; std::cin >> m;
	std::vector <int > sol(m);
	if (m == 0) return false;
	if (m == 1) {
		cout << "rojo " << endl;
	}
	else resolver(m,1,sol);
	// Generar las soluciones
	
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