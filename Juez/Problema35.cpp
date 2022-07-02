//Carlos Forriol Molina
//E23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool resolver(std::vector<int> const& v, int const& ini, int const& fin, int const& num, int& n) {
	if (ini > fin)return false;
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad]== mitad+num) {
			n = v[mitad];
			return true;
		}
		else {
			if(v[mitad]>mitad + num) return resolver(v, ini, mitad - 1, num, n);
			else return resolver(v, mitad + 1, fin, num, n);
		}
	}
}




void resuelveCaso(){
	int tam, num;
	std::cin >> tam >> num;
	std::vector<int> v(tam);

	for (size_t i = 0; i < v.size(); ++i)
		std::cin >> v[i];

	int n;
	bool sol = resolver(v, 0, tam - 1, num, n);

	// escribir sol
	if (!sol) std::cout << "NO" << "\n";
	else std::cout << n << "\n";
}





int main() {
	// Para la entrada por fichero.
	
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