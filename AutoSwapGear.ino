#include <Servo.h>

Servo myservo;

//set portas dos botões
const int neutral = 10;
const int gear = 9;
const int conditionUp = 12;
const int conditionDown = 11;

//set dos estados dos botões
int buttonGear = 1;
int buttonStateUp = 0;
int buttonStateDown = 0;  // variable for reading the pushbutton status
int buttonNeutral = 0;
//------------------------------------------------------------------------------------

void setup() {myservo.attach(8); }

void loop() {

//variaveis ligando o estado do botão e leitura a porta;
  buttonStateUp = digitalRead(conditionUp);
  buttonStateDown = digitalRead(conditionDown);
  buttonGear = digitalRead(gear);
  buttonNeutral = digitalRead(neutral);
//---------------------------------------------------------------------------------

  if(buttonGear == LOW){delay(0);
    
    //verifica em qual estado o botão está para baixo ou para cima;

    if (buttonStateUp == LOW){   myservo.write(140); }
    
    else if(buttonStateDown == LOW){   myservo.write(30); }
    
    // verifica se a porta 3 está ativa e o neutro liga
    else if(buttonNeutral == LOW){   myservo.write(60); }
  
    }

  // se não, volta ao estado de 90 graus
  else{  myservo.write(90);   }

//fim loop
}

