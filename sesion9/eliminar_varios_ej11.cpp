#include <iostream>

using namespace std;

int main(){
   const int TAM_MAXIMO = 100;
   int elementos[TAM_MAXIMO];
   int a_borrar[TAM_MAXIMO];
   int numero_elementos;
   int numero_a_borrar;
   int intercambiar;
   int pos_lectura, pos_escritura;
   int contador_borrar = 0;

   cout << "Introduce el número de elementos a introducir: ";
   cin >> numero_elementos;
   cout << "Introduce los elementos: ";

   for(int i = 0; i < numero_elementos; i++){
      cin >> elementos[i];
   }

   cout << "Introduce el número de posiciones a borrar: ";
   cin >> numero_a_borrar;
   cout << "Introduce las posiciones a borrar: ";

   for(int i = 0; i < numero_a_borrar; i++){
      cin >> a_borrar[i];
   }
   for(int i = 0;i < numero_a_borrar;i++){
      for(int j = numero_a_borrar - 1;j > i; j--){
         if (a_borrar[j] < a_borrar[j-1]){
            intercambiar = a_borrar[j];
            a_borrar[j] = a_borrar[j-1];
            a_borrar[j-1] = intercambiar;
         }
      }
   }

   pos_lectura = 0;
   pos_escritura = 0;

   while(pos_lectura < numero_elementos){
      if(pos_lectura != a_borrar[contador_borrar]){
         elementos[pos_escritura] = elementos[pos_lectura];
         pos_escritura++;
      }
      else{
         contador_borrar++;
      }
      pos_lectura++;
   }
   numero_elementos = numero_elementos - numero_a_borrar;
   for(int i = 0; i < numero_elementos;i++){
      cout << elementos[i] << " ";
   }
}
