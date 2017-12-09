#include <iostream>
#include <cmath>

using namespace std;

struct MaximoTempEntreMinimos{
   int fila;
   int columna;
};

class TablaTemperaturas{
private:
   static const int NUM_CIUDADES = 10;
   static const int NUM_TEMPERATURAS = 24;


   double tabla_temperaturas[NUM_CIUDADES][NUM_TEMPERATURAS];


   bool ExisteCiudadYTemperatura(int num_ciudad, int num_hora){
      if( num_ciudad >= 0     && num_ciudad < NUM_CIUDADES &&
          num_hora >=0 && num_hora < NUM_TEMPERATURAS ){

         return true;
      }
      else
         return false;
   }
public:

   double Valor(int num_ciudad, int num_hora){
      if( ExisteCiudadYTemperatura(num_ciudad, num_hora) )
         return tabla_temperaturas[num_ciudad][num_hora];
      else
         return NAN;
   }
   void Modifica(int num_ciudad, int num_hora, double nueva_temperatura){
      if( ExisteCiudadYTemperatura(num_ciudad, num_hora) ){
         tabla_temperaturas[num_ciudad][num_hora] = nueva_temperatura;
      }
   }
   int Minimo(int fila_a_buscar){
      int columna_minimo = 0;

      for(int i = 1; i < NUM_TEMPERATURAS; i++){
         if(tabla_temperaturas[fila_a_buscar][i] < tabla_temperaturas[fila_a_buscar][columna_minimo])
            columna_minimo = i;
      }

      return columna_minimo;
   }

   MaximoTempEntreMinimos MaxMinimos(){
      MaximoTempEntreMinimos maximo_entre_minimos;
      int minimos_por_fila[NUM_CIUDADES];

      for (int i = 0; i < NUM_CIUDADES; i++){
         minimos_por_fila[i] = Minimo(i);
      }

      maximo_entre_minimos.fila = 0;
      maximo_entre_minimos.columna = minimos_por_fila[0];

      for(int i = 1; i < NUM_CIUDADES; i++){
         if(tabla_temperaturas[i][minimos_por_fila[i]] > tabla_temperaturas[maximo_entre_minimos.fila][maximo_entre_minimos.columna]){
            maximo_entre_minimos.fila = i;
            maximo_entre_minimos.columna = minimos_por_fila[i];
         }
      }


      return maximo_entre_minimos;
   }

};

int main(){

}
