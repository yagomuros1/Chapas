//  Yago
//  Siguelineas
//git
#define rapidez 160
#define rapidez_giro_delante 200
#define rapidez_giro_atras 200
#define PIN_LDR_IZQUIERDO 5
#define PIN_LDR_DERECHO 0
#define PIN_LDR_CENTRO 2
#define pin_motor_izquierdo_delante 3
#define pin_motor_izquierdo_detras 5
#define pin_motor_derecho_delante 6
#define pin_motor_derecho_detras 10
int derecha =   0; 
int izquierda = 0;
int origenDer = 0;
int origenIzq = 0;
int umbral_izq_blanco = 0;
int umbral_derecha_blanco = 0;
int umbral_izq_negro = 0;
int umbral_derecha_negro = 0;
int umbral_blanco = 0 ; 
int umbral_negro = 0;
float umbral = 0 ; 



void setup() 
{ 
  Serial.begin(9600);
delay(500);
  
 origenIzq = analogRead(PIN_LDR_IZQUIERDO);
  
 origenDer = analogRead(PIN_LDR_DERECHO);

delay (2000);
                        //blanco
 umbral_izq_blanco = analogRead (PIN_LDR_IZQUIERDO);
 umbral_derecha_blanco = analogRead (PIN_LDR_DERECHO);
 umbral_blanco = (umbral_izq_blanco + umbral_derecha_blanco) / 2 ;

 delay (2000);

                //negro
 umbral_izq_negro = analogRead (PIN_LDR_IZQUIERDO);
 umbral_derecha_negro = analogRead (PIN_LDR_DERECHO);   
 umbral_negro = (umbral_izq_negro + umbral_derecha_negro) / 2 ;

 delay (2000);

 umbral = (umbral_blanco - umbral_negro) * 0.6 ;
            
 
  Serial.print("origen izq ");
  Serial.println(origenIzq);
  Serial.print("origen Der ");
  Serial.println(origenDer);
  delay(2000);
} 
 
 
void loop() 
{ 
  derecha = (analogRead(PIN_LDR_DERECHO) + analogRead(PIN_LDR_DERECHO)) / 2; 
  izquierda = (analogRead(PIN_LDR_IZQUIERDO) + analogRead(PIN_LDR_IZQUIERDO) ) /2;
  Serial.print("Izquierda ");
  Serial.println(izquierda);
  Serial.print("Derecha ");
  Serial.println(derecha);
  if (origenDer - derecha > umbral) 
  {
    giro_derecha () ;
    Serial.println("Gira a la derecha");
  }
  else if (origenIzq - izquierda > umbral)
  {
    giro_izquierda () ;
    Serial.println("Gira a la izquierda");
  }
  else
  {
    avanzar () ;
    Serial.println("sigue de frente");
  }
  delay(10); 
} 

void avanzar ()
{
  // digitalWrite (pin_motor_izquierdo_delante,HIGH);
 // digitalWrite (pin_motor_derecho_delante,HIGH);
 // delay(5);
  analogWrite (pin_motor_izquierdo_delante,rapidez);
  analogWrite (pin_motor_derecho_delante,rapidez);
  digitalWrite (pin_motor_izquierdo_detras,LOW);
  digitalWrite (pin_motor_derecho_detras,LOW);
  
}

void retroceder () 
{
  digitalWrite (pin_motor_izquierdo_delante,LOW);
  digitalWrite (pin_motor_derecho_delante,LOW);
  analogWrite (pin_motor_izquierdo_detras,rapidez);
  analogWrite (pin_motor_derecho_detras,rapidez);
}

void giro_izquierda ()
{
  digitalWrite (pin_motor_izquierdo_delante,LOW);
  analogWrite (pin_motor_derecho_delante,rapidez_giro_delante);
  analogWrite (pin_motor_izquierdo_detras,rapidez_giro_atras);
  digitalWrite (pin_motor_derecho_detras,LOW);
}

void giro_derecha ()
{
  analogWrite (pin_motor_izquierdo_delante,rapidez_giro_delante);
  digitalWrite (pin_motor_derecho_delante,LOW);
  digitalWrite (pin_motor_izquierdo_detras,LOW);
  analogWrite (pin_motor_derecho_detras,rapidez_giro_atras);
}

void detener ()
{
  digitalWrite (pin_motor_izquierdo_delante,LOW);
  digitalWrite (pin_motor_derecho_delante,LOW);
  digitalWrite (pin_motor_izquierdo_detras,HIGH);
  delay(10);
  digitalWrite (pin_motor_derecho_detras,HIGH);
  delay(10);
}
