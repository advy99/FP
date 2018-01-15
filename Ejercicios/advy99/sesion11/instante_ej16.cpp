#include <iostream>

using namespace std;

const int HORAS_EN_DIA = 24;
const int MINUTOS_EN_HORA = 60;
const int SEGUNDOS_EN_MINUTO = 60;

int LeerIntRango(int minimo, int maximo){
   int dato;
   do{
      cin >> dato;
   }while( dato < minimo || dato > maximo );

   return dato;
}
int ValorAbsoluto(int dato){
   if (dato > 0)
      return dato;
   else
      return -dato;
}

class Instante{
private:
   int horas;
   int minutos;
   int segundos;
   int segundos_desde_instante;
   int minutos_desde_instante;

   bool ValidarDatoEnRango(int dato, int minimo, int maximo){
      if (dato >= minimo && dato <= maximo)
         return true;
      else
         return false;
   }

public:
   Instante()
      :horas(0),
       minutos(0),
       segundos(0)
   {
   }
   Instante(int segundos_iniciales){
      horas = segundos_iniciales / 3600;
      segundos_iniciales = segundos_iniciales - (horas * 3600);
      minutos = segundos_iniciales / 60;
      segundos = segundos_iniciales % 60;
   }
   void SetHoras(int nueva_hora){
      if (ValidarDatoEnRango(nueva_hora, 0, HORAS_EN_DIA - 1))
         horas = nueva_hora;
   }
   void SetMinutos(int nuevos_minutos){
      if (ValidarDatoEnRango(nuevos_minutos, 0, MINUTOS_EN_HORA - 1))
         minutos = nuevos_minutos;
   }
   void SetSegundos(int nuevos_segundos){
      if (ValidarDatoEnRango(nuevos_segundos, 0, SEGUNDOS_EN_MINUTO - 1))
         segundos = nuevos_segundos;
   }
   int MinutosTranscurridos(){
      return horas * 60 + minutos;
   }
   int SegundosTranscurridos(){
      return MinutosTranscurridos() * 60 + segundos;
   }

   int Horas(){
      return horas;
   }
   int Minutos(){
      return minutos;
   }
   int Segundos(){
      return segundos;
   }
};

int main(){
   Instante instante_inicial, instante_final, instante_diferencia, nuevo_instante(3721);
   int diferencia_horas, diferencia_minutos, diferencia_segundos;

   instante_inicial.SetHoras( LeerIntRango(0,HORAS_EN_DIA - 1 ) );
   instante_inicial.SetMinutos( LeerIntRango(0,MINUTOS_EN_HORA - 1 ) );
   instante_inicial.SetSegundos( LeerIntRango(0,SEGUNDOS_EN_MINUTO - 1) );

   instante_final.SetHoras( LeerIntRango(0,HORAS_EN_DIA - 1) );
   instante_final.SetMinutos( LeerIntRango(0,MINUTOS_EN_HORA - 1) );
   instante_final.SetSegundos( LeerIntRango(0,SEGUNDOS_EN_MINUTO - 1) );


   diferencia_horas = instante_final.Horas() - instante_inicial.Horas() ;
   diferencia_horas = ValorAbsoluto( diferencia_horas );

   diferencia_minutos = instante_final.Minutos() - instante_inicial.Minutos() ;
   diferencia_minutos = ValorAbsoluto( diferencia_minutos );

   diferencia_segundos = instante_final.Segundos() - instante_inicial.Segundos() ;
   diferencia_segundos = ValorAbsoluto( diferencia_segundos );

   instante_diferencia.SetHoras( diferencia_horas );
   instante_diferencia.SetMinutos( diferencia_minutos );
   instante_diferencia.SetSegundos( diferencia_segundos );

   cout << "\nDiferencia: " << instante_diferencia.Horas() << "h "
        << instante_diferencia.Minutos() << "´ " << instante_diferencia.Segundos() << "´´";

   cout << "\nSegundos desde el 0:0:0 hasta el instante inicial: " << instante_inicial.SegundosTranscurridos();
   cout << "\nMinutos desde el 0:0:0 hasta el instante inicial: " << instante_inicial.MinutosTranscurridos();


   cout << "\nNuevo instante: " << nuevo_instante.Horas() << "h "
        << nuevo_instante.Minutos() << "´ " << nuevo_instante.Segundos() << "´´";
}
