int irSensor = 7;  

void setup() {
  Serial.begin(9600);       // Iniciar comunicación serie
  pinMode(irSensor, INPUT); // Configurar el pin como entrada
}

void loop() {
  int estado = digitalRead(irSensor); // Leer estado del sensor

  if (estado == LOW) {
    Serial.println("Obstaculo detectado");
  } else {
    Serial.println("No hay obstaculo");
  }

  delay(200);
}
