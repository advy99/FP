//Intercambiar tres variables
#include <iostream>

using namespace std;

int main(){
   double x,y,z;
   double paso_intermedio;
   cout << "Introduce el valor de la primera variable (x): ";
   cin >> x;
   cout << "Introduce el valor de la segunda variable (y): ";
   cin >> y;
   cout << "Introduce el valor de la tercera variable (z): ";
   cin >> z;

   paso_intermedio = y;
   y = x;
   x = paso_intermedio;
   paso_intermedio = z;
   z = x;
   x = paso_intermedio;

   cout << "Los nuevos valores de las variables son: " << x << " , " << y << " , " << z << "\n";
}
