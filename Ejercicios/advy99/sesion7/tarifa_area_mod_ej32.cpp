#include <iostream>
using namespace std;

int main(){
   const int    LIMITE_KMS_TARIFICACION_ADICIONAL = 300;
   const double TARIFA_POR_KM_ADICIONAL = 0.1;
   const double MINIMO_KMS_DESCUENTO = 700.0;
   const int    MINIMO_PUNTOS_DESCUENTO_BAJO = 100;
   const int    MINIMO_PUNTOS_DESCUENTO_ALTO = 200;
   const double DESCUENTO_POR_KMS = 0.02;
   const double DESCUENTO_BAJO_POR_PUNTOS = 0.03;
   const double DESCUENTO_ALTO_POR_PUNTOS = 0.04;
   const double TARIFA_BASE = 150.0;
   const int    MAXIMO_NUM_PUNTOS = 400;
   const char NUEVO_BILLETE = 'N';
   const char SALIDA_BILLETE = '#';

   double descuento_final;
   double   tarifa_final;
   int distancia_trayecto;
   int num_puntos_fidelizacion;
   char billete;
   bool billete_valido;

	do{
		cout  << "Introducir nuevo billete (N)\n"
				<< "Salir (#)\n";
		cin >> billete;
		billete_valido = billete == NUEVO_BILLETE || billete == SALIDA_BILLETE;
	}while (!billete_valido );

	while(billete == NUEVO_BILLETE){
	   cout << "Tarifa aerea."
	        << "\nIntroduzca la distancia del recorrido del viaje (> 0) y el "
	        << "numero de puntos de la tarjeta de fidelización (entre 0 y "
	        << MAXIMO_NUM_PUNTOS << ":\n";

	   do{
	      cin >> distancia_trayecto;
	   }while (distancia_trayecto <= 0);

	   do{
	      cin >> num_puntos_fidelizacion;
	   }while (num_puntos_fidelizacion < 0 || num_puntos_fidelizacion > MAXIMO_NUM_PUNTOS);


	   tarifa_final = TARIFA_BASE;

	   if (distancia_trayecto > LIMITE_KMS_TARIFICACION_ADICIONAL)
	      tarifa_final = tarifa_final +
	                     TARIFA_POR_KM_ADICIONAL *
	                       (distancia_trayecto - LIMITE_KMS_TARIFICACION_ADICIONAL) ;


	   if (distancia_trayecto > MINIMO_KMS_DESCUENTO)
	      descuento_final = DESCUENTO_POR_KMS;
	   else
	      descuento_final = 0;

	   if (num_puntos_fidelizacion > MINIMO_PUNTOS_DESCUENTO_ALTO)
	      descuento_final = descuento_final + DESCUENTO_ALTO_POR_PUNTOS;
	   else if (num_puntos_fidelizacion > MINIMO_PUNTOS_DESCUENTO_BAJO)
	      descuento_final = descuento_final + DESCUENTO_BAJO_POR_PUNTOS;

	   tarifa_final = tarifa_final * (1 - descuento_final);

	   cout << "\n\nTarifa final aplicando los descuentos: ";
	   cout << tarifa_final << '\n';

	   do{
			cout  << "Introducir nuevo billete (N)\n"
					<< "Salir (#)\n";
			cin >> billete;
			billete_valido = billete == NUEVO_BILLETE || billete == SALIDA_BILLETE;
		}while (!billete_valido );
	}
}
