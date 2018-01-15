#include <iostream>

using namespace std;

int main(){
   int velocidad;
   int multa_puntos, multa_euros;

   cout << "Introduzca la velocidad: ";
   cin >> velocidad;

   multa_euros = 0;
   multa_puntos = 0;

   if (velocidad > 120){
      multa_euros = 100;
      multa_puntos = 0;

      if (velocidad > 150){
         multa_euros = 300;
         multa_puntos = 2;

         if (velocidad > 170){
            multa_euros = 400;
            multa_puntos = 4;

            if (velocidad > 180){
               multa_euros = 500;
               multa_puntos = 6;

               if (velocidad > 190){
                  multa_euros = 600;
                  multa_puntos = 6;
               }
            }
         }
      }
   }

   cout << "\nLa multa sera de " << multa_puntos << " puntos y " << multa_euros << " euros\n";
}
