#include <iostream>
#include <cmath>

using namespace std;

int main(){
   const double PI = 6 * asin(0.5);
   double esperanza;
   double desviacion_tipica;
   double valor_abcisa;
   double base_gaussiana;
   double exponente_gaussiana;
   double diferencia_abcisa_esperanza_cuadrado;
   double gaussiana;
   double minimo, maximo, incremento;
   double minimo_incrementado;
   int contador_incremento = 0;
   bool minimo_supera_maximo;

   cout << "Introduzca el valor de la esperanza: ";
   cin >> esperanza;

   do{
      cout << "Introduzca el valor de la desviacion tipica: ";
      cin >> desviacion_tipica;
   }while (desviacion_tipica < 0);

   cout << "Introduzca el mínimo: ";
   cin >> minimo;

   do{
      cout << "Introduzca el máximo: ";
      cin >> maximo;
   }while (maximo <= minimo);

   do{
      cout << "Introduzca el valor del incremento: ";
      cin >> incremento;
   }while (incremento < 0);

   base_gaussiana = 1.0 / ( desviacion_tipica * sqrt(2*PI) );

   do{
      valor_abcisa = minimo + contador_incremento * incremento;
      diferencia_abcisa_esperanza_cuadrado = pow ( (valor_abcisa - esperanza) / desviacion_tipica, 2);
      exponente_gaussiana = -0.5 * diferencia_abcisa_esperanza_cuadrado;
      gaussiana = base_gaussiana * exp(exponente_gaussiana);

      cout << "\nLa ecuacion gaussiana en el punto " << valor_abcisa << " vale " << gaussiana;
      contador_incremento++;
      minimo_supera_maximo = valor_abcisa < maximo;
   }while (minimo_supera_maximo);
}
