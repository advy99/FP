#include <iostream>

using namespace std;

int main(){
   int numero;
   int izquierda, derecha;
   int decimal_separar = 10;
   int suma, suma_cuadrado;
   const int aniadir_decimal = 10;
   bool es_desgarrable = false;
   
   cout << "Introduce un número: ";
   cin >> numero;

   while (decimal_separar < numero && !es_desgarrable ){
      izquierda = numero / decimal_separar;
      derecha = numero % decimal_separar;
      suma = izquierda + derecha;
      suma_cuadrado = suma * suma;
      decimal_separar = decimal_separar * aniadir_decimal;

      if (suma_cuadrado == numero)
         es_desgarrable = true;
   }

   if (es_desgarrable)
      cout << "\nEl número " << numero << " es desgarrable";
   else
      cout << "\nEl número " << numero << " no es desgarrable";
}
