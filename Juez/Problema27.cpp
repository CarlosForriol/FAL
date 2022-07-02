// Nombre: Alejandro Gonzalez Escalona 
// Usuario: A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// función que resuelve el problema
int recursion(int n, int sumafin, int sumaini) { //suma ini es la suma inicial de los digitos totales
	if (n < 10) { //caso base 
		if (n == 0) {
			return 0;
		}
		else {
			if (sumafin % n == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}

	}

	else {
		
		int resto = n % 10;
		if (resto == 0) {
			return 0;
		}
		else {
			if (((sumaini - resto) % resto == 0) && (sumafin % resto == 0)) {
				return recursion(n / 10 , sumafin + resto, sumaini - resto);
			}
			else {
				return 0 ;
			}

		}
	

	}

}

int sumaDigitos(int num, int suma) {

	if (num < 10) {
		return suma + num;
	}
	else {
		return sumaDigitos(num / 10, suma + num % 10);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;

	int sumaini = 0;
	int reves = 0;
	int sumafin = 0;
	sumaini = sumaDigitos(n, sumaini);
	int sol = recursion(n, sumafin, sumaini );
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



/*	if (n < 10) {
		if (suma % n == 0) {
			return n ;
		}
		else {
			return 0;
		
		}
	}
	
	else {
		int resto = n % 10;
		if (resto == 0) {
			return 0;
		}
		else {
			if (suma % resto == 0) {
				int inverso = recursion(n / 10, suma + resto, reves);
				if (inverso == 0) {
					return 0;
				}
				else {
					if (reves % inverso == 0) {

						return inverso + reves;
					}
					else {
						return 0;
					}
				}
			
			}
			else {
				return 0;
			}
		}
		
		
	}*/