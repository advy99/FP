#include <iostream>

using namespace std;

int main(){
   char caracter, caracter_codificado, letra_final, letra_inicial;
   int codigo, pos_caracter_intervalo;
   const int RANGO_MAYUS = 'Z' - 'A' + 1;
   const char INICIO_LETRAS = 'A';
   int division;

   cout << "Introduce un caracter, en mayuscula: ";
   cin >> caracter;
   cout << "Introduce la clave: ";
   cin >> codigo;

   pos_caracter_intervalo = caracter - INICIO_LETRAS;
   caracter_codificado = pos_caracter_intervalo + codigo;
   division = caracter_codificado / RANGO_MAYUS;
   letra_final = caracter_codificado % RANGO_MAYUS;
   letra_final = letra_final + INICIO_LETRAS;

   letra_inicial = letra_final - codigo - INICIO_LETRAS;
   letra_inicial = letra_inicial % RANGO_MAYUS;
   letra_inicial = letra_inicial + INICIO_LETRAS + division * RANGO_MAYUS;

   cout << caracter << "\t" << letra_final;
   cout << "\n" << letra_final << "\t" << letra_inicial;
}
