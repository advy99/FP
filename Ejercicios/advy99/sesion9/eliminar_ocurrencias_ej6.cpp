#include <iostream>

using namespace std;

int main(){
   const int MAXIMO = 2500000;
   const char PARAR_LECTURA = '#';
   char cadena[MAXIMO];
   char a_borrar;
   int pos_lectura, pos_escritura, util_cadena = 0;
   int i = 0;
   bool salir;

   cout << "Introduce el texto: ";
   cadena[0] = cin.get();
   salir = cadena[0] == PARAR_LECTURA;

   while(!salir){
      i++;
      cadena[i] = cin.get();
      salir = cadena[i] == PARAR_LECTURA;
   }
   util_cadena = i;

   a_borrar = cin.get();

   pos_lectura = 0;
   pos_escritura = 0;

   while (pos_lectura < util_cadena){
      if (cadena[pos_lectura] != a_borrar){
         cadena[pos_escritura] = cadena[pos_lectura];
         pos_escritura++;
      }
      pos_lectura++;
   }
   util_cadena = util_cadena - (pos_lectura - pos_escritura);

   for(int i = 0; i < util_cadena; i++){
      cout << cadena[i];
   }
}
