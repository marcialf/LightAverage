/*
  LightAverage.cc - library for luminance average in Lux
  
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

#include "Arduino.h"
#include "LightAverage.h"
#include <math.h>

LightAverage::LightAverage(uint8_t analogPin, uint32_t ref_resistor, float adc_ref_volt,
                       float ldr_dark_resistence, float ldr_gama) {
    _analogPin = analogPin;
	_ref_resistor = ref_resistor;
 	_adc_ref_volt = adc_ref_volt;
	_ldr_dark_resistence = ldr_dark_resistence;
	_ldr_gama = ldr_gama;
	}
	
float LightAverage::lux(void) {	
    return lux(DEFAULT_SAMPLE_SIZE);
}
	
float LightAverage::lux(uint8_t _samples) {
    int average = 0;
	float resistor_volt = 0.;
	float ldr_resistence = 0.;
	float lux = 0.;
	
    // take samples and calculate average
    for (uint8_t i = 0; i < _samples; i++) {
        average += analogRead(_analogPin);
        delay(10);
    }
    average /= _samples;

    // convert ADC value to reference resistor voltage
	resistor_volt = (float)average / MAX_ADC_SIZE * _adc_ref_volt;
    // calculate LDR resistence	
	ldr_resistence = (_adc_ref_volt - resistor_volt) / resistor_volt * _ref_resistor;
	// calculate light measure in Lux using gama coeficiente
	lux = pow(10,(log10(_ldr_dark_resistence) - _ldr_gama * log10(ldr_resistence)));

    return lux;	
}