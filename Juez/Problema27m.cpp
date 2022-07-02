// Javier de Hoyos Pino
// E37


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int suma(int num)
{
	if (num == 0)
	{
		return 0;
	}
	else
	{
		return suma(num / 10) + num % 10;
	}
}

bool resolver(int num) {

	int aux = num % 10;

	if (num == 0)
	{
		return true;
	}
	else
	{

		if ((aux == 0 || suma(num / 10) % aux != 0))
		{
			return false;
		}
		else
		{
			return resolver(num / 10);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	int num;

	cin >> num;

	if (resolver(num) == true)
	{
		cout << "SI" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	// escribir sol


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