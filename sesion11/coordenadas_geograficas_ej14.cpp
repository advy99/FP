#include <iostream>
#include <cmath>

using namespace std;

class CoordenadasGPS{
private:
   double longitud;
   double latitud;
   double altura;

   bool EstaEnIntervalo(double dato, int minimo, int maximo){
      if (dato >= minimo && dato <= maximo)
         return true;
      else
         return false;
   }
   double PasarARadianes(double grados){
      const int PI = 6 * asin(0.5);
      return grados * PI / 180;
   }

public:
   CoordenadasGPS()
      :longitud(0),
       latitud(0),
       altura(0)
   {
   }
   void SetLatitud(double nueva_latitud){
      if(EstaEnIntervalo(nueva_latitud, -90,90))
         latitud = PasarARadianes(nueva_latitud);
   }
   void SetLongitud(double nueva_longitud){
      if(EstaEnIntervalo(nueva_longitud,-180,180))
         longitud = PasarARadianes(nueva_longitud);
   }
   void SetAltura(double nueva_altura){
      if(EstaEnIntervalo(nueva_altura, -423, 8848))
         altura = nueva_altura;
   }
   double Longitud(){
      return longitud;
   }
   double Latitud(){
      return latitud;
   }
   double Altura(){
      return altura;
   }
};

int main(){
   CoordenadasGPS punto1;

   punto1.SetAltura(900);
   punto1.SetLatitud(45);
   punto1.SetLongitud(100);

   cout << punto1.Latitud() << "\t" << punto1.Longitud() << "\t" << punto1.Altura();
}
