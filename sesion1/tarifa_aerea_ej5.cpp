//Tarifa a�rea seg�n km

#include <iostream>

using namespace std;

int main(){
	double base;
	double kilometros;
	double precio_total;
	
	cout << "Introduzca el n�mero de kilometros al destino: ";
	cin >> kilometros;
	
	base = 150;
	precio_total = base + (kilometros * 0.1);
	
	cout << "El precio total del billete sera de " << precio_total << " euros\n";
}
