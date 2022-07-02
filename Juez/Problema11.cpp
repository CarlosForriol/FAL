//Carlos Forriol Molina
// E23
//problema 11
#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
struct tIntervalo {
	int ini;
	int fin;
};
tIntervalo resolver(const vector<int>& v, int t) {
	tIntervalo sol={0, 0};
	int a = 0, l = -1;

	for (int m = 0; m < v.size();++m) {
		if (v[m]> t) {
			a = m;
			while (m < v.size() && v[m]> t) {
				if (m - a > l) {
					l = m - a;
					sol = { a,m };
				}
				m++;
			}
			
		}
	}
	return sol;
}
void resuelveCaso() {
	int n, t;
	cin >> n >> t;
	vector<int> v(n); for (int pos = 0; pos < n; pos++) cin >> v[pos];

	tIntervalo sol = resolver(v, t);
	cout << sol.ini << " " << sol.fin << endl;
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
	for (int i = 0; i < numCasos; ++i) resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}