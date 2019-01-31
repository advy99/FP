#include <iostream>
#include <cmath>

using namespace std;

class FormateadorDoubles{
private:
   enum class SeparadorDecimal {PUNTO, COMA};
   string izda    = "";  // Valor por defecto. Se puede cambiar en el constructor pero no una vez creado el objeto
   string dcha    = "";  // Valor por defecto. Se puede cambiar en el constructor pero no una vez creado el objeto
   int decimales  = 2;   // Valor por defecto. Se puede cambiar una vez creado el objeto
   SeparadorDecimal separador = SeparadorDecimal::PUNTO;   // Valor por defecto. Se puede cambiar una vez creado el objeto

   void SetDelimitadores(string delimitador_izda, string delimitador_dcha){
      izda = delimitador_izda;
      dcha = delimitador_dcha;
   }

   // Los siguientes métodos privados podrían haberse puesto como funciones
   // globales en el caso de que tuviésemos previsto reutilizarlas en otros sitios.

   double PotenciaEntera(double base, int exponente){
   	double potencia;
   	int exponente_positivo;

   	if (base == 0 && exponente == 0)
   		potencia = NAN;				// Devuelve NAN (Indeterminación)
   	else{
   		exponente_positivo = abs(exponente);
   		potencia = 1;

   		for (int i = 1; i <= exponente_positivo; i++)
   			potencia = potencia * base;
   	}

   	if (exponente < 0)
   		potencia = 1/potencia;

   	return potencia;
   }


   double Redondea(double real, int num_decimales){
      double real_redondeado;
      long long potencia_10;

      potencia_10 = PotenciaEntera(10, num_decimales);
      real_redondeado = round(real * potencia_10);
      real_redondeado = real_redondeado / potencia_10;

      return real_redondeado;
   }

   string EliminaUltimos(string cadena, char a_borrar){
      while (! cadena.empty() && cadena.back() == a_borrar)
         cadena.pop_back();

      return cadena;
   }

public:
   FormateadorDoubles(){
   }

   FormateadorDoubles(string delimitador_izda,
                      string delimitador_dcha)
   {
      SetDelimitadores(delimitador_izda, delimitador_dcha);
   }

   FormateadorDoubles(string delimitador_izda,
                      string delimitador_dcha,
                      int num_decimales_a_mantener)
      :FormateadorDoubles(delimitador_izda, delimitador_dcha)
   {
      SetNumeroDecimales(num_decimales_a_mantener);
   }

   void SetSeparadorPunto(){
      separador = SeparadorDecimal::PUNTO;
   }
   void SetSeparadorComa(){
      separador = SeparadorDecimal::COMA;
   }

   void SetNumeroDecimales(int num_decimales_a_mantener){
      if (num_decimales_a_mantener >= 0)
         decimales = num_decimales_a_mantener;
   }

   //---------------------------------------------------------------------
   // string GetCadena(double real)
   // Transforma el real en string, redondeándolo al número de
   // cifras decimales especificado en el correspondiente dato miembro

   // 1.23  1  1.2
   // 1.23  2  1.23
   // 1.23  3  1.23
   // 1.23 20  1.23
   // 1.25  1  1.3
   // 1.25  2  1.25

   string GetCadena(double real){
      const int MAX_DIGITOS_PRECISION_DOUBLE = 15;
      int parte_entera;
      int num_digitos_precision;
      string cadena_separador;
      string cadena = "";  // No es necesario. C++ inicializa los string a ""

      if (real < 0)
         cadena = "-";

      real = abs(real);
      real = Redondea(real, decimales);
      parte_entera = trunc(real);
      cadena = cadena + to_string(parte_entera);
      num_digitos_precision = cadena.size();

      if (real != parte_entera
         && decimales > 0
         && num_digitos_precision < MAX_DIGITOS_PRECISION_DOUBLE){

         if (separador == SeparadorDecimal::PUNTO)
            cadena_separador = ".";
         else
            cadena_separador = ",";

         cadena = cadena + cadena_separador;

         for (int i = 0; i < decimales && num_digitos_precision < MAX_DIGITOS_PRECISION_DOUBLE; i++){
            real = Redondea(real - parte_entera, decimales);
            real = real * 10;
            parte_entera = trunc(real);
            cadena = cadena + to_string(parte_entera);
            num_digitos_precision++;
         }

         while (cadena.back() == '0')
            cadena.pop_back();
      }

      cadena = izda + cadena + dcha;

      return cadena;
   }
};

class Instante{
private:
   static const int SEGUNDOS_POR_MINUTO = 60,
          MINUTOS_POR_HORA = 60,
          HORAS_EN_DIA = 24;
   int hora    = -1;
   int minuto  = -1;
   int segundo = -1;

   bool EsCorrecto (int hora, int minuto, int segundo){
      return  (0 <= hora    && hora < HORAS_EN_DIA  &&
               0 <= minuto  && minuto < MINUTOS_POR_HORA &&
               0 <= segundo && segundo < SEGUNDOS_POR_MINUTO);
   }

   // segundos_a_modificar puede ser negativo
   void AniadeQuitaSegundos(int segundos_a_modificar){
      int segundos_nuevos;

      segundos_nuevos =
         SegundosTotalesEnterosTranscurridos() + segundos_a_modificar;

      SetSegundosTotalesTranscurridos(segundos_nuevos);
   }

public:
   Instante(int hora_instante, int minuto_instante, int segundo_instante){
      SetHoraMinutoSegundo(hora_instante,  minuto_instante,  segundo_instante);
   }

   Instante(int segundos_transcurridos){
      SetSegundosTotalesTranscurridos(segundos_transcurridos);
   }

   int Hora(){
      return hora;
   }

   int Minuto(){
      return minuto;
   }

   int Segundo(){
      return segundo;
   }

   void SetHoraMinutoSegundo(int hora_instante,
                             int minuto_instante,
                             int segundo_instante){
      if (EsCorrecto(hora_instante, minuto_instante, segundo_instante)){
         hora = hora_instante;
         minuto = minuto_instante;
         segundo = segundo_instante;
      }
   }

   void SetSegundosTotalesTranscurridos(int segundos_totales){
      int minutos_enteros;
      const int SEGUNDOS_EN_1_DIA = SEGUNDOS_POR_MINUTO
                                    * MINUTOS_POR_HORA
                                    * HORAS_EN_DIA;

      if (segundos_totales < SEGUNDOS_EN_1_DIA){
         segundo = segundos_totales % SEGUNDOS_POR_MINUTO;
         minutos_enteros  = segundos_totales / SEGUNDOS_POR_MINUTO;
         minuto  = minutos_enteros % MINUTOS_POR_HORA;
         hora    = minutos_enteros / MINUTOS_POR_HORA;
      }
   }

   void SumaleSegundos(int segundos_a_aniadir){
      if (segundos_a_aniadir > 0)
         AniadeQuitaSegundos(segundos_a_aniadir);
   }

   void RestaleSegundos(int segundos_a_quitar){
      if (segundos_a_quitar > 0)
         AniadeQuitaSegundos( - segundos_a_quitar);
   }

   bool EsNulo(){
      return !EsCorrecto(hora, minuto, segundo);
   }

   int SegundosTotalesEnterosTranscurridos(){
      return SEGUNDOS_POR_MINUTO * (hora * MINUTOS_POR_HORA + minuto)
             + segundo;
   }

   int MinutosTotalesEnterosTranscurridos(){
      return trunc(MinutosTotalesDecimalTranscurridos());
   }

   double MinutosTotalesDecimalTranscurridos(){
      return 1.0 * SegundosTotalesEnterosTranscurridos() / SEGUNDOS_POR_MINUTO;
   }

   double HorasTotalesDecimalTranscurridas(){
      return 1.0 * MinutosTotalesDecimalTranscurridos() / MINUTOS_POR_HORA;
   }

   string ToString(){
      return to_string(hora) + "h, " +
             to_string(minuto) + "\', " +
             to_string(segundo) + "\'\'";
   }
};


class Tunel{
private:
  static const int MAX_VEHICULOS = 100;
  double longitud_tunel;
  string matriculas[MAX_VEHICULOS];
  int entradas[MAX_VEHICULOS];
  int salidas[MAX_VEHICULOS];
  int num_vehiculos_registrados;

  int PosVehiculoPorMatricula(string matricula){
    bool encontrado = false;
    int i = 0;
    int pos_encontrado = -1;

    while(i <= num_vehiculos_registrados - 1 && !encontrado){
      if(matriculas[i] == matricula){
         pos_encontrado = i;
         encontrado = true;
      }
      i++;
    }

    return pos_encontrado;
  }
public:
   Tunel(double longitud)
      :longitud_tunel(longitud),
       num_vehiculos_registrados(0)
   {
      for(int i = 0; i < MAX_VEHICULOS; i++){
         matriculas[i] = "";
         entradas[i] = -1;
         salidas[i] = -1;
      }
   }
   void Entra(string matricula, int segundos_transcurridos){
      matriculas[num_vehiculos_registrados] = matricula;
      entradas[num_vehiculos_registrados] = segundos_transcurridos;

      num_vehiculos_registrados++;
   }
   void Sale(string matricula, int segundos_transcurridos){
      int pos_matricula;
      pos_matricula = PosVehiculoPorMatricula(matricula);


      if(pos_matricula != -1 && segundos_transcurridos >= entradas[pos_matricula])
         salidas[pos_matricula] = segundos_transcurridos;
   }
   string Matricula(int vehiculo){
      return matriculas[vehiculo];
   }
   int SegundosEnTunel(int vehiculo){
      if(salidas[vehiculo] != -1){
         return salidas[vehiculo] - entradas[vehiculo];
      }
      else{
         return -1;
      }
   }
   double Velocidad(int vehiculo){
      int segundos_en_tunel = SegundosEnTunel(vehiculo);

      if(segundos_en_tunel != -1){
         Instante tiempo_en_tunel(segundos_en_tunel);

         return longitud_tunel/tiempo_en_tunel.HorasTotalesDecimalTranscurridas();
      }
      else{
         return -1;
      }
   }
   int TotalEntradas(){
      return num_vehiculos_registrados;
   }
};


int main(){
   const char FIN_ENTRADA_FICHERO = '#';
   const char ENTRADA = 'E';
   const char SALIDA  = 'S';

   double longitud;
   char tipo_movimiento;
   string matricula;
   double velocidad;
   int total_segundos;
   int hora, minuto, segundo;

   cout << "Introduce la longitud del tunel en km: ";
   cin >> longitud;

   Tunel tunel(longitud);
   Instante nuevo_instante(0);

   cout << "Introduce el movimiento: ";
   cin >> tipo_movimiento;


   while(tipo_movimiento != FIN_ENTRADA_FICHERO){
      cout << "\nIntrouce matricula: ";
      cin >> matricula;
      cout << "\nIntroduce un instante en h m s: ";
      cin >> hora >> minuto >> segundo;

      nuevo_instante.SetHoraMinutoSegundo(hora,minuto,segundo);
      total_segundos = nuevo_instante.SegundosTotalesEnterosTranscurridos();

      if(tipo_movimiento == ENTRADA)
         tunel.Entra(matricula, total_segundos);
      if(tipo_movimiento == SALIDA)
         tunel.Sale(matricula, total_segundos);

      cout << "\nIntroduce el movimiento: ";
      cin >> tipo_movimiento;
   }

   FormateadorDoubles mostrar_velocidad("","km",1);

   for (int i = 0; i < tunel.TotalEntradas(); i++){
      cout << "\nMatricula: \t" << tunel.Matricula(i);
      cout << "\nVelocidad: \t";

      velocidad = tunel.Velocidad(i);

      if(velocidad == -1){
         cout << "No ha salido del tunel\n";
      }
      else{
         cout << mostrar_velocidad.GetCadena(velocidad) << "\n";
      }
   }

}
