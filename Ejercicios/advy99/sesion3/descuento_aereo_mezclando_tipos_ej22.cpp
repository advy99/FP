#include <iostream>

using namespace std;

int main(){
	double descuento_ppal;
	double descuento_second;
   double precio_billete;
   double precio_descuento_ppal;
   double precio_descuento_second;
   int porciento_descuento_ppal;
   int porciento_descuento_second;

   cout << "Introduzca el precio del billete: ";
   cin >> precio_billete;
   cout << "Introduce el descuento principal: ";
   cin >> porciento_descuento_ppal;
   cout << "Introduce el descuento secundario: ";
   cin >> porciento_descuento_second;
   
   descuento_ppal = 1.0 - porciento_descuento_ppal / 100.0;
   descuento_second = 1.0 - porciento_descuento_second / 100.0;   

   precio_descuento_ppal = precio_billete * descuento_ppal;
   precio_descuento_second = precio_billete * descuento_second;

   cout << "\nEl precio del billete total es de: " << precio_billete << " euros";
   cout << "\nCon un descuento del 4% es de: " << precio_descuento_ppal << " euros";
   cout << "\nCon un descuento del 2% es de: " << precio_descuento_second << " euros";

}
