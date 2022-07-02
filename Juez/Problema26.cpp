#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;



long long int resolver(long long int n, long long int p) {
	if (n < 10 && p==0 ) {
		return n;
	}
	else if ( n==0) {
		return p;
	}
	else {
		return resolver(n / 10, p * 10 + n % 10);
	}

}


bool resuelveCaso() {
	long unsigned int n,p=0;
	std::cin >> n;

	if (n == 0) return false;

	long long int solucion = resolver(n,p);

	// escribir sol
	std::cout << solucion << "\n";

	return true;
}



int main() {
	// Para la entrada por fichero.
	
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}