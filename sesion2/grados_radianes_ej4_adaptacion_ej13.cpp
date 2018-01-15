//Conversión de grados a radianes

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double grados;
	double grados2;
	double radianes;
	double radianes2;
	const double PI = 6 * asin(0.5);
	const double GRADOS_A_RADIANES = PI / 180.0;
	
	cout << "Introduce el primer ángulo en grados: ";
	cin >> grados;
	cout << "Introduce el segundo ángulo en grados: ";
	cin >> grados2;

	radianes = grados * GRADOS_A_RADIANES;
	radianes2 = grados2 * GRADOS_A_RADIANES;

	cout << "\n" << grados << " grados son " << radianes << " radianes\n";
	cout << grados2 << " grados son " << radianes2 << " radianes\n";
}

