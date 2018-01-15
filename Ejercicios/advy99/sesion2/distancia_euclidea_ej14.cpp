//Programa para calcular la distancia euclidea a partir de dos puntos

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double punto1_x;
	double punto1_y;
	double punto2_x;
	double punto2_y;
	double distancia;
	double diferencia_x;
	double diferencia_y;
	
	cout << "Introduce la coordenada X del punto 1: ";
	cin >> punto1_x;
	cout << "Introduce la coordenada Y del punto 1: ";
	cin >> punto1_y;
	cout << "\n\nIntroduce la coordenada X del punto 2: ";
	cin >> punto2_x;
	cout << "Introduce la coordenada Y del punto 2: ";
	cin >> punto2_y;
	
	diferencia_x = punto1_x - punto2_x;
	diferencia_y = punto1_y - punto2_y;
	
	distancia = sqrt(diferencia_x*diferencia_x + diferencia_y*diferencia_y);
	
	cout << "\nLa distancia entre el punto (" << punto1_x << " , " << punto1_y << ") y el punto (" << punto2_x << " , " << punto2_y << ") es de " << distancia;
	
}
