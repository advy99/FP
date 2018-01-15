#include <iostream>

using namespace std;

int main(){
   int primer_entero, segundo_entero;
   int producto_enteros;

   cout << "Introduce el primer entero: ";
   cin >> primer_entero;
   cout << "Introduce el segundo entero: ";
   cin >> segundo_entero;

   producto_enteros = primer_entero * segundo_entero;

   if(producto_enteros > 0){
      cout << primer_entero << " y " << segundo_entero << " tienen el mismo signo";
   }
   else{
      cout << primer_entero << " y " << segundo_entero << " no tienen el mismo signo";
   }
}
