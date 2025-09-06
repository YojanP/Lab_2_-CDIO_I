/*
Ultrasonic sensor HC-SR04:
VCC: +5VDC
Trig: Pin 11
Echo: Pin 12
GND: GND
*/

int trigPin = 11;
int echoPin = 12;
int pulsador = 5;
int led1 = 3;   // PWM pin
int led2 = 6;  // PWM pin
int led3 = 9;   // PWM pin

long duration, cm;

unsigned long tiempoinicio = 0;
unsigned long tiempofin = 0;
float tiempopulsado = 0;  

bool ledEncendido = false;

void setup() {
  Serial.begin(9600);
  pinMode(pulsador, INPUT_PULLUP); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  analogWrite(led1, LOW);
  analogWrite(led2, LOW);
  analogWrite(led3, LOW);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  cm = (duration / 2.0) / 29.1;

  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.println(" cm");

  if (cm < 30) {
    analogWrite(led1, 250);   // brillo alto
    if (ledEncendido == false){
      tiempoinicio = millis(); 
      ledEncendido = true; }
  }

  if (cm >= 30 && cm <= 90) {
    analogWrite(led2, 120);   // brillo medio
    if (ledEncendido == false){
      tiempoinicio = millis(); 
      ledEncendido = true; }
  }

  if (cm > 90 && cm <= 120) {
    analogWrite(led3, 30);    // brillo bajo
    if (ledEncendido == false){
      tiempoinicio = millis(); 
      ledEncendido = true; }
  }
  

  // --- Revisar pulsador ---
  if (digitalRead(pulsador) == LOW) { 
    tiempofin = millis();
    tiempopulsado = (tiempofin - tiempoinicio) / 1000; 

    // Apaga LEDs
    analogWrite(led1, LOW);
    analogWrite(led2, LOW);
    analogWrite(led3, LOW);

    Serial.print("Tiempo transcurrido: ");
    Serial.print(tiempopulsado);
    Serial.println(" segundos");

    ledEncendido = false;
    delay(500); 
  }

  delay(200);
}
