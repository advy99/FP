#include <iostream>
#include <cmath>

using namespace std;

double PotenciaEntera (double numero_a_elevar, int potencia){
	double numero_elevado = 1;
	for (int i = 0;i < potencia; i++){
		numero_elevado = numero_elevado * numero_a_elevar;
	}
	return numero_elevado;
}

double Redondea(double a_redondear, int decimal_a_redondear){
   double desplazamiento;
   int redondeado;

   desplazamiento = PotenciaEntera(10, decimal_a_redondear);
   redondeado = round(a_redondear * desplazamiento);

   return redondeado/desplazamiento;
}

int main(){
   double numero, numero_redondeado;
   int n_cifra_a_redondear;

   cout << "Introduzca un numero real: ";
   cin >> numero;
   cout << "Introduzca la cifra a la que redondear: ";
   cin >> n_cifra_a_redondear;

   numero_redondeado = Redondea(numero, n_cifra_a_redondear);

   cout << "El numero redondeado es " << numero_redondeado;
	
   return (0);
}
