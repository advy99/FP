#include <iostream>

using namespace std;

int main(){
   int primer_entero, segundo_entero;
   int producto_enteros;
   bool mismo_signo;
   bool primer_positivo;
   bool segundo_positivo;

   cout << "Introduce el primer entero: ";
   cin >> primer_entero;
   cout << "Introduce el segundo entero: ";
   cin >> segundo_entero;

   primer_positivo = primer_entero > 0;
   segundo_positivo = segundo_entero > 0;

   mismo_signo =  (primer_positivo && segundo_positivo) ||
                  (!primer_positivo && !segundo_positivo);

   cout << primer_entero << " y " << segundo_entero << " tienen el mismo signo: " << mismo_signo;


   /*SEGUNDA VERSION
   if (primer_positivo)
      if (segundo_positivo)
         mismo_signo = true;
      else
         mismo_signo = false;
   else
      if(segundo_signo)
         mismo_signo = false;
      else
         mismo_signo = true;
   */
}
