#include <iostream>

using namespace std;

int main(){
   const int HORAS_MINUTOS = 60;
   const int MINUTOS_SEGUNDOS = HORAS_MINUTOS * 60;
   int hora_instante1;
   int minuto_instante1;
   int segundo_instante1;
   int hora_instante2;
   int minuto_instante2;
   int segundo_instante2;
   int segundos_totales_instante1;
   int segundos_totales_instante2;

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

   segundos_totales_instante1 = hora_instante1 * HORAS_MINUTOS * MINUTOS_SEGUNDOS;
   segundos_totales_instante1 += minuto_instante1 * MINUTOS_SEGUNDOS;
   segundos_totales_instante1 += segundo_instante1;

   segundos_totales_instante2 = hora_instante2 * HORAS_MINUTOS * MINUTOS_SEGUNDOS;
   segundos_totales_instante2 += minuto_instante2 * MINUTOS_SEGUNDOS;
   segundos_totales_instante2 += segundo_instante2;

   if (segundos_totales_instante1 > segundos_totales_instante2)
      cout << "\nEl instante 1 no es anterior al instante 2\n";

   else if (segundos_totales_instante1 < segundos_totales_instante2)
      cout << "\nEl instante 1 es anterior al instante 2\n";
   else
      cout << "\nAmbos instantes son el mismo\n";


/* Sin calcular los segundos totales


   if (hora_instante1 > hora_instante2)
      cout << "\nEl instante 1 no es anterior al instante 2\n";

   else if (hora_instante1 < hora_instante2)
      cout << "\nEl instante 1 es anterior al instante 2\n";

   else if (minuto_instante1 > minuto_instante2)
      cout << "\nEl instante 1 no es anterior al instante 2\n";

   else if (minuto_instante1 < minuto_instante2)
      cout << "\nEl instante 1 es anterior al instante 2\n";

   else if (segundo_instante1 > segundo_instante2)
      cout << "\nEl instante 1 no es anterior al instante 2\n";

   else if (segundo_instante1 < segundo_instante2)
      cout << "\nEl instante 1 es anterior al instante 2\n";

   else
      cout << "\nAmbos instantes son el mismo\n";

*/

}
