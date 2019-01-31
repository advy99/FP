#include <iostream>
#include <cctype>

using namespace std;

int main(){
	char tipo_radar;
	char radar_fijo = 'F';
	int velocidad, margen_error;
	double velocidad_imputada;
	double error_radar;
	int error_radar_fijo = 5, error_radar_movil = 7;
	int tope_velocidad_error = 100;

	cout << "Introduce el tipo de radar: ";
	cin >> tipo_radar;
	cout << "Introduce la velocidad: ";
	cin >> velocidad;

	tipo_radar = toupper(tipo_radar);

	if (tipo_radar == radar_fijo){
		margen_error = error_radar_fijo;
	}
	else{
		margen_error = error_radar_movil;
	}

	if (velocidad <= tope_velocidad_error){
		velocidad_imputada = velocidad - margen_error;
	}
	else{
		error_radar = 1.0 - margen_error / 100.0;
		velocidad_imputada = velocidad * error_radar;
	}

	cout << "La velocidad imputada es " << velocidad_imputada;
}
