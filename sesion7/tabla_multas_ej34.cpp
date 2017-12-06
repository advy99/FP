#include <iostream>

using namespace std;

int main(){
   const int N_FILAS = 5;
   const int N_COLUMNAS = 10;
   const int INCREMENTO = 10;
   const int PRIMER_ELEMENTO = 31;
   int incremento_fila = 20;
   int incremento_columna = INCREMENTO;
   int elemento = PRIMER_ELEMENTO;
   int filas, columnas;

   for (filas = 1; filas <= N_FILAS; filas++){
      for (columnas = 1; columnas <= N_COLUMNAS; columnas++){
         if (columnas == 3 ){
            incremento_columna = filas * INCREMENTO;
            if (filas >=3){
               incremento_columna = columnas * INCREMENTO;
            }
         }
         else{
            incremento_columna = 10;
         }
         cout << elemento << "\t";
         elemento = elemento + incremento_columna;
      }
      cout << "\n";
      elemento = PRIMER_ELEMENTO + incremento_fila;
      incremento_fila = incremento_fila + INCREMENTO;
   }
}
