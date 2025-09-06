int irSensor = 7;           // Pin del sensor
int estadoActual = HIGH;
int estadoAnterior = HIGH;
int contadorEventos = 0;
bool objetoPresente = false;

void setup() {
  Serial.begin(9600);
  pinMode(irSensor, INPUT);
}

void loop() {
  estadoActual = digitalRead(irSensor);

  // Detecta cuando hay un obstáculo
  if (estadoActual == LOW && !objetoPresente) {
    objetoPresente = true;
  }

  // Detecta cuando no hay obstáculoe
  if (estadoActual == HIGH && objetoPresente) {
    objetoPresente = false;
    contadorEventos++; // Suma al contador
    Serial.print("Cambio detectado. Total eventos: ");
    Serial.println(contadorEventos);
  }

  estadoAnterior = estadoActual; // actualizar para la siguiente lectura
  delay(50); // Anti-rebote
}
