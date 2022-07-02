# include <iostream>
# include <fstream>
# include <vector>
using namespace std;
std::vector <int> resolver(std::vector <int > const& v, int inicio) {
	std::vector <int > sol;
	int PIBMax = v[0];
	 // posicion del primer maximo
	for (int k = 0; k < v.size(); ++k) {
		if (v[k] > PIBMax) { // Encontrado nuevo maximo
			PIBMax = v[k];
			sol.push_back(k + inicio);
		}
	}
	return sol;
}
void resuelveCaso() {
	// Lectura de los datos
	int inicio, fin;
	std::cin >> inicio >> fin;
	std::vector <int > v(fin - inicio + 1);
	for (int& n : v) std::cin >> n;
	// Resolver el problema
	std::vector <int> sol = resolver(v, inicio);
	// Escribir los datos de salida
	if (sol.size() > 0) std::cout << sol[0];
	for (int i = 0; i < sol.size(); ++i)
		std::cout << " " << sol[i];
	std::cout << "\n";
}
int main() {
	// Para la entrada por fichero .
# ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
# endif
	// Entrada con numero de casos
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso()
		;
	// Para restablecer entrada .
# ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}