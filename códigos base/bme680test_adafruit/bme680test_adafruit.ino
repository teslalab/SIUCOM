/***************************************************************************
  Este código fue basado en la libreria de Adafruit para el sensor BME680
  ----> http://www.adafruit.com/products/3660

  Este sensor se puede comunicar por la interfaz I2C utilizando las direcciones de memoria 0x77 ó 0x76,
  utiliza el ESP32 como tarjeta de control.

  Escrito por Angel Isidro de Tesla Lab/Universidad Galileo.
  Código open source.
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme(&Wire); 

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println(F("BME680 test"));

  if (!bme.begin()) {
    Serial.println("No se pudo encontrar un sensor BME680 válido, revise la conexión!");
    while (1);
  }

  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
}

void loop() {
  if (! bme.performReading()) {
    Serial.println("No se pudo realizar la lectura :(");
    return;
  }
  Serial.print("Temperatura = ");
  Serial.print(bme.temperature);
  Serial.println(" *C");

  Serial.print("Presión Atmosférica = ");
  Serial.print(bme.pressure / 100.0);
  Serial.println(" hPa");

  Serial.print("Humedad = ");
  Serial.print(bme.humidity);
  Serial.println(" %");

  Serial.print("Gas = ");
  Serial.print(bme.gas_resistance / 1000.0);
  Serial.println(" KOhms");

  Serial.print("Altitud aproximada= ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.println();
  delay(2000);
}
