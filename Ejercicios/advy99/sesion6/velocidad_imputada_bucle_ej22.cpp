#include <iostream>
#include <cctype>

using namespace std;

int main(){
	char tipo_radar;
	const char RADAR_FIJO = 'F';
	int velocidad, margen_error;
	double velocidad_imputada;
	double error_radar;
	double velocidad_imputada_maxima = 0;
	const int ERROR_RADAR_FIJO = 5, ERROR_RADAR_MOVIL = 7;
	const int TOPE_VELOCIDAD_ERROR = 100;
   string matricula;
	string matricula_mayor_velocidad = "" ;


	cout << "Introduce la matricula del vehiculo: ";
	cin >> matricula;

	while(matricula != "#"){
		cout << "Introduce el tipo de radar: ";
		cin >> tipo_radar;
		cout << "Introduce la velocidad: ";
		cin >> velocidad;

		tipo_radar = toupper(tipo_radar);

		if (tipo_radar == RADAR_FIJO){
			margen_error = ERROR_RADAR_FIJO;
		}
		else{
			margen_error = ERROR_RADAR_MOVIL;
		}

		if (velocidad <= TOPE_VELOCIDAD_ERROR){
			velocidad_imputada = velocidad - margen_error;
		}
		else{
			error_radar = 1.0 - margen_error / 100.0;
			velocidad_imputada = velocidad * error_radar;
		}
		if(velocidad_imputada > velocidad_imputada_maxima){
			velocidad_imputada_maxima = velocidad_imputada;
			matricula_mayor_velocidad = matricula;
		}

		cout << "Introduce la matricula del vehiculo: ";
		cin >> matricula;
	}
	cout << "\nLa matricula con mayor velocidad imputada es: " << matricula_mayor_velocidad;
	cout << "\nSu velocidad imputada es de: " << velocidad_imputada_maxima;
}
