#include <iostream>

using namespace std;

int main(){
   const int NUMERO_DIGITOS = 20;
   cout.precision(NUMERO_DIGITOS);

   //a)
   int chico_a, chico1_a, chico2_a;
   chico1_a = 1234567;
   chico2_a = 1234567;
   chico_a = chico1_a * chico2_a;   //Desbordamiento, en una variable entera no
                                    //tendria espacio suficiente

   cout << "Se produce un desbordamiento, el resultado correcto seria: 15242e12";
   cout << "\nSin embargo muestra: " << chico_a;

   //b)
   long grande_b;
   int chico1_b, chico2_b;
   chico1_b = 1234567;
   chico2_b = 1234567;
   grande_b = chico1_b * chico2_b;  //Mismo caso que a, el declarar grande_b
                                    //como long da igual, la evaluacion se
                                    //desborda antes de asignarse

   cout << "\n\nSe produce un desbordamiento, el resultado correcto seria: 15242e12";
   cout << "\nSin embargo muestra: " << grande_b;

   //c)
   double resultado_c, real1_c, real2_c;
   real1_c = 123.1;
   real2_c = 124.2;
   resultado_c = real1_c * real2_c;

   cout << "\n\nSe produce un problema de precision, el resultado correcto seria: 15289.02";
   cout << "\nSin embargo muestra: " << resultado_c;

   //d)
   double resultado_d, real1_d, real2_d;
   real1_d = 123456789.1;
   real2_d = 123456789.2;
   resultado_d = real1_d * real2_d;
   cout << "\n\nSe produce un problema de precision";
   cout << "\n" << resultado_d;

   //e)
   double real_e, otro_real_e;
   real_e = 2e34;
   otro_real_e = real_e + 1;
   otro_real_e = otro_real_e - real_e;

   cout << "\n\nSe produce un problema de precision, al ser un numero tan grande,"
        << " al sumar uno lo aproxima a el mismo";
   cout << "\nY muestra: " << otro_real_e;

   //f)
   double real_f, otro_real_f;
   real_f = 1e+300;
   otro_real_f = 1e+200;
   otro_real_f = otro_real_f * real_f;

   cout  << "\n\nSe produce un problema de desbordamiento, al ser tan grande"
         << " muestra el numero como infinito";
   cout << "\n" << otro_real_f;

   //g)
   float chico_g;
   double grande_g;
   grande_g = 2e+150;
   chico_g = grande_g;
   cout  << "\n\nSe produce un problema de desbordamiento, al ser tan grande"
         << " double lo interpreta como infinito";
   cout << "\n" << chico_g;
}
