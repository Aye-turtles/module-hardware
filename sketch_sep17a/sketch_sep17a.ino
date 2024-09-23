#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <MPU6050_light.h>


// Definir el pin al que está conectado el sensor (DQ)
#define ONE_WIRE_BUS 2 
#define MOISTURE_SENSOR_PIN 3
MPU6050 mpu(Wire);

// Configurar el objeto OneWire para comunicar con el sensor
OneWire oneWire(ONE_WIRE_BUS);

// Pasar la referencia de OneWire a Dallas Temperature
DallasTemperature sensors(&oneWire);

void setup() {
  // Iniciar la comunicación serie
  Serial.begin(115200);
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
  Wire.begin(1, 0); // SDA en GPIO1 y SCL en GPIO0
 if (mpu.begin() != 0) {
    Serial.println("Error al iniciar el MPU6050");
  }else{
Serial.println("MPU6050 iniciado correctamente");
  
  }

  // Iniciar el sensor DS18B20
  sensors.begin();
}

void loop() {
 mpu.update();
  
  Serial.print("Aceleración X: "); Serial.println(mpu.getAccX());
  Serial.print("Aceleración Y: "); Serial.println(mpu.getAccY());
  Serial.print("Aceleración Z: "); Serial.println(mpu.getAccZ());

  Serial.print("Giroscopio X: "); Serial.println(mpu.getGyroX());
  Serial.print("Giroscopio Y: "); Serial.println(mpu.getGyroY());
  Serial.print("Giroscopio Z: "); Serial.println(mpu.getGyroZ());


  // Pedir al sensor que haga la lectura de temperatura
  sensors.requestTemperatures();

  // Obtener la temperatura en grados Celsius
  float temperatureC = sensors.getTempCByIndex(0);
  float moisture = analogRead(MOISTURE_SENSOR_PIN);
  //Serial.println(moisture);
  //Serial.println(temperatureC);

  // Esperar un segundo antes de la siguiente lectura
  delay(1000);
}
