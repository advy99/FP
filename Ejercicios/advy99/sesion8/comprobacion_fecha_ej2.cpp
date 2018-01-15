#include <iostream>

using namespace std;

int main(){
   const int MAX_FECHAS = 100;
   int num_fechas_pedidas = 0;
   int dia;
   int mes;
   int anio;
   int dias_en_mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
   string son_fechas_validas[MAX_FECHAS];
   bool salir;
   bool fecha_valida = false;
   bool es_bisiesto;

   cout << "Introduce el dia: ";
   cin >> dia;
   salir = dia < 0;


   while (!salir){
      cout << "Introduce el mes: ";
      cin >> mes;
      cout << "Introduce el año: ";
      cin >> anio;

      /*Adaptamos el numero del mes con el comienzo del vector ( el 1 pasa a ser el 0)
      comprobamos si es un mes correcto, si año es bisiesto, sumamos 1 a los dias de febrero
      si el dia esta entre 1 y los dias de ese mes es una fecha correcta.
         No se comprueban los años debido a que no especifica si el año puede ser negativo( A.C ).
         Se almacena en un vector de string si es correcta o no la fecha, y se muestra una vez
      finalizada la entrada de datos.

      */

      mes--;

      es_bisiesto = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;

      if (mes >= 0 && mes <= 11){
         if ( mes == 1 && es_bisiesto ){
            dias_en_mes[1]++;
         }
         if (dia >= 1 && dia <= dias_en_mes[mes]){
            fecha_valida = true;
         }
         else{
            fecha_valida = false;
         }
      }
      else{
         fecha_valida = false;
      }

      if (fecha_valida)
         son_fechas_validas[num_fechas_pedidas] = "SI";
      else
         son_fechas_validas[num_fechas_pedidas] = "NO";

      num_fechas_pedidas++;

      cout << "Introduce el dia: ";
      cin >> dia;
      salir = dia < 0;
   }

   for (int i  = 0; i < num_fechas_pedidas; i++) {
      cout << son_fechas_validas[i] << " ";
   }
}
