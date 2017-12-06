#include <iostream>

using namespace std;

string EliminaUltimos(string cadena, char elemento_a_borrar){
   while(cadena[cadena.size() - 1] == elemento_a_borrar){
      cadena.pop_back();
   }

   return cadena;
}

int main(){
   const char TERMINADOR = '#';
   char a_eliminar, nuevo_elemento;
   string cadena = "";
   int i;

   i = 0;

   cout << "Introduce una cadena y el caracter a eliminar, separandolos con #: ";
   nuevo_elemento = cin.get();

   while(nuevo_elemento != TERMINADOR){
      cadena.push_back(nuevo_elemento);
      nuevo_elemento = cin.get();
   }

   a_eliminar = cin.get();

   cadena = EliminaUltimos(cadena, a_eliminar);

   cout << "\n\nLa nueva cadena es : \n";
   cout << cadena;
}
