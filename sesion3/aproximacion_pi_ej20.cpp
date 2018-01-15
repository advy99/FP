//Aproximaciones de PI

#include <iostream>

using namespace std;

int main(){
	const double APROXIMACION_PI_1800AC = 256.0 / 81.0;
	const double APROXIMACION_PI_MESOPOTAMICOS = 3.0 + 1.0 / 8.0;
	const double APROXIMACION_PI_PTOLOMEO = 377.0 / 120;
	
	cout << "La aproximacion del numero PI dada en el 1800 AC es: " << APROXIMACION_PI_1800AC;
	cout << "\nLa aproximacion del numero PI dada por los mesopotamicos es: " << APROXIMACION_PI_MESOPOTAMICOS;
	cout << "\nLa aproximacion del numero PI dada por Ptolomeo es: " << APROXIMACION_PI_PTOLOMEO;
}
