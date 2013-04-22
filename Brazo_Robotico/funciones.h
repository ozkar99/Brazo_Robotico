/* funciones que expanden la libreria de nunchuck_funcs originales */

//struct para el joystick, acelerometro y botones:
struct Joystick {
 int X;
 int Y; 
};
   
struct Accelerometer {
  int X;
  int Y;
  int Z;
}; 

struct Buttons{
  int C;
  int Z;
};

//struct principal:
struct Nunchuck {
   struct Joystick Joy;
   struct Accelerometer Acc;
   struct Buttons But;
};

//int accx,accy,zbut,cbut,joyx,joyy; //variables globales.
//accelerometro x,y; butones z,c; joystick x,y;

struct Nunchuck get_variables() {
   struct Nunchuck n;
   n.Joy.X = map(nunchuck_joyx(), 40, 225, -10, 10); 
   n.Joy.Y = map(nunchuck_joyy(), 40, 225, -10, 10);

   n.Acc.X = map(nunchuck_accelx(), 70, 182, -10, 10);
   n.Acc.Y = map(nunchuck_accely(), 65, 173, -10, 10);
   n.Acc.Z = map(nunchuck_accelz(), 70, 180, -10, 10); //no se usa.

   n.But.Z = nunchuck_zbutton(); //0: off, 1: on
   n.But.C = nunchuck_cbutton();//0: off, 1: on
   return n;  
}

void print_variables(struct Nunchuck n) {
  //joystick:
 Serial.print("joyx: "); Serial.print(n.Joy.X);
 Serial.print("\tjoyy: ");Serial.print(n.Joy.Y);
 //buttons:
 Serial.print("\tzbut: ");Serial.print(n.But.Z);
 Serial.print("\tcbut: ");Serial.print(n.But.C);
 //accelerometer:
 Serial.print("\taccx: ");Serial.print(n.Acc.X);
 Serial.print("\taccy: ");Serial.print(n.Acc.Y);
 Serial.print("\taccz: ");Serial.print(n.Acc.Z);
 Serial.println(); //new line
 }
 

