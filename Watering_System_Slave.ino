#include <DHT.h>
#include <Adafruit_Sensor.h>

#define LDRPIN A0 //LDR = light sensing diode
#define SOIL_PIN A1
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  //TODO change to other type of delay
  delay(1000);

  Serial.print("Humidity: "); 
  Serial.print(measureHumidity());
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(measureTemperature());
  Serial.print(" *C\t");
  Serial.print("Luminosity: ");
  Serial.print(measureLight());
  Serial.print(" lx\t");
  Serial.print("Soil moisture: ");
  Serial.print(measureSoilMoisture());
  Serial.println("%");

}
