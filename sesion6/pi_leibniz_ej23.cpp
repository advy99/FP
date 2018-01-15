#include <iostream>
#include <cmath>

using namespace std;

int main(){
   int tope;
   double aproximacion_pi_cuartos = 0;
   double aproximacion_pi;
   const int TOPE_MAXIMO = 100000;
   const int TOPE_MINIMO = 0;
   bool tope_valido;
   int numerador = -1;
   const int CAMBIO_SIGNO = -1;

   do {
      cout << "Introduce el tope: ";
      cin >> tope;
      tope_valido = tope > TOPE_MINIMO && tope <= TOPE_MAXIMO;
   } while(!tope_valido);

   while(tope >= 0) {
      //Con pow seria:
      //aproximacion_pi_cuartos += pow(numerador,tope) / (2*tope + 1);
      aproximacion_pi_cuartos += numerador / (2*tope + 1);
      numerador = numerador * CAMBIO_SIGNO;
      tope--;
   }
   aproximacion_pi = aproximacion_pi_cuartos * 4;
   cout.precision(15);
   cout  << "La aproximacion de pi segun Leibniz es de " << aproximacion_pi;
}
