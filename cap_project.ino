#include <dht11.h>
#include <Servo.h>
Servo myservo;
#define DHT11PIN 9 //dht
 
#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 7
int frequency = 0;

dht11 DHT11;

void  setup()
{
  myservo.attach(10);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  myservo.write(-90);
  

 
}

void loop()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  DHT11.temperature = 28.5;

  Serial.print("Temperature  (C): ");
  Serial.println((float)DHT11.temperature, 2);
  if (DHT11.temperature >= 25){
    digitalWrite(8, HIGH);
  }
  if (DHT11.temperature < 25){
    digitalWrite(8, LOW);
  }
  if (DHT11.temperature < 20){
    digitalWrite(11, HIGH);
  }
  if (DHT11.temperature >= 20){
    digitalWrite(11, LOW);
  }

  delay(2000);
  

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 30,90,255,0);
  frequency = 580;
  // Printing the value on the serial monitor
  Serial.print("Wavelength= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  if (frequency < 590){
    myservo.write(180);
  }
  if (frequency >= 590){
    myservo.write(-180);
  }
  delay(100);
 
  delay(100);

}
