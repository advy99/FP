#include <iostream>

using namespace std;

int main(){
   const int MAXIMO_N_ALTURAS = 100;
   int n_alturas;
   int desnivel = 0;
   int maximo_desnivel = 0;
   int desnivel_acumulado_positivo = 0;
   bool hay_datos_suficientes = false;
   int alturas[MAXIMO_N_ALTURAS];

   cout << "Introduce el numero de datos a introducir: ";
   cin >> n_alturas;

   if (n_alturas > 1)
      hay_datos_suficientes = true;



   for (int i = 0;i < n_alturas; i++){
      cin >> alturas[i];


      if (i > 0){
         desnivel = alturas[i] - alturas[i - 1];

         if (desnivel < 0){
            desnivel = -desnivel;
         }
         else{
            desnivel_acumulado_positivo = desnivel_acumulado_positivo +
                                          desnivel;
         }
         if (desnivel > maximo_desnivel)
            maximo_desnivel = desnivel;
      }
   }

   if (hay_datos_suficientes)
      cout << maximo_desnivel << "\t" << desnivel_acumulado_positivo;
   else
      cout << "No hay datos suficientes.";
}
