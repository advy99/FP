//Calcular el número de segundos entre dos instantes del mismo dia

#include <iostream>

using namespace std;

int main(){
   double hora_instante1;
   double minuto_instante1;
   double segundo_instante1;
   double hora_instante2;
   double minuto_instante2;
   double segundo_instante2;
   double segundos_totales_instante1;
   double segundos_totales_instante2;
   double diferencia;

   cout << "Introduce la hora del instante 1: ";
   cin >> hora_instante1;
   cout << "Introduce el minuto del instante 1: ";
   cin >> minuto_instante1;
   cout << "Introduce el segundo del instante 1: ";
   cin >> segundo_instante1;

   cout << "\nIntroduce la hora del instante 2: ";
   cin >> hora_instante2;
   cout << "Introduce el minuto del instante 2: ";
   cin >> minuto_instante2;
   cout << "Introduce el segundo del instante 2: ";
   cin >> segundo_instante2;

   segundos_totales_instante1 = segundo_instante1 + minuto_instante1*60 + hora_instante1*3600;
   segundos_totales_instante2 = segundo_instante2 + minuto_instante2*60 + hora_instante2*3600;
   diferencia = segundos_totales_instante2 - segundos_totales_instante1;

   cout << "Hay " << diferencia << " segundos entre el primer y el segundo instante";
}
