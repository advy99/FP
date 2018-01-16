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

class FormatearDoubleToString{
private:
   string delimitador_izq;
   string delimitador_der;
   char separador;
   int num_decimales;

public:
   FormatearDoubleToString()
      :delimitador_der(">>"),
       delimitador_izq("<<"),
       separador(','),
       num_decimales(7)
   {
   }

   string PasaACadena(double real){
      int parte_natural = real;
      int parte_decimal_como_int;
      double parte_decimal = real - parte_natural;
      string cadena_formateada;
      string parte_natural_cadena;
      string parte_decimal_cadena;

      parte_decimal_como_int = Redondea(parte_decimal, num_decimales) * PotenciaEntera(10, num_decimales);

      parte_natural_cadena = to_string(parte_natural);
      parte_decimal_cadena = to_string(parte_decimal_como_int);

      cadena_formateada = delimitador_izq + parte_natural_cadena + separador + parte_decimal_cadena + delimitador_der;

      return cadena_formateada;
   }
   void SetDelimitadorIzq(string cadena_nueva){
      delimitador_izq = cadena_nueva;
   }
   void SetDelimitadorDer(string cadena_nueva){
      delimitador_der = cadena_nueva;
   }
   void SetSeparador(char caracter){
      separador = caracter;
   }
   void SetNumDecimales(int entero){
      num_decimales = entero;
   }
   string DelimitadorIzq(){
      return delimitador_izq;
   }
   string DelimitadorDer(){
      return delimitador_der;
   }
   char Separador(){
      return separador;
   }
   int NumDecimales(){
      return num_decimales;
   }
};


int main(){
   FormatearDoubleToString cadena_a_formatear;
   string a_rellenar;
   char separador;
   int cifras;
   double real;
   string real_convertido;

   cout << "Introduzca el delimitador izquierdo: ";
   cin >> a_rellenar;

   cadena_a_formatear.SetDelimitadorIzq(a_rellenar);

   cout << "Introduzca el delimitador derecho: ";
   cin >> a_rellenar;

   cadena_a_formatear.SetDelimitadorDer(a_rellenar);

   cout << "Introduzca el separador: ";
   cin >> separador;

   cadena_a_formatear.SetSeparador(separador);

   cout << "Introduzca hasta que cifra redondear: ";
   cin >> cifras;

   cadena_a_formatear.SetNumDecimales(cifras);

   cout << "Introduzca el numero a formatear: ";
   cin >> real;

   cout << "El numero formateado es : " << cadena_a_formatear.PasaACadena(real);
}
