//Carlos Forriol Molina
// E23
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



struct tDatos {
	int maxLongitud=0;
	int Numencontrados=0;
	vector <int> pos;
};
tDatos resolver(const vector <int>& v,int l){
	tDatos sol; sol.maxLongitud = 0, sol.Numencontrados = 0;
	int max = -1,r=1;
	
	for (int pos = v.size() - 1; pos >= 1; pos--) {

		while (pos >=1 && v[pos] > max  && v[pos] == v[pos -1]) {
			r++;
			pos--;
		}
		if (r >= 1) {
			if (sol.maxLongitud < r) sol.maxLongitud = r;
			sol.Numencontrados++;
			sol.pos.push_back(pos + r - 1);
		}
		if (max < v[pos]) {
			max = v[pos];
			r = 1;
		}
	}
	return sol;
}
bool resuelveCaso() {
	int n; cin >> n;
	if (!cin) return false;
	int l; cin >> l;
	vector <int> v(n); for (int pos = 0; pos < n; pos++) cin >> v[pos];
	tDatos sol = resolver(v, l);

	cout << sol.maxLongitud << " " << sol.Numencontrados << " ";
	for (int pos = 0; pos < sol.pos.size(); pos++) cout << sol.pos[pos] << " ";
	cout << endl;

	return true;
}
int main() {
	
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