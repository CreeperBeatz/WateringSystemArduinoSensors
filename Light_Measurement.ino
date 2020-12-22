#define LDR_PIN                   A0
#define MAX_ADC_READING           1023
#define ADC_REF_VOLTAGE           5.0
#define REF_RESISTANCE            4600  // measure this for best results
#define LUX_CALC_SCALAR           12518931
#define LUX_CALC_EXPONENT         -1.405

int   ldrRawData;
float resistorVoltage, ldrVoltage;
float ldrResistance;
float ldrLux;

float measureLight(){
  // Light sensor measurements
  ldrRawData = analogRead(LDR_PIN);
  
  // Convert the raw digital data back to the voltage that was measured on the analog pin
  resistorVoltage = (float)ldrRawData / MAX_ADC_READING * ADC_REF_VOLTAGE;

  // voltage across the LDR is the 5V supply minus the 5k resistor voltage
  ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
  
  // LDR_RESISTANCE_CONVERSION
  // resistance that the LDR would have for that voltage  
  ldrResistance = ldrVoltage/resistorVoltage * REF_RESISTANCE;
  
  // LDR_LUX
  // Change the code below to the proper conversion from ldrResistance to
  // ldrLux
  ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);
 
  // print out the results
  //Serial.print("LDR Raw Data   : "); Serial.println(ldrRawData);
  //Serial.print("LDR Voltage    : "); Serial.print(ldrVoltage); Serial.println(" volts");
  //Serial.print("LDR Resistance : "); Serial.print(ldrResistance); Serial.println(" Ohms");
  //Serial.print("  LDR Illuminance: "); Serial.print(ldrLux); Serial.println(" lux");

  return ldrLux;
}
