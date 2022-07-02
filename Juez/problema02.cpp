// Carlos Forriol Molina
// E23



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tDatos{
	int p;
	vector<int> tvector;
	int contador = 0;
	
};


istream& operator>> (std::istream& in, tDatos& dato){

	int num;
	in >> dato.contador >> dato.p;

	for (int i = 0; i < dato.contador; i++) {

		in >> num;
		dato.tvector.push_back(num);
	}
	return in;
}

// función que resuelve el problema
bool Resolver(const tDatos& dato) {

	int minimo, maximo = dato.tvector[0];
	bool caso;

	if (dato.p + 1 == dato.contador){
	
		caso = true;
	}
	else{
	
		minimo = dato.tvector[dato.p + 1];
		if (dato.p == 0){
		
			maximo = dato.tvector[dato.p];
			for (int i = dato.p + 1; i < dato.contador; i++){
			
				if (dato.tvector[i] < minimo){
				
					minimo = dato.tvector[i];
				}
			}
		}
		else{
		
			for (int i = 0; i < dato.contador; i++){
			
				if (i <= dato.p){
				

					if (dato.tvector[i] > maximo){
					
						maximo = dato.tvector[i];
					}
				}
				else if (dato.tvector[i] < minimo){
					minimo = dato.tvector[i];
					
				}
			}
		}

		if (maximo < minimo){
		
			caso = true;
		}
		else{
		
			caso = false;
		}

	}

	return caso;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	tDatos dato;
	bool caso;
	// leer los datos de la entrada
	cin >> dato;
	// escribir sol
	caso = Resolver(dato);
	if (caso == true){
	
		cout << "SI" << endl;
	}
	else{
	
		cout << "NO" << endl;
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