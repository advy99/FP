#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const int TAMANIO_BYTE = 8;
	const int PARADA = -1;
	int cambio_binario;
	int numero;
	int caracteres_por_leer = TAMANIO_BYTE;
	int pos_cambio_binario = caracteres_por_leer - 1;
	double n_letras = 0.0;
	double n_bloques = 0.0;
	double porcentaje_letras = 0.0;
	double porcentaje_otros;
	const char MIN_MINUS = 'a';
	const char MAX_MINUS = 'z';
	const char MIN_MAYUS = 'A';
	const char MAX_MAYUS = 'Z';
	string frase = "";
	char bloque_en_ascii = 0;
	bool salida = false;

	cout << "Introduce una lista de numeros (-1 para finalizar): ";
	do{

		cin >> numero;
		if (numero == 1 || numero == 0){
			cambio_binario = pow(2,pos_cambio_binario);
			bloque_en_ascii = bloque_en_ascii + numero * cambio_binario;

			if (caracteres_por_leer == 1){

				if ( (bloque_en_ascii > MIN_MINUS && bloque_en_ascii < MAX_MINUS) || (bloque_en_ascii > MIN_MAYUS && bloque_en_ascii < MAX_MAYUS) ){
					frase = frase + bloque_en_ascii;
					n_letras = n_letras + 1.0;
				}

				bloque_en_ascii = 0;
				caracteres_por_leer = TAMANIO_BYTE;
				n_bloques = n_bloques + 1.0;
			}
			else
				caracteres_por_leer--;

			pos_cambio_binario = caracteres_por_leer - 1;

		}

		salida = numero == PARADA;
	}while (!salida);

	porcentaje_letras = (n_letras / n_bloques) * 100.0;
	porcentaje_otros = 100.0 - porcentaje_letras;

	cout << frase;
	cout << "\nLetras: " << porcentaje_letras << "%\n";
	cout << "Otros: " << porcentaje_otros << "%";
}

/*
while (!fin_entrada){
	while (!ocho_bits_leidos && !fin_entrada){
		cin >> bit;
		if (es_bit){
			procesando (suma = suma + potencia_adecuada)
		}

	}

	if (ocho_bits_leidos){
		imprimir_pantalla
		procesar_caracter
	}
}
*/
