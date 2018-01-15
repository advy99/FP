//Calcular tarifa aerea con un 4 y un 2% de descuento

#include <iostream>

using namespace std;

int main(){
   double precio_billete;
   double precio_descuento2;
   double precio_descuento4;

   cout << "Introduzca el precio del billete: ";
   cin >> precio_billete;

   precio_descuento4 = precio_billete - (precio_billete * 0.04);
   precio_descuento2 = precio_billete - (precio_billete * 0.02);

   cout << "El precio del billete total es de: " << precio_billete << " euros";
   cout << "\nCon un descuento del 4% es de: " << precio_descuento4 << " euros";
   cout << "\nCon un descuento del 2% es de: " << precio_descuento2 << " euros";

}
