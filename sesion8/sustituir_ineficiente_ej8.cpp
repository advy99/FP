#include <iostream>

using namespace std;

int main(){
   const int LONGITUD_MAXIMA = 100;
   char cadena[LONGITUD_MAXIMA];
   char caracteres_sustitutos[LONGITUD_MAXIMA];
   char a_borrar;
   int tam_cadena = 0;
   int tam_cadena_sustitutos = 0;
   int i = 0;
   bool salir = false;

   cout << "Introduce caracteres para la cadena: ";
   cin >> cadena[i];
   salir = cadena[i] == '#';
   while (!salir && i != LONGITUD_MAXIMA) {
      i++;
      cin >> cadena[i];
      salir = cadena[i] == '#';
   }
   tam_cadena = i;

   i = 0;

   cout << "Introduce caracteres para la sustitucion: ";
   cin >> caracteres_sustitutos[i];
   salir = caracteres_sustitutos[i] == '#';
   while (!salir && i != LONGITUD_MAXIMA) {
      i++;
      cin >> caracteres_sustitutos[i];
      salir = caracteres_sustitutos[i] == '#';
   }
   tam_cadena_sustitutos = i;

   cout << "Introduce el caracter a sustituir: ";
   cin >> a_borrar;

   i = 0;

   while(i < tam_cadena){
      if (cadena[i] == a_borrar){
         for (int j = i; j < tam_cadena; j++) {
            cadena[j] = cadena[j+1];
         }
         tam_cadena--;
         for(int j = 0; j < tam_cadena_sustitutos; j++){
            for(int k = tam_cadena; k >= i+j; k--){
               cadena[k] = cadena[k - 1];
            }
            tam_cadena++;
            cadena[i+j]=caracteres_sustitutos[j];
         }
         i = i + tam_cadena_sustitutos - 1 ;
      }
      else{
         i++;
      }
   }

   for (i = 0; i < tam_cadena; i++) {
      cout << cadena[i] << " ";
   }
}
