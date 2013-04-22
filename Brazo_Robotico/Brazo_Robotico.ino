/* Brazo Robotico and stuff... */
#include <Wire.h>
#include <DCMotor.h>
#include <nuchuck_funcs.h>
#include "funciones.h"


/* Motores y Nunchuck */
struct Nunchuck N; //mi nunchuck
#define DEADZONE 3 //zona muerta para los joysticks y acelerometros.

DCMotor M0(2,3);
DCMotor M1(4,5);
DCMotor M2(6,7);
DCMotor M3(8,9);
DCMotor M4(10,11);

void control_motor(DCMotor X, DCMotor Y,   DCMotor N1, DCMotor N2, DCMotor N3, DCMotor N4) {  
  //motor para X, motor para Y, motores que no se usan...
  N1.stop(); N2.stop(); N3.stop(); N4.stop();
  //motor en X y motor en Y
  if ( N.Joy.X <= -DEADZONE ) { 
      X.inverse(); 
    } 
    else if ( N.Joy.X >= DEADZONE ) { 
      X.regular(); 
    }  else { 
      X.stop(); 
    }
    
  if ( N.Joy.Y <= -DEADZONE ) { 
      Y.inverse(); 
    } 
    else if ( N.Joy.Y >= DEADZONE ) { 
      Y.regular(); 
    }  else { 
      Y.stop(); 
    }
    
     
 
}


void manejo_con_joystick( ) {  
 if ( N.But.C ) {
   //button C presionado mover pinzas solamente.
   control_motor(M4, M4,   M3,M2,M1,M0);       
  } else if  ( N.But.Z ) {
    //button Z presionado mover los 2 secundarios.  
    control_motor(M2,M3,  M0,M1,M4,M4);
 } else  {
   //mover los 2 principales 
   control_motor(M0,M1,  M2,M3,M4,M4);   
 }

}

void setup () {

    Serial.begin(19200);
    nunchuck_setpowerpins();
    nunchuck_init(); // send the initilization handshake       
}

void loop () {
  
  //obtener data e imprimirla:
  nunchuck_get_data();
  N = get_variables(); 
  print_variables(N);

  //manejo con joystick:
  manejo_con_joystick();
    
  delay(1); //esperar para estabilidad.
  
}
