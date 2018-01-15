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
   double numero_redondeado = numero;
   int parte_decimal;
   int parte_natural = numero;
   string numero_convertido_redondeado;
   string parte_natural_convertido = to_string(parte_natural);
   string parte_decimal_convertido;


   numero_redondeado = numero_redondeado - parte_natural;
   numero_redondeado = Redondea(numero_redondeado, cifra);

   parte_decimal = numero_redondeado * PotenciaEntera(10, cifra);
   parte_decimal_convertido = to_string(parte_decimal);

   numero_convertido_redondeado = "" + parte_natural_convertido;
   numero_convertido_redondeado.push_back('.');
   numero_convertido_redondeado = numero_convertido_redondeado + parte_decimal_convertido;


   return numero_convertido_redondeado;
}

int main(){
   double numero_real;

   int cifra_a_redondear;
   string numero_como_cadena;

   cout << "Introduce un numero real: ";
   cin >> numero_real;
   cout << "Introduce una cifra a la que redondear: ";
   cin >> cifra_a_redondear;

   cout.precision(16);

   numero_como_cadena = DoubleToString(numero_real, cifra_a_redondear);

   cout << numero_como_cadena;
}
