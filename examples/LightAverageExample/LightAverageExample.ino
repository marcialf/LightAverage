
 
// include the ThermoAverage library
#include <LightAverage.h>

// create a LightAverage instance, reading from analog pin A0
// Using a 10K serie reference resistor.
LightAverage lightAverage(A0, 10000);  

// If you have a different type of LDR
/*LightAverage lightAverage(A0,          // the analog pin to read from
                      10000,           // the reference resistor value in ohm
                      5,               // the reference ADC volt
                      1000,            // the LDR dark resistence (0 Lux) in Kohm
                      0.7)             // the LDR gama coeficiente
*/
// If you have  LDR cdatasheet LDR gama is log(R_10lux/R_100lux)

void setup() {
  // set up UART
  Serial.begin(9600);
}

void loop() {
 
  // print the iluminance
  Serial.print("Lux = ");
  Serial.println(lightAverage.lux(10));   // calculate 10 sample average

  // pause to read again
  delay(3000);
}