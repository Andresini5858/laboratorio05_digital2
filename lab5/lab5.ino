//Andrés Lemus

//definir numero de pines
#define LED1_J1 2
#define LED2_J1 3
#define LED3_J1 4
#define LED4_J1 5
#define LED5_J1 6
#define LED6_J1 7
#define LED7_J1 8
#define LED8_J1 9
#define LEDW_J1 38

#define LED1_J2 23
#define LED2_J2 24
#define LED3_J2 25
#define LED4_J2 26
#define LED5_J2 27
#define LED6_J2 28
#define LED7_J2 29
#define LED8_J2 10
#define LEDW_J2 37

#define RES 36

//declaración de variables
int etapa; //variable para definir la etapa del juego
int cont1; //contador para jugador 1
int cont2; //contaador para jugador 2
int bandera; //bandera para antirrebotes

void setup() {
  etapa = 0; //Inicializar en etapa 0
  cont1 = 0; //Iniciar en 0 contador 1
  cont2 = 0; //Iniciar en 0 contador 2
  bandera = 0; //Iniciar en 0 bandera

  pinMode(RES, INPUT_PULLUP); //definir botón de reset con pullup interno
  
  pinMode(PUSH1, INPUT_PULLUP); //definir botón de jugador 1 con pull-up interno
  pinMode(PUSH2, INPUT_PULLUP); //definir botón de jugador 2 con pull-up interno

  attachInterrupt(digitalPinToInterrupt(PUSH1), boton1, LOW); //asignar interrupción a botón de jugador 1 cuando el pin esté en bajo
  attachInterrupt(digitalPinToInterrupt(PUSH2), boton2, LOW); //asignar interrupción a botón de jugador 2 cuando el pin esté en bajo
  attachInterrupt(digitalPinToInterrupt(RES), res, LOW); //asignar interrupción a botón de reset cuando el pin esté en bajo

  //asignar leds como salidas
  pinMode(RED_LED, OUTPUT); 
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  pinMode(LEDW_J1, OUTPUT);
  pinMode(LEDW_J2, OUTPUT);
  
  pinMode(LED1_J1, OUTPUT);
  pinMode(LED2_J1, OUTPUT);
  pinMode(LED3_J1, OUTPUT);
  pinMode(LED4_J1, OUTPUT);
  pinMode(LED5_J1, OUTPUT);
  pinMode(LED6_J1, OUTPUT);
  pinMode(LED7_J1, OUTPUT);
  pinMode(LED8_J1, OUTPUT);

  pinMode(LED1_J2, OUTPUT);
  pinMode(LED2_J2, OUTPUT);
  pinMode(LED3_J2, OUTPUT);
  pinMode(LED4_J2, OUTPUT);
  pinMode(LED5_J2, OUTPUT);
  pinMode(LED6_J2, OUTPUT);
  pinMode(LED7_J2, OUTPUT);
  pinMode(LED8_J2, OUTPUT);
}

//Función de reset
void res(){
  etapa = 0; //etapa en 0 
  cont1 = 0; //reiniciar contador 1
  cont2 = 0; //reiniciar contador 2
  
  //apagar todos los leds
  digitalWrite(LED1_J1, LOW);
  digitalWrite(LED2_J1, LOW);
  digitalWrite(LED3_J1, LOW);
  digitalWrite(LED4_J1, LOW);
  digitalWrite(LED5_J1, LOW);
  digitalWrite(LED6_J1, LOW);
  digitalWrite(LED7_J1, LOW);
  digitalWrite(LED8_J1, LOW);
  digitalWrite(LEDW_J1, LOW);

  digitalWrite(LED1_J2, LOW);
  digitalWrite(LED2_J2, LOW);
  digitalWrite(LED3_J2, LOW);
  digitalWrite(LED4_J2, LOW);
  digitalWrite(LED5_J2, LOW);
  digitalWrite(LED6_J2, LOW);
  digitalWrite(LED7_J2, LOW);
  digitalWrite(LED8_J2, LOW);
  digitalWrite(LEDW_J2, LOW);
}

void loop() {
  //Etapa 0 (Semáforo de Inicialización)
  while(etapa == 0){
    detachInterrupt(digitalPinToInterrupt(PUSH1)); //Deshabilitar interrupción de botón del jugador 1
    detachInterrupt(digitalPinToInterrupt(PUSH2)); //Deshabilitar interrupción de botón del jugador 2
    //Iniciar secuencia
    //Color ROJO
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    delay(1000); //delay de 1s
    //Color AMARILLO
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    delay(1000); //delay de 1s
    //Color VERDE
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(1000); //delay de 1s
    etapa = 1; //Cambio de etapa
  }
  //Etapa 1 (Jugando)
  while(etapa == 1){
    attachInterrupt(digitalPinToInterrupt(PUSH1), boton1, LOW); //Habilitar interrupción al jugador 1
    attachInterrupt(digitalPinToInterrupt(PUSH2), boton2, LOW); //Habilitar interrupción al jugador 2
  }

  while (etapa == 2){
     //Etapa 2 (Ganador)
    detachInterrupt(digitalPinToInterrupt(PUSH1)); //Deshabilitar interrupción de botón del jugador 1
    detachInterrupt(digitalPinToInterrupt(PUSH2)); //Deshabilitar interrupción de botón del jugador 2
  }
}

//Función de interrupción del botón del jugador 2
void boton2(){
  delay(5); //delay mínimo
  bandera = 2; //encender bandera para antirrebote
  if (digitalRead(PUSH2) == HIGH && bandera == 2){ //Si ya se soltó el botón, ejecutar
    if (cont2 == 0){
      //Leds si contador en 0
      digitalWrite(LED1_J2, HIGH);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(LEDW_J2, LOW);
      cont2 = 1; //Aumentar contador
    }
    else if (cont2 == 1){
      //Leds si contador en 1
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, HIGH);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(LEDW_J2, LOW);
      cont2 = 2; //Aumentar contador
    }
    else if (cont2 == 2){
      //Leds si contador en 2
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, HIGH);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(LEDW_J2, LOW);
      cont2 = 3; //Aumentar contador
    }
    else if (cont2 == 3){
      //Leds si contador en 3
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, HIGH);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(LEDW_J2, LOW);
      cont2 = 4; //Aumentar contador
    }
    else if (cont2 == 4){
      //Leds si contador en 4
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, HIGH);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(LEDW_J2, LOW);
      cont2 = 5; //Aumentar contador
    }
    else if (cont2 == 5){
      //Leds si contador en 5
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, HIGH);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(LEDW_J2, LOW);
      cont2 = 6; //Aumentar contador
    }
    else if (cont2 == 6){
      //Leds si contador en 6
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, HIGH);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(LEDW_J2, LOW);
      cont2 = 7; //Aumentar contador
    }
    else if (cont2 == 7){
      //Leds si contador en 7
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, HIGH);
      digitalWrite(LEDW_J2, LOW);
      cont2 = 8; //Aumentar contador
    }
    else if (cont2 == 8){ //Aumentar contador
      //Leds si contador en 8
      digitalWrite(LED1_J2, LOW);
      digitalWrite(LED2_J2, LOW);
      digitalWrite(LED3_J2, LOW);
      digitalWrite(LED4_J2, LOW);
      digitalWrite(LED5_J2, LOW);
      digitalWrite(LED6_J2, LOW);
      digitalWrite(LED7_J2, LOW);
      digitalWrite(LED8_J2, LOW);
      digitalWrite(LEDW_J2, HIGH);  
      etapa = 2; //Ganó, entonces cambiar etapa
      }
      bandera = 0; //Limpiar bandera
    }
  }
  
//Función de interrupción del botón del jugador 1
void boton1(){
  delay(5); //delay de 5ms
  bandera = 1; //Encender
  if (digitalRead(PUSH1) == HIGH && bandera == 1){ //Si ya se soltó el botón, ejecutar
    if (cont1 == 0){
      //Leds si contador en 0
      digitalWrite(LED1_J1, HIGH);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(LEDW_J1, LOW);
      cont1 = 1; //Aumentar contador
    }
    else if (cont1 == 1){
      //Leds si contador en 1
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, HIGH);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(LEDW_J1, LOW);
      cont1 = 2; //Aumentar contador
    }
    else if (cont1 == 2){
      //Leds si contador en 2
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, HIGH);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(LEDW_J1, LOW);
      cont1 = 3; //Aumentar contador
    }
    else if (cont1 == 3){
      //Leds si contador en 3
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, HIGH);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(LEDW_J1, LOW);
      cont1 = 4; //Aumentar contador
    }
    else if (cont1 == 4){
      //Leds si contador en 4
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, HIGH);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(LEDW_J1, LOW);
      cont1 = 5; //Aumentar contador
    }
    else if (cont1 == 5){
      //Leds si contador en 5
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, HIGH);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(LEDW_J1, LOW);
      cont1 = 6; //Aumentar contador
    }
    else if (cont1 == 6){
      //Leds si contador en 6
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, HIGH);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(LEDW_J1, LOW);
      cont1 = 7; //Aumentar contador
    }
    else if (cont1 == 7){
      //Leds si contador en 7
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, HIGH);
      digitalWrite(LEDW_J1, LOW);
      cont1 = 8; //Aumentar contador
    }
    else if (cont1 == 8){
      //Leds si contador en 8
      digitalWrite(LED1_J1, LOW);
      digitalWrite(LED2_J1, LOW);
      digitalWrite(LED3_J1, LOW);
      digitalWrite(LED4_J1, LOW);
      digitalWrite(LED5_J1, LOW);
      digitalWrite(LED6_J1, LOW);
      digitalWrite(LED7_J1, LOW);
      digitalWrite(LED8_J1, LOW);
      digitalWrite(LEDW_J1, HIGH);
      etapa = 2; //Ganó, entonces cambiar etapa
      }
      bandera = 0; //Lipiar bandera
    }
  }
