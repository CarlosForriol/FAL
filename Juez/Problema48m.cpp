//Carlos Forriol Molina
//E23
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct tDatos {
	std::vector <int > tipAbrigos;
	std::vector <int > probPrecip;
};
bool esvalida(int k, int i, tDatos const& d, std::vector <int > const& sol,std::vector <int > const& marcas) {
	if (d.tipAbrigos[i] < d.probPrecip[k]) return false;
	if (k > 0 && sol[k] == sol[k - 1]) return false;
	if (marcas[i] > k / 3 + 2) return false;
	return true;
}


int abrigos(tDatos const& d, int k, std::vector <int >& sol, std::vector <int >& marcas) { //D= datos entrada, K etapa,sol abrigo q me pondre ,marcas dias q me he puesto abrigo
	int numSol = 0;
	for (int i = 0; i < d.tipAbrigos.size(); ++i) {
		sol[k] = i;
		// marcar
		++marcas[i];
		if (esvalida(k, i, d, sol, marcas)) {//SI es valida
			if (k = d.probPrecip.size() - 1) {
				if (sol[0] != sol[k]) {
					++numSol;
				}
			}
			else {
				numSol += abrigos(d, k + 1, sol, marcas);
			}
		}


		--marcas[i];
	}
	return numSol;
}

bool resuelveCaso() {	// leer los datos de la entrada
	int numDias, numAbrigos;
	std::cin >> numDias;
	if (numDias == 0) return false;
	std::cin >> numAbrigos;
	// leer probabilidad de precipitacion
	tDatos d;
	d.probPrecip.resize(numDias);
	for (int& i : d.probPrecip) std::cin >> i;
	// leer caracteristicas de los abrigos
	d.tipAbrigos.resize(numAbrigos);
	for (int& i : d.tipAbrigos) std::cin >> i;
	// Declaracion de tipos para llamar a la funcion
	int k = 0;
	std::vector <int > sol(numDias);
	std::vector <int > marcas(numAbrigos);
	int numSoluciones = abrigos(d, k, sol, marcas);
	// Escribir resultado
	if (numSoluciones == 0) std::cout << "Lo puedes comprar \n";
	else std::cout << numSoluciones << '\n';
	return true;}

int main() {
# ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos . txt
# endif
	while (resuelveCaso()) {} // Resolvemos todos los casos
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}