#include <iostream>
#include <fstream>
#include <string>
using namespace std;
long long int resolver(long long int n) {
	if (n==0) {
		return 0;
	}
	else{
		return 1+ resolver(n / 10);
	}
}
bool resuelveCaso() {
	long long int n;
	cin >> n;
	if (!std::cin)
		return false;

	long long int sol = resolver(n);
	cout << sol;
	cout<< endl;

	return true;

}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}