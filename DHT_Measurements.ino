float airHumidity = 0;
float airTemp = 0;

float measureHumidity() {
    //DHT Sensor measurements
  airHumidity = dht.readHumidity();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(airTemp)) {
    Serial.println("Failed to read from DHT sensor!");
    return 0.0;
  }

  return airHumidity;
}

float measureTemperature(){
    //DHT Sensor measurements
  airTemp = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(airHumidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return 0.0;
  }

  return airTemp;
}
