//Nombre Carlos Forriol Molina
//Usuario E23
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int inversion(int n,int pot) {
	if (n < 10 && pot ==0) {
		return 9 - n;
	}
	else if (n == 0) {
		return pot;
	}
	else {
		return inversion(n / 10, pot * 10 + (9 - (n % 10)));
	}
}
int complementario(int n) {
	if (n / 10 == 0) {
		return 9 - n;
	}
	else {
		return complementario(n / 10) * 10 + (9 - (n % 10));
	}
}

void resuelveCaso() {
	int n;
	std::cin >> n;
	int comp = complementario(n);
	int inv = inversion(n, 0);

	std::cout << comp << " " << inv << "\n";

}

int main() {
	
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
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