#include <iostream>  
using namespace std; 

int LeerIntMayorIgualQue (int minimo){
	int num_mayor_igual;
	
	do{
		cout << "Introduzca un numero mayor que " << minimo <<": ";
		cin >> num_mayor_igual;
	}while (num_mayor_igual < minimo);
	
	return num_mayor_igual;
}

int LeeIntRango(int min, int max, string mensaje) {
   int a_leer;
   
   do{
      cout << mensaje;
      cin >> a_leer;
   }while (min > a_leer || max < a_leer);
   
   return a_leer;
}

int main(){
   const int TOTAL_A_INTRODUCIR = 3;
   
   long min, max, dato, suma;
   
   cout << "Programa de prueba para la función LeeIntRango"
        << "\nIntroduzca el valor mínimo y el máximo"
        << "\nA continuación introduzca "
        << TOTAL_A_INTRODUCIR << " enteros en el rango anterior\n";
        
   cin >> min;
   max = LeerIntMayorIgualQue(min);
   suma = 0;
   
   for (int i = 0; i < TOTAL_A_INTRODUCIR; i++){
      dato = LeeIntRango(min, max, "");
      suma = suma + dato;
   }

   cout << "\n\nSuma total: " << suma;
}
