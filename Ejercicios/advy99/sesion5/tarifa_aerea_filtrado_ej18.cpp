#include <iostream>

using namespace std;

int main(){
   const int BASE = 150;
   const double TOPE_KILOMETROS = 300;
   const double EUROS_POR_KILOMETRO = 0.1;
   double precio_total, kilometros, kilometros_extra;
   double descuento_trayecto = 0, descuento_puntos = 0;
   double descuento_total = 0;
   int n_puntos;
   const int KILOMETROS_SIN_DESCUENTO = 700;
   const int N_PUNTOS_DESCUENTO_PEQUENIO = 100;
   const int N_PUNTOS_DESCUENTO_GRANDE = 200;
   const int MAXIMO_PUNTOS = 400;
   const int MINIMO_PUNTOS = 0;

   do{
      cout << "Introduzca el número de kilometros al destino: ";
      cin >> kilometros;
   }while (kilometros < 0);

   do{
      cout << "Introduzca el numero de puntos: ";
      cin >> n_puntos;
   }while (n_puntos <= MINIMO_PUNTOS || n_puntos >= MAXIMO_PUNTOS);

	precio_total = BASE;

	/*Calculamos precio_final seún los KM
	*/

	if (kilometros > TOPE_KILOMETROS){
      kilometros_extra = kilometros - TOPE_KILOMETROS;
      precio_total = BASE + (kilometros_extra * EUROS_POR_KILOMETRO);
	}

	/*Recogemos los distintos descuentos y aplicamos variación
	*/

	if (kilometros > KILOMETROS_SIN_DESCUENTO){
      descuento_trayecto = 2;
	}

	if (n_puntos > N_PUNTOS_DESCUENTO_PEQUENIO){
      descuento_puntos = 3;

      if (n_puntos > N_PUNTOS_DESCUENTO_GRANDE){
         descuento_puntos = 4;
      }
	}

   descuento_total = 1.0 - (descuento_puntos + descuento_trayecto) / 100.0;

   precio_total = precio_total * descuento_total;

	cout << "\nEl precio total del billete sera de " << precio_total << " euros\n";
}
