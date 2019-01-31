#include <iostream>

using namespace std;

class Dinero{
private:
   int euros;
   int centimos;

   bool CifraAIngresarCorrecta(int euros_a_ingresar, int centimos_a_ingresar){
      if (euros_a_ingresar >= 0 && centimos_a_ingresar > 0)
         return true;
      else
         return false;
   }

public:
   Dinero()
      :euros(0),
       centimos(0)
   {
   }
   void Ingresar(int euros_a_ingresar, int centimos_a_ingresar){
      if( CifraAIngresarCorrecta(euros_a_ingresar, centimos_a_ingresar) ){
         euros = euros + euros_a_ingresar;
         euros = euros + (centimos_a_ingresar / 100);
         centimos = centimos + centimos_a_ingresar % 100;
      }
   }
   int Euros(){
      return euros;
   }
   int Centimos(){
      return centimos;
   }
};

int main(){
   Dinero cuenta_uno, cuenta_dos, cuenta_suma;
   int euros, centimos, suma_euros, suma_centimos;

   cout << "Introuzca los euros de la cuenta 1:";
   cin >> euros;
   cout << "Introuzca los centimos de la cuenta 1:";
   cin >> centimos;

   cuenta_uno.Ingresar(euros,centimos);

   cout << "Introuzca los euros de la cuenta 2:";
   cin >> euros;
   cout << "Introuzca los centimos de la cuenta 2:";
   cin >> centimos;
   cuenta_dos.Ingresar(euros, centimos);

   suma_euros = cuenta_uno.Euros()+cuenta_dos.Euros();
   suma_centimos = cuenta_uno.Centimos()+cuenta_dos.Centimos();

   cuenta_suma.Ingresar(suma_euros, suma_centimos);

   cout << "\nLa suma de las cuentas es \n\n" << cuenta_suma.Euros() << "\t" << cuenta_suma.Centimos();
}
