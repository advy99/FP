#include <iostream>
#include <cmath>

using namespace std;

class TablaTemperaturas{
private:
   static const int NUM_CIUDADES = 10;
   static const int NUM_TEMPERATURAS = 24;

   double tabla_temperaturas[NUM_CIUDADES][NUM_TEMPERATURAS];

   bool ExisteCiudadYTemperatura(int num_ciudad, int num_temperatura){
      if( num_ciudad >= 0     && num_ciudad < NUM_CIUDADES &&
          num_temperatura >=0 && num_temperatura < NUM_TEMPERATURAS ){

         return true;
      }
      else
         return false;
   }
public:

   double Valor(int num_ciudad, int num_temperatura){
      if( ExisteCiudadYTemperatura(num_ciudad, num_temperatura) )
         return tabla_temperaturas[num_ciudad][num_temperatura];
      else
         return NAN;
   }
   void Modifica(int num_ciudad, int num_temperatura, double nueva_temperatura){
      if( ExisteCiudadYTemperatura(num_ciudad, num_temperatura) ){
         tabla_temperaturas[num_ciudad][num_temperatura] = nueva_temperatura;
      }
   }
   int Minimo(int fila_a_buscar){
      int columna_minimo = tabla_temperaturas[fila_a_buscar][0];

      for(int i = 1; i < NUM_TEMPERATURAS; i++){
         if(tabla_temperaturas[fila_a_buscar][i] < columna_minimo)
            columna_minimo = tabla_temperaturas[fila_a_buscar][i];
      }

      return columna_minimo;
   }
};

int main(){

}
