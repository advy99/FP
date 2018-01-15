#include <iostream>

using namespace std;

int main(){
   char letra;
   int edad;
   int adivine;
   int anio;
   bool es_minuscula, no_es_adulto, esta_intervalo, es_bisiesto;

   cout << "Introduce una letra: ";
   cin >> letra;
   cout << "Introduce una edad: ";
   cin >> edad;
   cout << "Introduce un numero: ";
   cin >> adivine;
   cout << "Introduce un anio: ";
   cin >> anio;

   es_minuscula = 'a' <= letra && letra <= 'z';
   no_es_adulto = edad < 18 || edad > 65;
   esta_intervalo = adivine >= 1 && adivine <= 100;
   es_bisiesto = anio % 100 == 0;

   cout  << "\nLa letra " << letra << "es minuscula: " << es_minuscula
         << "\nUna persona de edad " << edad << " no es adulto: " << no_es_adulto
         << "\nEl numero " << adivine << " esta entre 1 y 100: " << esta_intervalo
         << "\nEl anio " << anio << " es bisiesto " << es_bisiesto;

}
