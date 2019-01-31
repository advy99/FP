#include <iostream>

using namespace std;

double LeerDoubleEnIntervalo(double minimo, double maximo){
   double valor;

   do{
      cin >> valor;
   }while (valor < minimo || valor > maximo);

   return valor;
}

class CalificacionFinal{
private:
   double nota_ev_continua;
   double nota_ex_practicas_1;
   double nota_ex_practicas_2;
   double nota_ex_escrito;
   double subida_por_grupo;

   bool NotaCorrecta(double nota){
      if (nota >= 0 && nota <= 10)
         return true;
      else
         return false;
   }

public:
   CalificacionFinal(double subida){
      if(subida >= 0 && subida <= 0.5)
         subida_por_grupo = subida;
   }

   double CalcularNotaFinal(int porcentaje_continua, int porcentaje_pract1, int porcentaje_pract2, int porcentaje_escrito, double nota_limite){
      double parte_continua, parte_pract1, parte_pract2, parte_escrita, nota_final;

      if((nota_ex_escrito + subida_por_grupo) >= 5)
         nota_ex_escrito = nota_ex_escrito + subida_por_grupo;
      if(nota_ex_escrito < nota_limite){
         nota_final = nota_ex_escrito;
      }
      else{
         parte_continua = nota_ev_continua * porcentaje_continua / 100.0;
         parte_pract1 = nota_ex_practicas_1 * porcentaje_pract1 / 100.0;
         parte_pract2 = nota_ex_practicas_2 * porcentaje_pract2 / 100.0;
         parte_escrita = nota_ex_escrito * porcentaje_escrito / 100.0;

         nota_final = parte_continua + parte_pract1 + parte_pract2 + parte_escrita;
      }

      return nota_final;
   }

   void SetNotaEvContinua(double nueva_nota){
      if(nueva_nota <= 10 && nueva_nota >= 0)
         nota_ev_continua = nueva_nota;
   }
   void SetNotaExPracticas1(double nueva_nota){
      if(nueva_nota <= 10 && nueva_nota >= 0)
         nota_ex_practicas_1 = nueva_nota;
   }
   void SetNotaExPracticas2(double nueva_nota){
      if(nueva_nota <= 10 && nueva_nota >= 0)
         nota_ex_practicas_2 = nueva_nota;
   }
   void SetNotaExEscrito(double nueva_nota){
      if(nueva_nota <= 10 && nueva_nota >= 0)
         nota_ex_escrito = nueva_nota;
   }
};

int main(){
   double subida_por_grupo, nota_continua, nota_pract1, nota_pract2, nota_escrito;
   int contador = 0;


   subida_por_grupo = LeerDoubleEnIntervalo(-1,0.5);

   while(subida_por_grupo >= 0){
      CalificacionFinal nuevo_grupo(subida_por_grupo);

      nota_continua = LeerDoubleEnIntervalo(-1,10);

      while(nota_continua >= 0){
         nuevo_grupo.SetNotaEvContinua(nota_continua);

         nota_pract1 = LeerDoubleEnIntervalo(0,10);
         nuevo_grupo.SetNotaExPracticas1(nota_pract1);

         nota_pract2 = LeerDoubleEnIntervalo(0,10);
         nuevo_grupo.SetNotaExPracticas2(nota_pract2);

         nota_escrito = LeerDoubleEnIntervalo(0,10);
         nuevo_grupo.SetNotaExEscrito(nota_escrito);

         cout << nuevo_grupo.CalcularNotaFinal(10,10,20,60,4) << "/" << nuevo_grupo.CalcularNotaFinal(5,5,20,70,4.4) ;
         cout << "\n";

         nota_continua = LeerDoubleEnIntervalo(-1,10);

      }
      cout << "\n------------------------------------------------------\n";

      subida_por_grupo = LeerDoubleEnIntervalo(-1,0.5);
   }

}
