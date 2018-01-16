#include <iostream>
#include <cmath>

using namespace std;

int main(){
   const double PI = 6 * asin(0.5);
	const double GRADOS_A_RADIANES = PI / 180.0;
	const double LONGITUD_MEDIA_RADIO_TIERRA = 6372797.560856;
	double grados_lon1, grados_lat1;
	double grados_lon2, grados_lat2;
	double radianes_lon1, radianes_lat1;
	double radianes_lon2, radianes_lat2;
	double mitad_diferencia_latitudes;
	double mitad_diferencia_longitudes;
	double seno_cuadrado_latitudes;
	double seno_cuadrado_longitudes;
	double alfa, raiz_alfa;
	double minimo, c, distancia_sin_altura;
	double altura_p1;
	double altura_p2;
	double distancia_sin_altura_cuadrado;
	double diferencia_altura_cuadrado;
	double distancia;

	cout << "Introduce la latitud de la coordenada 1 (en grados): ";
	cin >> grados_lat1;
	cout << "Introduce la longitud de la coordenada 1 (en grados): ";
	cin >> grados_lon1;
	cout << "Introduce la altura de la coordenada 1 (en metros): ";
	cin >> altura_p1;
	cout << "\n\nIntroduce la latitud de la coordenada 2 (en grados): ";
	cin >> grados_lat2;
	cout << "Introduce la longitud de la coordenada 2 (en grados): ";
	cin >> grados_lon2;
	cout << "Introduce la altura de la coordenada 2 (en metros): ";
	cin >> altura_p2;

	radianes_lon1 = grados_lon1 * GRADOS_A_RADIANES;
	radianes_lat1 = grados_lat1 * GRADOS_A_RADIANES;
	radianes_lon2 = grados_lon2 * GRADOS_A_RADIANES;
	radianes_lat2 = grados_lat2 * GRADOS_A_RADIANES;

	mitad_diferencia_latitudes = 0.5 * (radianes_lat2 - radianes_lat1);
	mitad_diferencia_longitudes = 0.5 * (radianes_lon2 - radianes_lon1);
	seno_cuadrado_latitudes = pow( sin(mitad_diferencia_latitudes) ,2);
	seno_cuadrado_longitudes = pow( sin(mitad_diferencia_longitudes) ,2);
	alfa = seno_cuadrado_latitudes + cos(radianes_lat1) * cos(radianes_lat2) * seno_cuadrado_longitudes;
   raiz_alfa = sqrt(alfa);
   minimo = 1;

   if (raiz_alfa < 1){
      minimo = raiz_alfa;
   }

   c = 2 * asin(minimo);
   distancia_sin_altura = c * LONGITUD_MEDIA_RADIO_TIERRA;

   distancia_sin_altura_cuadrado = pow(distancia_sin_altura,2);
   diferencia_altura_cuadrado = pow(altura_p1-altura_p2,2);
   distancia = sqrt(distancia_sin_altura_cuadrado + diferencia_altura_cuadrado);

   cout.precision(15);

   cout << "\nLa distancia entre los puntos es de " << distancia_sin_altura << " sin tener en cuenta la altura\n";
   cout << "\nLa distancia entre los puntos es de " << distancia << "\n";

}
