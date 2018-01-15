#include <iostream>

using namespace std;

int main(){
   const int BASE = 150;
   const double TOPE_KILOMETROS = 300;
   const double EUROS_POR_KILOMETRO = 0.1;
   double precio_total, kilometros, kilometros_extra;

	cout << "Introduzca el número de kilometros al destino: ";
	cin >> kilometros;

	precio_total = BASE;

	if (kilometros > TOPE_KILOMETROS){
      kilometros_extra = kilometros - TOPE_KILOMETROS;
      precio_total = BASE + (kilometros_extra * EUROS_POR_KILOMETRO);
	}

	cout << "\nEl precio total del billete sera de " << precio_total << " euros\n";
}
