#define AIR_VALUE 620 //when soil humidity sensor is in the air
#define WATER_VALUE 310 //when soild humidity sensor is completely under water

int soilMoistureValue = 0;
float soilMoisturePercent = 0.0;

//Returns value from 0 to 1024, depending on the moisture
float measureSoilMoisture() {
  
  soilMoistureValue = analogRead(SOIL_PIN);
  
  soilMoisturePercent = map(soilMoistureValue, AIR_VALUE, WATER_VALUE, 0, 100); //TODO fix mapping bug
  if(soilMoisturePercent >= 100) {
    return 100.0;
  }
  else if(soilMoisturePercent <=0){
    return 0.0;
  }
  else {
    return soilMoisturePercent;
  }
}
