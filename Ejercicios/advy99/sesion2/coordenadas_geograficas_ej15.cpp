//Calculo de angulo entre dos puntos geograficos

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const double PI = 6 * asin(0.5);
	const double GRADOS_A_RADIANES = PI / 180.0;
	double grados_lon1;
	double grados_lat1;
	double grados_lon2;
	double grados_lat2;
	double radianes_lon1;
	double radianes_lat1;
	double radianes_lon2;
	double radianes_lat2;
	double mitad_diferencia_latitudes;
	double mitad_diferencia_longitudes;
	double seno_cuadrado_latitudes;
	double seno_cuadrado_longitudes;
	double alfa;

	cout << "Introduce la latitud de la coordenada 1 (en grados): ";
	cin >> grados_lat1;
	cout << "Introduce la longitud de la coordenada 1 (en grados): ";
	cin >> grados_lon1;
	cout << "\n\nIntroduce la latitud de la coordenada 2 (en grados): ";
	cin >> grados_lat2;
	cout << "Introduce la longitud de la coordenada 2 (en grados): ";
	cin >> grados_lon2;

	radianes_lon1 = grados_lon1 * GRADOS_A_RADIANES;
	radianes_lat1 = grados_lat1 * GRADOS_A_RADIANES;
	radianes_lon2 = grados_lon2 * GRADOS_A_RADIANES;
	radianes_lat2 = grados_lat2 * GRADOS_A_RADIANES;

	mitad_diferencia_latitudes = 0.5 * (radianes_lat2 - radianes_lat1);
	mitad_diferencia_longitudes = 0.5 * (radianes_lon2 - radianes_lon1);
	seno_cuadrado_latitudes = pow( sin(mitad_diferencia_latitudes) ,2);
	seno_cuadrado_longitudes = pow( sin(mitad_diferencia_longitudes) ,2);
	alfa = seno_cuadrado_latitudes + cos(radianes_lat1) * cos(radianes_lat2) * seno_cuadrado_longitudes;

   cout << "\nEl valor de alfa vale: " << alfa;
}
