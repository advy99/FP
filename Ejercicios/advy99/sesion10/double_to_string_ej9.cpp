#include <iostream>
#include <cmath>

using namespace std;

string EliminaUltimos(string cadena, char elemento_a_borrar){
   while(cadena[cadena.size() - 1] == elemento_a_borrar){
      cadena.pop_back();
   }

   return cadena;
}

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

string DoubleToString(double numero,int cifra){
   double numero_redondeado;
   string numero_convertido_cadena;

   numero_redondeado = Redondea(numero, cifra);

   numero_convertido_cadena = to_string(numero_redondeado);
   numero_convertido_cadena = EliminaUltimos(numero_convertido_cadena,'0');

   return numero_convertido_cadena;
}

int main(){
   double numero_real;

   int cifra_a_redondear;
   string numero_como_cadena;

   cout << "Introduce un numero real: ";
   cin >> numero_real;
   cout << "Introduce una cifra a la que redondear: ";
   cin >> cifra_a_redondear;

   numero_como_cadena = DoubleToString(numero_real, cifra_a_redondear);

   cout << numero_como_cadena;
}
