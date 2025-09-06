/* 
Reto: Ultrasonico + Infrarrojo
Conexiones:
HC-SR04:
  VCC  -> 5V
  GND  -> GND
  Trig -> Pin 11
  Echo -> Pin 12

Sensor IR (digital):
  VCC  -> 5V
  GND  -> GND
  OUT  -> Pin 7
*/

int trigPin = 11;
int echoPin = 12;
int irPin   = 7;   // salida digital del sensor infrarrojo

long duracion;
float distancia;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin, INPUT);  
}

void loop() {
  int irValor = digitalRead(irPin);

  if (irValor == LOW) {  
    // Activar el sensor ultrasónico
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Medir duración del pulso de eco
    duracion = pulseIn(echoPin, HIGH); 

    // Convertir duración a distancia en cm
    distancia = (duracion / 2.0) / 29.1;

    Serial.print("Distancia detectada: ");
    Serial.print(distancia);
    Serial.println(" cm");
  } 

  delay(500); // Retardo entre mediciones
}
