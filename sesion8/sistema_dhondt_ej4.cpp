#include <iostream>

using namespace std;

int main(){
   const int MAXIMO_PARTIDOS = 100;
   int numero_escanios;
   int numero_partidos;
   int votos_partido[MAXIMO_PARTIDOS];
   int escanio_partido[MAXIMO_PARTIDOS] = {};
   int partido_mayor_coeficiente;
   double cociente_dhondt;
   double mayor_cociente_dhondt = 0;
   int partido_mayor_cociente_dhondt = 0;

   cout << "Introduce el número de escaños: ";
   cin >> numero_escanios;
   cout << "Introduce el número de partidos: ";
   cin >> numero_partidos;


   for (int i = 0; i < numero_partidos; i++){
      cout << "Introduce el número de votos del partido " << i + 1 << ": ";
      cin >> votos_partido[i];
   }

   cout << "\n";

   for (int i = 0; i < numero_escanios; i++){
      for (int j = 0; j < numero_partidos; j++) {
         cociente_dhondt = votos_partido[j] / (escanio_partido[j] + 1);
         if (cociente_dhondt > mayor_cociente_dhondt ){
            partido_mayor_cociente_dhondt = j;
            mayor_cociente_dhondt = cociente_dhondt;
         }
      }
      escanio_partido[partido_mayor_cociente_dhondt]++;
      partido_mayor_cociente_dhondt = 0;
      mayor_cociente_dhondt = 0;
   }

   for (int i  = 0; i < numero_partidos; i++) {
      cout << "El partido " << i + 1 << " tiene " << escanio_partido[i] << " escaños\n";
   }
}
