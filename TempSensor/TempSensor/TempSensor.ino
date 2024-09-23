#include <OneWire.h>
#include <DallasTemperature.h>

// Definir el pin al que está conectado el sensor (DQ)
#define ONE_WIRE_BUS 2  // Cambia esto si usas otro pin

// Configurar el objeto OneWire para comunicar con el sensor
OneWire oneWire(ONE_WIRE_BUS);

// Pasar la referencia de OneWire a Dallas Temperature
DallasTemperature sensors(&oneWire);

void setup() {
  // Iniciar la comunicación serie
  Serial.begin(921600);
  
  // Iniciar el sensor DS18B20
  sensors.begin();
}

void loop() {
  // Pedir al sensor que haga la lectura de temperatura
  sensors.requestTemperatures();

  // Obtener la temperatura en grados Celsius
  float temperatureC = sensors.getTempCByIndex(0);

  // Si se obtiene una lectura válida, mostrar la temperatura
  if (temperatureC != DEVICE_DISCONNECTED_C) {
    Serial.println(temperatureC);
  } else {
    Serial.println("Error: No se pudo leer la temperatura.");
  }

  // Esperar un segundo antes de la siguiente lectura
  delay(1000);
}
