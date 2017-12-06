#include <iostream>
using namespace std;

int main(){
   const int TERMINADOR = -1;
   int dato;
   const int TAMANIO                 =  1e6;
   int vector[TAMANIO], topk[TAMANIO];
   int utilizados_vector, k;
   int intercambio;

   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:


   cout << "Topk.\n\n"
        << "Introduzca enteros con terminador "
        << TERMINADOR << "\n"
        << "Luego introduzca el valor de k.\n\n";

   utilizados_vector = 0;
   cin >> dato;

   while (dato != TERMINADOR && utilizados_vector < TAMANIO){
      vector[utilizados_vector] = dato;
      utilizados_vector++;
      cin >> dato;
   }

   cin >> k;

   for (int i = 0; i < utilizados_vector; i++)
      topk[i] = vector[i];

   int izda;
   int a_insertar;

   for (izda = 1; izda < k; izda++){
      a_insertar = topk[izda];
      int j;

      for (j = izda; j > 0 && a_insertar > topk[j-1]; j--)
         topk[j] = topk[j-1];

      topk[j] = a_insertar;
   }

   for (a_insertar = k; a_insertar < utilizados_vector;a_insertar++){
      for (izda = 0;izda < k; izda++){
         if (topk[a_insertar] > topk[izda]){
            intercambio = topk[izda];
            topk[izda] = topk[a_insertar];
            topk[a_insertar] = intercambio;
         }
      }
   }

   for (int i = 0; i < k; i++){
      cout << topk[i] << " ";
   }
}
