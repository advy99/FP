//Cálculo del interes bancario

#include <iostream>

using namespace std;

int main(){
   double capital;
   double interes;
   double total;

   cout << "Introduce el capital que desea invertir: ";
   cin >> capital;
   cout << "Introduce el interes (valor entre 0 y 100, representando un porcentaje): ";
   cin >> interes;

   total = capital + capital*interes/100;

   cout << "\nAl cabo de un año el capital total sera de " << total << " debido a los intereses";

   /*
   Respuesta a la pregunta sobre si es posible realizarlo de la siguiente manera:
      capital = capital + capital * interes / 100;

   Se podria realizar de esta manera, sin embargo, esto conllevaría ciertas ventajas e inconvenientes:

   Ventajas:
      -Ahorramos una dirección de memoria, al no usar la variable "total"
   Desventajas:
      -Perdemos el dato original del capital, ya que se veria sobreescribido por el capital con el interes

   */
}
