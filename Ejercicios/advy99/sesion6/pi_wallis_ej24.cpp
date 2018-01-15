#include <iostream>

using namespace std;

int main(){
   int tope;
   double aproximacion_pi_medios = 1.0;
   double aproximacion_pi;
   const int TOPE_MAXIMO = 100000;
   const int TOPE_MINIMO = 0;
   bool tope_valido;
   int numerador_calculo = 2;
   int denominador_calculo = 1;
   const int DIFERENCIA_PROXIMO = 2;
   bool cambiar_denominador = true;

   do {
      cout << "Introduce el tope: ";
      cin >> tope;
      tope_valido = tope > TOPE_MINIMO && tope <= TOPE_MAXIMO;
   } while(!tope_valido);

   while (tope > 0){
      aproximacion_pi_medios = aproximacion_pi_medios * numerador_calculo / denominador_calculo;
      if (cambiar_denominador){
         denominador_calculo = denominador_calculo + DIFERENCIA_PROXIMO;
         cambiar_denominador = false;
      }
      else{
         numerador_calculo = numerador_calculo + DIFERENCIA_PROXIMO;
         cambiar_denominador = true;
      }
      tope--;
   }
   cout.precision(15);
   aproximacion_pi = aproximacion_pi_medios * 2;
   cout << "La aproximacion de pi es: " << aproximacion_pi;
}
