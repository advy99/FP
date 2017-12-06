//Programa para calcular el voltaje segun la ley de Ohm

#include <iostream>

using namespace std;

int main(){
	double intensidad;
	double resistencia;
	double voltaje;
	
	cout << "Introduce la intensidad: ";
	cin >> intensidad;
	cout << "Introduce la resistencia: ";
	cin >> resistencia;
	
	voltaje = intensidad * resistencia;
	
	cout << "\nEl voltaje es de " << voltaje << " voltios\n";
}
