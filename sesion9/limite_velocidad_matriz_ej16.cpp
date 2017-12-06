#include <iostream>

using namespace std;

int main () {
  const int FILAS      = 5 ;
  const int COLUMNAS   = 10;
  const int INICIAL    = 31;
  const int INCREMENTO = 10;
  const int SALTO = 30 ;
  int numero = INICIAL;
  int tabla[FILAS][COLUMNAS];

  for ( int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++){
      tabla[i][j] = numero;
      if (j == 2 ){
         if (i >= 2)
            numero = numero + SALTO;
         else
            numero = numero + (INCREMENTO * (i + 1));
      }
      else{
         numero = numero + INCREMENTO;
      }
    }
     numero = INICIAL + INCREMENTO + ((i+1)*INCREMENTO);
  }

  for(int i = 0;i < FILAS;i++){
     for(int j = 0; j < COLUMNAS; j++){
        cout << tabla[i][j] << "\t";
     }
     cout << "\n";
  }

}
