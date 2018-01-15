//Intercambiar dos variables
#include <iostream>

using namespace std;

int main(){
	double caja_izda;
	double caja_dcha;
	double paso_intermedio;

	cout << "Introduce la cantidad de dinero en la caja de la izquierda: ";
	cin >> caja_izda;
	cout << "Introduce la cantidad de dinero en la caja de la derecha: ";
	cin >> caja_dcha;

	paso_intermedio = caja_izda;
	caja_izda = caja_dcha;
	caja_dcha = paso_intermedio;

	cout << "\nLa caja izquierda vale: " << caja_izda;
	cout << "\nLa caja derecha vale: " << caja_dcha << "\n";
}
