#include <iostream>

using namespace std;

int main(){
   const int LONGITUD_MAXIMA = 2500000;
   char cadena[LONGITUD_MAXIMA];
   char caracteres_sustitutos[LONGITUD_MAXIMA];
   char a_borrar;
   int pos_eliminar[LONGITUD_MAXIMA];
   long int tam_cadena = 0;
   int tam_cadena_sustitutos = 0;
   int elemento_borrar = 0;
   int fin_inicial = 0;
   int i = 0;
   bool salir = false;

   cout << "Introduce caracteres para la cadena: ";
   cadena[i] = cin.get();
   salir = cadena[i] == '#';
   while (!salir && i != LONGITUD_MAXIMA) {
      i++;
      cadena[i] = cin.get();
      salir = cadena[i] == '#';
   }
   tam_cadena = i;
   fin_inicial = tam_cadena - 1;
   i = 0;

   cout << "Introduce caracteres para la sustitucion: ";
   caracteres_sustitutos[i] = cin.get();
   salir = caracteres_sustitutos[i] == '#';
   while (!salir && i != LONGITUD_MAXIMA) {
      i++;
      caracteres_sustitutos[i] = cin.get();
      salir = caracteres_sustitutos[i] == '#';
   }
   tam_cadena_sustitutos = i;

   cout << "Introduce el caracter a sustituir: ";
   a_borrar = cin.get();

   i = 0;

   for (int i = 0; i < tam_cadena; i++){
      if(cadena[i] == a_borrar){
         elemento_borrar++;
      }
   }
   tam_cadena = (elemento_borrar * tam_cadena_sustitutos) + tam_cadena - elemento_borrar;
   i = tam_cadena  - 1;

   while( i >= 0 ){
      if(cadena[fin_inicial] != a_borrar){
         cadena[i] = cadena[fin_inicial];
         i--;
         fin_inicial--;
      }
      else{
         for(int k = tam_cadena_sustitutos - 1 ; k >=0; k--){
            cadena[i] = caracteres_sustitutos[k];
            i--;
         }
         fin_inicial--;
      }
   }

   for (int i = 0; i < tam_cadena; i++){
      cout << cadena[i];
   }

}
