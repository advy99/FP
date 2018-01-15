#include <iostream>

using namespace std;

int main(){
   char caracter, letra_final, letra_inicial;
   int codigo;
   const char FIN_LETRAS = 'Z';
   const char INICIO_LETRAS = 'A';
   const int INTERVALO_LETRAS = 'Z' - 'A';

   cout << "Introduce un caracter, en mayuscula: ";
   cin >> caracter;
   cout << "Introduce la clave: ";
   cin >> codigo;

   letra_final = caracter + codigo;

   if (letra_final > FIN_LETRAS){
      letra_final = letra_final - INTERVALO_LETRAS;
   }

   letra_inicial = letra_final - codigo;

   if (letra_inicial < INICIO_LETRAS){
      letra_inicial = letra_inicial + INTERVALO_LETRAS;
   }

   cout << "El caracter " << caracter << " codificado es " << letra_final << "\n";
   cout << "El caracter original era " << letra_inicial;
}
