#include <Servo.h>

Servo myservo;

//set portas dos botões
const int neutral = 3;
const int gear = 4;
const int conditionUp = 10;
const int conditionDown = 12;

//set dos estados dos botões
int buttonGear = 0;
int buttonStateUp = 0;
int buttonStateDown = 0;  // variable for reading the pushbutton status
int buttonNeutral = 0;
//------------------------------------------------------------------------------------

void setup() {myservo.attach(9); }

void loop() {

//variaveis ligando o estado do botão e leitura a porta;
  buttonStateUp = digitalRead(conditionUp);
  buttonStateDown = digitalRead(conditionDown);
  buttonGear = digitalRead(gear);
  buttonNeutral = digitalRead(neutral);
//---------------------------------------------------------------------------------

  if(buttonGear == LOW){
    //verifica em qual estado o botão está para baixo ou para cima;

    if (buttonStateUp == LOW){   myservo.write(140);}
    
    else if(buttonStateDown == LOW){   myservo.write(30); }
    
    // verifica se a porta 3 está ativa e o neutro liga
    else if(buttonNeutral == LOW){   myservo.write(50); }
  
    }

  // se não, volta ao estado de 90 graus
  else{  myservo.write(90);   }

//fim loop
}

