//Mover entero en un intervalo dado
#include <iostream>

using namespace std;

int main(){
   int minimo, maximo, a_desplazar, desplazamiento;
   int n_posicion_modulo;
   int tam_intervalo;
   int pos_intervalo;
   int n_final;

   cout << "Introduce el minimo del intervalo: ";
   cin >> minimo;
   cout << "Introduce el maximo del intervalo: ";
   cin >> maximo;
   cout << "Introduce el numero de casillas que desplazarlo: ";
   cin >> desplazamiento;
   cout << "Introduce el numero con el que empezar: ";
   cin >> a_desplazar;

   /*Sumamos uno ya que la diferencia de extremos nos elimina el primer
   elemento, por ejemplo, el intervalo :
      [3,5]:
   Sacaria como tamaño 2:
      5 - 3 = 2
   Sin embargo contiene tres elementos:
      3, 4, 5
   */
   tam_intervalo = maximo - minimo + 1;

   //Posicion del elemento dentro del intervalo
   pos_intervalo = a_desplazar - minimo;
   //El resto de la division de la posicion final en el intervalo (la posicion en el intervalo mas el numero a desplazar)
   //con el tamaño del intervalo nos da la nueva posicion contando desde el principio
   n_posicion_modulo = (desplazamiento + pos_intervalo) % tam_intervalo;
   n_final = minimo + n_posicion_modulo;

   cout << "\nLa nueva posicion al desplazarlo es: " << n_final << "\n";
}
