//Carlos Forriol Molina
//E23
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
struct tDatos {
	int m, n;
};
struct tSol {
	std::vector <char> sol;
	std::vector <bool> marcas;
};
void escribirSol(std::vector <char > const& v) {
	for (char c : v) std::cout << c;
	std::cout << '\n';
}

void resolver(tDatos const& datos, int k, tSol& s){
	for (char i = 'a'; i < 'a' + datos.m; ++i) {
		s.sol[k] = i;
		if (!s.marcas[i - 'a']) {// si la letra no utilizada
			s.marcas[i - 'a'] = true;
			if (k = datos.n - 1) { // es sol
				escribirSol(s.sol);
			}
			else {//Resto de sol
				resolver(datos, k + 1, s);
			}
			s.marcas[i - 'a'] = false;
		}

	}

}

bool resuelveCaso() {
	int m, n; std::cin >> m >> n;
	if (!std::cin) return false;
	tSol s;
	s.sol.resize(n);
	s.marcas.assign(m, false);
	resolver({ m , n }, 0, s);
	std::cout << '\n';
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