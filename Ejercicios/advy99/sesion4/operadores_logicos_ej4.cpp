/*
Caso a)

   char tipo_radar;
   cin >> tipo_radar;

   if (tipo_radar == 'F' && tipo_radar == 'f')

      Nunca se van a dar ambos casos, o es mayuscula o minuscula, por lo que el
      bloque nunca se ejecutara


Caso b)
   double velocidad;
   cin >> velocidad;
   if (velocidad > 100 && velocidad < 70)
      cout << "\nVelocidad fuera del rango";

      Un valor nunca puede cumplir esta condicion, ya que si algo es mayor que
      100 nunca es menor que 70, y viceversa, habria que usar el operador || (o)

Caso c)
   double velocidad;
   cin >> velocidad;
   if (velocidad > 100 || velocidad > 110)
      cout << "Velocidad excesiva";

      Se esta repitiendo la condicion, si la velocidad es mayor que 110, da
      igual la primera condicion, ya que tambien es mayor que 100, y si la
      velocidad no llega a 100 pero si es mayor que 100 tambien se ejecuta,
      porque se cumple la primera condicion al estar usando el operador ||,
      poner
          if (velocidad > 100)
      tendria el mismo efecto
*/
