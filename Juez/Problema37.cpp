#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
int resolver(std::vector<int>& v, int ini, int fin) {
	if (ini >= fin) return 0;
	else {
		int mitad = (ini + fin) / 2;

		int izq = resolver(v, ini, mitad);
		int der = resolver(v, mitad + 1, fin);
		int cont = 0;

		if (v[ini] > v[mitad + 1]) {
			cont += (mitad - ini + 1);
			++mitad + 1;

		}
		else ++ini;
		
		std::sort(v.begin() + ini, v.begin() + fin + 1); // O(n log(n))
		return izq + der + cont;
	}
	
}
bool resuelveCaso(){
	int num;
	std::cin >> num;

	if (!std::cin)
		return false;
	std::vector<int> v(num);
	for (int& aux : v)
		std::cin >> aux;

	int sol = resolver(v, 0, num - 1);
	std::cout << sol << "\n";

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