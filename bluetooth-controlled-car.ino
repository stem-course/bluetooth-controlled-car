/*
  Code by:
  M.Hashir

  This is a code for Bluetooth controlled car

  Hardware:
  Is bought from www.munphurid.com
  -Arduino UNO
  -Motor driver module L298N
  -Light weight 3 wheeler chassis
  -HC-05 Bluetooth Module
  -Li-ion cell with holder (any 7V to 12V battery will work)
  -10 male to female wires
  -5 male to male wires

  Connections:
  Motor driver module and Arduino
  -Connect IN1 of module to pin 6 of Arduino
  -Connect IN2 of module to pin 7 of Arduino
  -Connect IN3 of module to pin 8 of Arduino
  -Connect IN4 of module to pin 9 of Arduino
  -Connect ENA of module to pin 10 of Arduino
  -Connect ENB of module to pin 11 of Arduino
  -Connect 5V of module to 5V of Arduino
  -Connect GND of module to GND of Arduino

  Bluetooth module and Arduino
  -Connect RX of Bluetooth module to pin 1 = TX of Arduino
  -Connect TX of Bluetooth module to pin 0 = RX of Arduino
  -Connect VCC of Bluetooth module to 5V of Arduino
  -Connect GND of Bluetooth module to GND of Arduino

  Motors
  Connect motors to motor driver module.

  Battery and all circuits
  -Connect +ve wire of battery to 12V of motor driver module
  -Connect -ve wire of battery to GND of motor driver module
*/

#define IN1 6                          //Connect IN1 to pin 6 of Arduino
#define IN2 7                         //Connect IN2 to pin 7 of Arduino
#define ENA 10                          //Connect ENA to pin 10 of Arduino
#define ENB 11                          //Connect ENB to pin 11 of Arduino
#define IN3 8                         //Connect IN3 to pin 8 of Arduino
#define IN4 9                         //Connect IN4 to pin 9 of Arduino
int speedvariable = 255;               //range of speedvariable is 0 to 255.... you can change this value to change speed of car

void stopm(void);
void forward(void);
void right(void);
void left(void);
void backward(void);


void setup(void)
{
  Serial.begin(9600);              //Do not edit this line
  pinMode(IN1, OUTPUT);             //Do not edit this line
  pinMode(IN2, OUTPUT);             //Do not edit this line
  pinMode(IN3, OUTPUT);             //Do not edit this line
  pinMode(IN4, OUTPUT);             //Do not edit this line
  pinMode(ENA, OUTPUT);             //Do not edit this line
  pinMode(ENB, OUTPUT);             //Do not edit this line
  analogWrite(ENA, speedvariable);          //Used for speed controlling
  analogWrite(ENB, speedvariable);          //Used for speed controlling

  while (!Serial.available());
}


void loop(void) {

  int a = Serial.read();            //Receive data from Bluetooth module
  switch (a) {

    case 'F':                           //If this letter is received
      forward();                          //Move forward
      delay(200);
      break;

    case 'L':                           //If this letter is received
      left();                             //Turn left
      delay(200);
      break;

    case 'R':                           //If this letter is received
      right();                            //Turn right
      delay(200);
      break;

    case 'B':                           //If this letter is received
      backward();                         //Move forward
      delay(200);
      break;

    default:
      stopm();                            //If nothing is pressed then stop
      delay(200);

  }
  a = 0;
}



void forward(void)                  //The four lines below tell your car how to move forward... you can edit them
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}


void left(void)                     //The four lines below tell your car how to turn left.... you can edit them
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}



void right(void)                    //The four lines below tell your car how to turn right.... you can edit them
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}


void stopm(void)                    //The four lines below tell your car how to stop.... you can edit them
{

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}
void backward(void)            //The four lines below tell your car how to go backward.... you can edit them
{

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
