#include <iostream>
#include <cmath>

using namespace std;

int main(){
   const double UNO_ENTRE_RAIZ_TRES = 1.0 / sqrt(3);
   const int TOPE_MAXIMO = 100000;
   const int TOPE_MINIMO = 0;
   const int CAMBIO_SIGNO = -1;
   int tope, tope_inicial;
   double aproximacion_pi_sextos = 0;
   double aproximacion_pi;
   bool tope_valido;
   int multiplo_numerador = -1 ;
   int tope_por_dos_mas_uno;
   double potencia_numerador = 1.0;
   int contador_potencia_numerador = 1;

   do {
      cout << "Introduce el tope: ";
      cin >> tope_inicial;
      tope_valido = tope_inicial > TOPE_MINIMO && tope_inicial <= TOPE_MAXIMO;
   } while(!tope_valido);

   tope = 0;

   while (tope < tope_inicial){
      tope_por_dos_mas_uno = tope * 2 + 1;
      multiplo_numerador = multiplo_numerador * CAMBIO_SIGNO;

      while (contador_potencia_numerador <= tope_por_dos_mas_uno){
         potencia_numerador = potencia_numerador * UNO_ENTRE_RAIZ_TRES;
         contador_potencia_numerador++;
      }
      aproximacion_pi_sextos += multiplo_numerador * potencia_numerador / tope_por_dos_mas_uno;
      tope++;
   }
   cout.precision(15);
   aproximacion_pi = aproximacion_pi_sextos * 6;
   cout << "La aproximacion de pi es: " << aproximacion_pi;
}
