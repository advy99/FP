//Redondear un número al decimal indicado

#include <iostream>
#include <cmath>

using namespace std;

int main(){
   double numero;
   double decimal_redondeo;
   double numero_redondeado;

   cout << "Introduce el número a redondear: ";
   cin >> numero;
   cout << "Introduce a que decimal redondear el número: ";
   cin >> decimal_redondeo;

   numero_redondeado = round(numero*pow(10,decimal_redondeo))/pow(10,decimal_redondeo);

   cout << "\n" << numero << " redondeado al " << decimal_redondeo << " decimal es " << numero_redondeado;
}
