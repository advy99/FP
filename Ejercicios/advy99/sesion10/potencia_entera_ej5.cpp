#include <iostream>

using namespace std;

double PotenciaEntera (double numero_a_elevar, int potencia){
	double numero_elevado = 1;
	for (int i = 0;i < potencia; i++){
		numero_elevado = numero_elevado * numero_a_elevar;
	}
	return numero_elevado;
}

int main (){
	double base, potencia;
	int exponente;

	cout << "Introduce la base: ";
	cin >> base;
	cout << "Introduce el exponente: ";
	cin >> exponente;

	potencia = PotenciaEntera(base, exponente);

	cout << base << " elevado a " << exponente << " es " << potencia;
}
