//Tarifa a�rea seg�n km

#include <iostream>

using namespace std;

int main(){
	const double BASE = 150;
	const double TARIFA_POR_KILOMETRO = 0.1;
	double kilometros;
	double precio_total;

	cout << "Introduzca el n�mero de kilometros al destino: ";
	cin >> kilometros;

	precio_total = BASE + (kilometros * TARIFA_POR_KILOMETRO);

	cout << "El precio total del billete sera de " << precio_total << " euros\n";
}
