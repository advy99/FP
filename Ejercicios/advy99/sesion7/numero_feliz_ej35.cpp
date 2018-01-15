#include <iostream>
#include <cmath>

using namespace std;

int main(){
   int numero;
   int grado_comprobar;
   int copia_numero;
   int grado_actual;
   int n_cifras;
   int suma_cuadrados;
   int ultima_cifra_copia;
   bool es_n_feliz = false;

   cout << "Introduce un numero: ";
   cin >> numero;
   cout << "Introduce el grado hasta el cual se intentara: ";
   cin >> grado_comprobar;

   grado_actual = 0;
   /*La primera vez necesitamos el numero, pero las siguientes necesitamos la suma anterior
    y vaciar esta misma suma, desglosamos el numero y calculamos la suma del cuadrado de
    cifrasd
   */
   suma_cuadrados = numero;

   while ( grado_actual < grado_comprobar && !es_n_feliz) {
      copia_numero = suma_cuadrados;
      suma_cuadrados = 0;
      n_cifras = 0;
      while (copia_numero > 0){
         ultima_cifra_copia = copia_numero % 10;
         suma_cuadrados = suma_cuadrados + pow(ultima_cifra_copia, 2 );
         copia_numero = copia_numero / 10;
         n_cifras++;
      }
      es_n_feliz = suma_cuadrados == 1;
      grado_actual++;
   }

   if(es_n_feliz){
      cout << "\nEs feliz para grados >= " << grado_actual;
   }
   else
      cout << "\nNo es feliz para grados <= " << grado_actual;
}
