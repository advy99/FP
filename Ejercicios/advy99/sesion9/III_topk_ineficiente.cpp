//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// top_k: Calcula los k mayores valores de un vector - versión ineficiente -

/*
Se dispone de una serie de datos enteros positivos y se
quiere calcular los k mayores, ordenados de mayor a menor. Construya un programa
que vaya leyendo datos desde teclado hasta que se introduzca -1. A continuación lea
el número k y aplique el siguiente algoritmo:

Vector original: v
Vector que contendrá los k mayores valores: topk

   Copiar v en topk
   Ordenar topk de MAYOR a MENOR <-- Atención!!!
      (se recomienda modificar el algoritmo de ordenación
      por inserción)
   Seleccionar los k primeros elementos de topk

Finalmente, imprima los k primeros valores del vector topk en pantalla.

Ejemplo de entrada: 2 0 3 2 12 -1 2
-- Salida correcta: 12 3
*/

#include <iostream>
using namespace std;

int main(){
   const int TERMINADOR = -1;
   int dato;
   const int TAMANIO                 =  1e6;
   int vector[TAMANIO], topk[TAMANIO];
   int utilizados_vector, k;
   
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

   /*
   Algoritmo ineficiente:
      Copiar el vector en topk
      Ordenar topk
      Seleccionar los k primeros de topk
   */
   

   for (int i = 0; i < utilizados_vector; i++)
      topk[i] = vector[i];
   
   int izda;
   double a_insertar;

   for (izda = 1; izda < utilizados_vector; izda++){
      a_insertar = topk[izda];
      int j;
      
      for (j = izda; j > 0 && a_insertar > topk[j-1]; j--)   // Ordenación de mayor a menor
         topk[j] = topk[j-1];

      topk[j] = a_insertar;
   }
   
   for (int i = 0; i < k; i++){
      cout << topk[i] << " ";
   }
}
   


