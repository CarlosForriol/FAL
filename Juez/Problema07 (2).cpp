// Nombre del alumno Carlos Forriol Molina
// Usuario del Juez E23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> resolver(const vector<int> & v1, vector<int>& v2) {
	int i = 0;
	int j = 0;
	vector<int> solucion;

	while (i < v1.size() && j < v2.size()) {
		if (v1[i] == v2[j]) {
			solucion.push_back(v2[j]);
			++j;
			i++;
		}
		else if (v1[i] < v2[j]) {
			++i;
		}
		else if (v1[i] > v2[j]) {
			j++;
		}
		
	}
	return solucion;
}

void resuelveCaso() {
	int dato = 0;
	vector<int> solucion;
	vector<int> v1;
	vector<int> v2;
	
	cin >> dato;
	while (dato != 0) {
		v1.push_back(dato);
		cin >> dato;
	}
	dato = -1;
	cin >> dato;
	while (dato != 0) {
		v2.push_back(dato);
		cin >> dato;
	}
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());
	solucion  = resolver(v1, v2);
	for (int i = 0; i < solucion.size(); i++)
	{
		cout << solucion[i] << " ";
	}
	cout << endl;
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