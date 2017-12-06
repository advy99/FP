#include <iostream>
using namespace std;

enum class TipoLetra
            {mayuscula, minuscula, no_alfabetico};

int main(){
   char letra_convertida, letra_original;
   const int DISTANCIA_MAY_MIN = 'a'-'A';
   const int INICIO_MAYUS = 'A' , FIN_MAYUS = 'Z';
   const int INICIO_MINUS = 'a' , FIN_MINUS = 'z';
   TipoLetra caracter;

   cout << "Pasar de mayúscula a minúscula y viceversa\n\n"
        << "Introduzca una letra  --> ";
   cin >> letra_original;

   if ((letra_original >= INICIO_MAYUS) && (letra_original <= FIN_MAYUS)){
      letra_convertida = letra_original + DISTANCIA_MAY_MIN;
      caracter = TipoLetra::mayuscula;
   }
   else
      if ((letra_original >= INICIO_MINUS) && (letra_original <= FIN_MINUS)){
         letra_convertida = letra_original - DISTANCIA_MAY_MIN;
         caracter = TipoLetra::minuscula;
      }
      else
         letra_convertida = letra_original;

   if ( caracter == TipoLetra::mayuscula )
      cout << "\nEl carácter era una mayúscula";
   else if ( caracter == TipoLetra::minuscula )
      cout << "\nEl carácter era una minúscula";
   else
      cout << "\nEl carácter no era alfabético";

   cout << ", una vez convertido es: " << letra_convertida;
}
