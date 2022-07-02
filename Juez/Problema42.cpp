//Carlos Forriol Molina
//E23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*El coste de la funcion en el caso peor va  a ser O(n) -->lineal 
 respecto al numero de elementos del vector,
  numero caucasico tenemos un coste O(n), 
 lineal, pero en los demas casos siempre descartaremos alguna mitad. 
 */
bool resolver(std::vector<int> const& v, int ini, int fin, int& cont) {
	if (ini >=fin) {//1 elemento
		cont = 0;
		return true;
	}
	else if (ini + 1 == fin) {// 2 numeros
		if ((v[ini] % 2 == 0) && (v[fin] % 2 == 0))cont = 2;// 2 pares
		else if ((v[ini] % 2 == 0) || (v[fin] % 2 == 0))cont = 1;// 1 par
		else cont = 0;//ninguno
		return true;
	}
	else {
		int m = (ini + fin) / 2;
		int izq, der;

		if (resolver(v, ini, m, izq)) { // izquierdo
			if (resolver(v, m + 1, fin, der)) { // derecho
				if (abs(izq - der) <= 2) { // resta sea <= 2
					cont = izq + der;
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
}
bool resuelveCaso() {
	int num;
	std::cin >> num;

	if (num == 0) return false;

	std::vector<int> v(num);

	for (int i = 0; i < num; ++i)
		std::cin >> v[i];
// escribir sol
	int cont = 0;
	if (resolver(v, 0, num - 1, cont)) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
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