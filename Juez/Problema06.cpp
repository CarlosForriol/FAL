// Nombre y apellidos del estudiante Carlos Forriol Molina
// Usuario del juez E23

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
using lli = long long int;
// Calcula un vector con los valores acumulados
void resolver(std::vector<int> const& a, std::vector<lli>& v){
	

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	lli sumatotal = 0;
	vector<lli> v;
	vector <int> a;
	// Lee las dos fechas entre las que tenemos datos
	int a1, a2;
	std::cin >> a1 >> a2;
	if (a1 == 0 && a2 == 0) return false;

	// Lee el resto de los datos y calcula el vector de acumulados
	for (int k = 0; k < a2 - a1 + 1; k++) {
		int datos;
		cin >> datos;
		a.push_back(datos);
		v.push_back(sumatotal + datos);
		sumatotal = v[k];

	}

	// Aqui código del estudiante

	// Lectura de las preguntas
	int m; std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int f1, f2;
		std::cin >> f1 >> f2;
		// Escribir la respuesta
		sumatotal = v[f2 - a1] - v[f1 - a1];
		sumatotal += a[f1 - a1];

		// Aqui codigo del estudiante
		cout << sumatotal << endl;
	}
	std::cout << "---\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	while (resuelveCaso())
		;


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
