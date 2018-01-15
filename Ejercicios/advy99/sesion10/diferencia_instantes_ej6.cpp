#include <iostream>
#include <cmath>

using namespace std;

int HorasAMinutos(int horas){
   const int CAMBIO_HORAS_MINUTOS = 60;

   return horas * CAMBIO_HORAS_MINUTOS;
}

int MinutosASegundos(int minutos){
   const int CAMBIO_MINUTOS_SEGUNDOS = 60;

   return minutos * CAMBIO_MINUTOS_SEGUNDOS;
}

int PedirDatoRango(string mensaje, int tope_inferior, int tope_superior){
   int dato;
   do{
      cout << mensaje;
      cin >> dato;
   }while(dato < tope_inferior || dato > tope_superior);

   return dato;
}
int main(){
   const int MINIMO_HORA_CORRECTA = 0, MINIMO_MIN_CORRECTO = 0, MINIMO_SEG_CORRECTO = 0;
   const int MAXIMO_HORA_CORRECTA = 23, MAXIMO_MIN_CORRECTO = 59, MAXIMO_SEG_CORRECTO = 59;
   int horas_inicial, minutos_inicial, segundos_inicial;
   int horas_final, minutos_final, segundos_final;

   int diferencia_minutos, diferencia_segundos;
   int minutos_totales_iniciales, minutos_totales_finales;
   int segundos_totales_iniciales, segundos_totales_finales;

   horas_inicial    = PedirDatoRango("Introduce la hora inicial: ",MINIMO_HORA_CORRECTA, MAXIMO_HORA_CORRECTA);
   minutos_inicial  = PedirDatoRango("Introduce los minutos iniciales: ", MINIMO_MIN_CORRECTO, MAXIMO_MIN_CORRECTO);
   segundos_inicial = PedirDatoRango("Introduce los segundos iniciales: ", MINIMO_SEG_CORRECTO, MAXIMO_SEG_CORRECTO);

   horas_final    = PedirDatoRango("Introduce la hora final: ", MINIMO_HORA_CORRECTA, MAXIMO_HORA_CORRECTA);
   minutos_final  = PedirDatoRango("Introduce los minutos finales: ", MINIMO_MIN_CORRECTO, MAXIMO_MIN_CORRECTO);
   segundos_final = PedirDatoRango("Introduce los segundos finales: ", MINIMO_SEG_CORRECTO, MAXIMO_SEG_CORRECTO);

   minutos_totales_iniciales = HorasAMinutos(horas_inicial) + minutos_inicial;
   segundos_totales_iniciales = MinutosASegundos(minutos_totales_iniciales) + segundos_inicial;

   minutos_totales_finales = HorasAMinutos(horas_final) + minutos_final;
   segundos_totales_finales = MinutosASegundos(minutos_totales_finales) + segundos_final;

   diferencia_segundos = abs(segundos_totales_finales - segundos_totales_iniciales);
   diferencia_minutos = abs(minutos_totales_finales - minutos_totales_iniciales);

   cout << "La diferencia de segundos es de : " << diferencia_segundos;
   cout << "\nLa diferencia de minutos es de : " << diferencia_minutos;

}
