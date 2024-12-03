# SIUCOM - BME680 

Este es un sensor creado por el fabricante de dispositivos electronicos BOSCH, es capas de hacer lecturas ambientales en un pequeño empaquetado. Este pequeño sensor tiene la capacidad de leer las siguientes variables:
- Temperatura
- Humedad 
- Presión Barometrica
- VOC gases.
- CO2 Equivalente

## Protocolos de comunicación

- I2C
- SPI 

## Voltajes de alimentación

- 3V3
- 5V

## Protocolo de comunicación I2C con ESP32
Nombre | GPIO
--- | ---
SDI	 | SDA GPIO21
SCK | SCL GPIO22
3.3V | 3.3V
GND | GND


## Errores 

### BME680 error code : -2
![](/Img/error1.PNG)

Para solucionar este error debemos hacer algunos cambios en nuestro codigo, si estas utilizando la libreria ***wire.h*** este es el codigo que debes modificar para que tu sensore BME680 Funcione adecuadamente.

Busca en tu codigo la linea que contenga ```Wire.begin();``` y reemplazala por la siguiente linea de código:
```cpp
Wire.begin( SCL_#PIN , SDA_#PIN );
```

Seguido de esto nos buscar la linea de código que contenga ```begin(BME680_I2C_ADDR_PRIMARY, Wire);``` y reemplazarla por la siguiente linea de código:
```cpp
NOMBRE_DEL_OBJETO.begin( 0x77 , Wire);
```
Generalmente la dirección que el BME680 trae de forma predeterminada es *** 0x77 *** , de lo contrario debes intentar con la dirección *** 0x76 ***

#### Links importantes:
Para más información, visite estos sitios: 

- [BME680 Product page](https://www.bosch-sensortec.com/bst/products/all_products/bme680)
- [BME680 & BME688 Github page](https://github.com/BoschSensortec/BME68x-Sensor-API)
- [BME680 gas sensor design guide](https://community.bosch-sensortec.com/t5/Knowledge-base/BME680-gas-sensor-series-design-guide/ta-p/5952)
- [Knowledge base page](https://community.bosch-sensortec.com/t5/Knowledge-base/tkb-p/bst_community-mems-tkb)
- [Community support page](https://community.bosch-sensortec.com)


## Diseñado por <img src="https://github.com/teslalab/SIUCOM/blob/main/img/LOGO%20TESLA.png" height="30">

