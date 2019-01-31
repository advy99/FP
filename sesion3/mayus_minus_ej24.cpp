#include <iostream>

using namespace std;

int main(){
   const char A_MAYUS = 'A';
   const char A_MINUS = 'a';
   const int DIFERENCIA_MINU_MAYUS = A_MINUS - A_MAYUS;
   char caracter, caracter_minus;

   cout << "Introduce un caracter: ";
   cin >> caracter;

   caracter_minus = caracter + DIFERENCIA_MINU_MAYUS;

   cout << caracter << " en minuscula es " << caracter_minus;
}
