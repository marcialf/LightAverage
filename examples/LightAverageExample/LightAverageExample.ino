/*
  LightAverageExample.ino - Arduino Sketch example for LightAverage
  
  Copyright (c) Marcial Fernandez 2016
  
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
 
// include the LightAverage library
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
// If you have the LDR datasheet LDR gama = log(R_10lux/R_100lux), R in Kohm

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
