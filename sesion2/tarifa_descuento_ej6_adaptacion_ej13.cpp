//Calcular tarifa aerea con un 4 y un 2% de descuento

#include <iostream>

using namespace std;

int main(){
	const double DESCUENTO_PPAL = 1.0 - 4.0 / 100.0;
	const double DESCUENTO_SECOND = 1.0 - 2.0 / 100.0;
   double precio_billete;
   double precio_descuento2;
   double precio_descuento4;

   cout << "Introduzca el precio del billete: ";
   cin >> precio_billete;

   precio_descuento4 = precio_billete * DESCUENTO_PPAL;
   precio_descuento2 = precio_billete * DESCUENTO_SECOND;

   cout << "El precio del billete total es de: " << precio_billete << " euros";
   cout << "\nCon un descuento del 4% es de: " << precio_descuento4 << " euros";
   cout << "\nCon un descuento del 2% es de: " << precio_descuento2 << " euros";

}
