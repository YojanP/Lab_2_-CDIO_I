/*
Ultrasonic sensor Pins:

VCC: +5VDC

Pinil Trig: Trigger (INPUT)

Echo: Echo (OUTPUT) Pin 12

GND: GND

*/


int trigPin = 11;
int echoPin = 12;
int pulsador = 7;
int led1 = 3;
int led2 = 6;
int led3 = 8;

long duration, cm;

unsigned long tiempoinicio = 0;
unsigned long tiempofin = 0;
float tiempopulsado = 0;  


bool ledEncendido = false;  


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pulsador, INPUT_PULLUP); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); 
  cm = (duration / 2.0) / 29.1;

  
  if (cm > 60) {
    digitalWrite(led1, HIGH);
  }
  
  if (cm >= 20 && cm <= 60) {
    digitalWrite(led2, HIGH);
  } 
  
  if (cm < 20) {
    digitalWrite(led3, HIGH);
  }
  
  if (ledEncendido == false && (digitalRead(led1) == HIGH || digitalRead(led2) == HIGH || digitalRead(led3) == HIGH)) {
    tiempoinicio = millis();
    ledEncendido = true;
  }

  //  Revisar pulsador
  if (digitalRead(pulsador) == LOW) { 
    tiempofin = millis();
    tiempopulsado = (tiempofin - tiempoinicio) / 1000; 

    // Apaga LEDs
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    Serial.print("Tiempo transcurrido: ");
    Serial.print(tiempopulsado);
    Serial.println(" segundos");

    ledEncendido = false; 
    delay(500); 
  }

  delay(200);
}