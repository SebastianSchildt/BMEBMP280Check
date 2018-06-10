
#include <Adafruit_BME280.h>
#include <Adafruit_BMP280.h>




//Global sensor object
Adafruit_BME280 bme280;
Adafruit_BMP280 bmp280;

bool has_bmp280=false;
bool has_bme280=false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 

  Wire.begin(D3, D4);



  Serial.println("test BMP 280 on 76");
  if (bmp280.begin(0x76)) {
    Serial.println(" ... found");
    has_bmp280=true;
    goto BME_CHECK;
  } else {
   Serial.println(" not found");
  }

  Serial.println("test BMP 280 on 77"); 
  if (bmp280.begin(0x77)) {
    Serial.println(" ... found");
    has_bmp280=true;
  } else {
    Serial.println(" not found");
  }

BME_CHECK:
   Serial.println("test BME 280 on 76");
  if (bme280.begin(0x76)) {
    Serial.println(" ... found");
    has_bme280=true;
    goto BME_CHECK_DONE;
  } else {
    Serial.println(" not found");
  }

  Serial.println("test BME 280 on 77");
  if (bme280.begin(0x77)) {
    Serial.println(" ... found");
  } else {
    Serial.println(" not found");
  }

BME_CHECK_DONE:

  if (has_bme280) {
    Serial.println("\nBME280 data:");
    Serial.print("Temperature is : "); Serial.print(bme280.readTemperature()); Serial.println("");
    Serial.print("Humidity is    : "); Serial.print(bme280.readHumidity()); Serial.println("");
    Serial.print("Pressure is    : "); Serial.print(bme280.readPressure()); Serial.println("");
  }

if (has_bmp280) {
    Serial.println("\nBME280 data");
    Serial.print("Temperature is : "); Serial.print(bme280.readTemperature()); Serial.println("");
    Serial.print("Pressure is    : "); Serial.print(bme280.readPressure()); Serial.println("");
  }
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
