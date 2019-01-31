#include <iostream>

using namespace std;

int main(){
   const int LONGITUD_MAXIMA = 100;
   char cadena[LONGITUD_MAXIMA];
   char sustituido[LONGITUD_MAXIMA];
   char caracteres_sustitutos[LONGITUD_MAXIMA];
   char a_borrar;
   int tam_cadena = 0;
   int tam_cadena_sustitutos = 0;
   int tam_util_sustituido = 0;
   int n_apariciones = 0;
   int contador_cadena = 0;
   int i = 0;
   int j = 0;
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

   for (i = 0;i < tam_cadena ; i++){
      if (cadena[i] == a_borrar)
         n_apariciones++;
   }

   tam_util_sustituido = (n_apariciones * tam_cadena_sustitutos) + tam_cadena - n_apariciones;

   if (tam_util_sustituido > LONGITUD_MAXIMA){
      cout << "ERROR - El resultado es demasiado grande.";
   }
   else{
      i = 0;
      while (i < tam_util_sustituido){
         if (cadena[contador_cadena] != a_borrar){
            sustituido[i] = cadena[contador_cadena];
            i++;
         }
         else{
            j = 0;
            while (j < tam_cadena_sustitutos){
               sustituido[i] = caracteres_sustitutos[j];
               i++;
               j++;
            }
         }

         contador_cadena++;
      }

      for(i = 0; i < tam_util_sustituido; i++)
         cout << sustituido[i] << " ";
   }
}
