#include <iostream>
#include <cmath>

using namespace std;

int main(){
   int real_truncado_pow, cifra_truncar;
   double real, copia_real, potencia_cifra_truncar;

   cout << "Introduzca un numero: ";
   cin >> real;
   cout << "Introduzca a que cifra truncarlo: ";
   cin >> cifra_truncar;

   potencia_cifra_truncar = pow(10,cifra_truncar);
   copia_real = real * potencia_cifra_truncar;
   real_truncado_pow = copia_real;
   copia_real = real_truncado_pow / potencia_cifra_truncar;

   cout << "\n" << real <<" truncado al decimal " << cifra_truncar << " es " << copia_real;
}
