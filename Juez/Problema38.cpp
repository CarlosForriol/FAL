// Carlos Forriol Molina
//E23

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

/* El coste de la funcion es:

	T(n) = {
			T(1) = 1;
			T(n) = 2T(n/2) + 1;
	}

	--> Tras resolver la recurrencia obtenemos un coste de O(n),
	siendo n el numero de elementos del vector;
*/
 struct tdatos{
	bool jugador; // True --> jugador se presento, False --> no se presento;
	int numJuegos; // Numero de juegos acumulados;
};
tdatos resolver(std::vector<std::string> const& partidos, int ini, int fin, int rondaLim, int& rondaAct) {
	if (ini + 1 == fin) { // Cuando tenemos 2 jugadores ---> O(1);
		rondaAct = 1;
		if ((partidos[ini] != "NP") && (partidos[fin] != "NP")) return { true, 1 };
		else if ((partidos[ini] != "NP") || (partidos[fin] != "NP")) return { true, 0 }; // Si solo se presento un jugador;
		else return { false, 0 };//Ninguno
	}
	else { // Cuando hay mas de 2 jugadores;
		int m = (ini + fin) / 2;
		tdatos izq = resolver(partidos, ini, m, rondaLim, rondaAct); // ---> O(log n);
		tdatos der = resolver(partidos, m + 1, fin, rondaLim, rondaAct); // ---> O(log n);

		if ((rondaLim > rondaAct) && izq.jugador && der.jugador) {
			++rondaAct;
			return { true, (izq.numJuegos + der.numJuegos + 1) };
		}
		else if (izq.jugador || der.jugador) {
			++rondaAct;
			return { true, (izq.numJuegos + der.numJuegos) };
		}
		else {
			++rondaAct;
			return { false, (izq.numJuegos + der.numJuegos) };
		}
	
	
	}
}

bool resuelveCaso() {
	int tam;
	std::cin >> tam;
	if (!std::cin) return false;

	int rondaLim;
	std::cin >> rondaLim;

	std::vector<std::string> partidos(tam);

	for (std::string& jugador : partidos)
		std::cin >> jugador;

	int rondaAct;

	tdatos sol = resolver(partidos, 0, tam - 1, rondaLim, rondaAct);

	// Escribir sol:
	std::cout << sol.numJuegos << "\n";

	return true;
}




int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt
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