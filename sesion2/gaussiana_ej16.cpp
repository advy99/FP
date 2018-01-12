#include <iostream>
#include <cmath>
//2018
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

   cout << "Introduzca el valor de la esperanza: ";
   cin >> esperanza;
   cout << "Introduzca el valor de la desviacion tipica: ";
   cin >> desviacion_tipica;
   cout << "Introduzca el valor de la abcisa donde calcular la gaussiana: ";
   cin >> valor_abcisa;

   base_gaussiana = 1.0 / ( desviacion_tipica * sqrt(2*PI) );
   diferencia_abcisa_esperanza_cuadrado = pow ( (valor_abcisa - esperanza) / desviacion_tipica, 2);
   exponente_gaussiana = -0.5 * diferencia_abcisa_esperanza_cuadrado;
   gaussiana = base_gaussiana * exp(exponente_gaussiana);

   cout << "\nLa ecuacion gaussiana en el punto " << valor_abcisa << " vale " << gaussiana;
}
