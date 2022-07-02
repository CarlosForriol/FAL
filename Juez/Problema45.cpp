#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
void escribirSolucion(std::vector <char > const& v) {
	for (char c : v) std::cout << c;
	std::cout << '\n';
}
// Calcula de forma recursiva las variaciones de los elementos
void variaciones(int m, int n, int k, std::vector <char >& sol) {
	for (char i = 'a'; i < 'a' + m; ++i) {
		sol[k] = i;
		if (k == n - 1) { // Es solucion
			escribirSolucion(sol);
		}
		else { // Sigue completando la soluci´on
			variaciones(m, n, k + 1, sol);
		}
	}
	
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	int m, n; std::cin >> m >> n;
	if (!std::cin) return false;
	// Generar las soluciones
	std::vector <char > sol(n);
	variaciones(m, n, 0, sol);
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
	system(" PAUSE ");
# endif
	return 0;
}