//Carlos Forriol Molina
//E23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// función que resuelve el problema
int resolver(int n, int finsuma, int insuma) { //suma ini es la suma inicial de los digitos totales
	if (n < 10) { //caso base 
		if (n == 0) {
			return 0;
		}
		else {
			if (finsuma % n == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}

	}

	else {

		int r = n % 10;
		if (r == 0) {
			return 0;
		}
		else {
			if (((insuma - r) % r == 0) && (finsuma % r == 0)) {
				return resolver(n / 10, finsuma + r, insuma - r);
			}
			else {
				return 0;
			}
		}
	}
}

int sumDigitos(int num, int sum) {

	if (num < 10) {
		return sum + num;
	}
	else {
		return sumDigitos(num / 10, sum + num % 10);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;

	int insuma = 0;
	int reves = 0;
	int finsuma = 0;
	insuma = sumDigitos(n, insuma);
	int sol = resolver(n, finsuma, insuma);
	// escribir sol
	if (sol == 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "SI" << endl;
	}


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
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
