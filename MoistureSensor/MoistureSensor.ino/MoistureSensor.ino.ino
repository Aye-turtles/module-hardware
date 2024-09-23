// Definir el pin donde está conectado el sensor de humedad
#define MOISTURE_SENSOR_PIN 3  // Cambia si usas otro pin analógico

// Para el ESP32-C3 el rango ADC es de 0 a 4095
void setup() {
  // Iniciar comunicación serial
  Serial.begin(115200);

  // Configurar el pin del sensor de humedad como entrada
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
}

void loop() {
  // Leer el valor analógico del sensor
  float sensorValue = analogRead(MOISTURE_SENSOR_PIN);
  Serial.println(sensorValue);

  // Esperar 1 segundo antes de la siguiente lectura
  delay(1000);
}
