// Carlos forriol Molina
// E23


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tDat {
	vector<int> tvector;
	int fin;
	int ini;
};

istream& operator>> (std::istream& in, tDat& dat) {
	int n;
	in >> dat.ini >> dat.fin;
	for (int i = 0; i < dat.fin - dat.ini + 1; i++) {
		in >> n;
		dat.tvector.push_back(n);
	}
	return in;
}


vector<int> resolver(tDat dat) {
	vector<int> sol;
	int min = dat.tvector[0];
	for (int i = 0; i < dat.tvector.size(); i++) {
		if (min < dat.tvector[i]) {
			min = dat.tvector[i];
			sol.push_back(i + dat.ini);
		}
	}
	return sol;
}

void resuelveCaso() {
	vector<int> sol;
	tDat dat;

	cin >> dat; // leer los datos de la entrada

	sol = resolver(dat);

	//cout << solucion
	// escribir sol

	for (int i = 0; i < sol.size(); i++)
	{
		cout << sol[i] << " ";
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