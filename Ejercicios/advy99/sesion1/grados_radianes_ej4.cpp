//Conversión de grados a radianes

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double grados;
	double grados2;
	double radianes;
	double radianes2;
	double pi;
	
	cout << "Introduce el primer ángulo en grados: ";
	cin >> grados;
	cout << "Introduce el segundo ángulo en grados: ";
	cin >> grados2;
	
	pi = 6 * asin(0.5);
	radianes = grados * pi / 180;
	radianes2 = grados2 * pi / 180;

	cout << grados << " grados son " << radianes << " radianes\n";
	cout << grados2 << " grados son " << radianes2 << " radianes\n";
}

