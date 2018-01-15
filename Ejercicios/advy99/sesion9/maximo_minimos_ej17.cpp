#include <iostream>

using namespace std;

int main(){
   const int TAM_MAX = 100;
   double matriz[TAM_MAX][TAM_MAX];
   double minimos_por_fila[TAM_MAX];
   double maximo_entre_minimos;
   int num_filas;
   int num_columnas;
   int fila_max, columna_max;

   cout << "Introduce el numero de filas: ";
   cin >> num_filas;
   cout << "Introduce el numero de columnas: ";
   cin >> num_columnas;

   for (int i = 0; i < num_filas; i++){
      cout << "Introduce los elementos de la fila " << i + 1 << ": ";
      for (int j = 0; j < num_columnas; j++){
         cin >> matriz[i][j];
      }
   }
   for (int i = 0; i < num_filas; i++){
      minimos_por_fila[i] = matriz[i][0];
      for (int j = 0; j < num_columnas; j++){
         if (matriz[i][j] < minimos_por_fila[i]){
            minimos_por_fila[i] = matriz[i][j];
         }
      }
   }

   maximo_entre_minimos = minimos_por_fila [0];
   fila_max = 0;
   for (int j = 0; j < num_columnas;j++){
      if (maximo_entre_minimos == matriz[0][j])
         columna_max = j;
   }

   for (int i = 0; i < num_filas; i++){
      if (minimos_por_fila[i] > maximo_entre_minimos){
         maximo_entre_minimos = minimos_por_fila[i];
         fila_max = i;
         for (int j = 0; j < num_columnas;j++){
            if (maximo_entre_minimos == matriz[i][j])
               columna_max = j;
         }
      }
   }

   for (int i = 0; i < num_filas; i++){
      cout << "El minimo de la fila " << i << " es " << minimos_por_fila[i] << "\n";
   }
   cout << "El mayor de estos minimos es " << maximo_entre_minimos << " y esta en la posicion " << fila_max << ","<< columna_max ;
}
