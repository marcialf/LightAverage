/*
  LightAverage.h - library for luminance average in Lux
  
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

#ifndef LightAverage_h
#define LightAverage_h

#include "Arduino.h"

// Default LDR value for GA 5528
// DEFAULT_LDR_DARK_RESISTENCE = LDR resistence at 0 lux in KOhm 
const float DEFAULT_LDR_DARK_RESISTENCE	= 10000;  // KOhm

// DEFAULT_LDR_GAMA is the LDR gama coeficiente
const float DEFAULT_LDR_GAMA = 0.7; 	
// Calculate gama if the datasheet don't have gama value
// you need LDR resistence in 10 Lux and the LDR resistence in 100 Lux 
//const float DEFAULT_LDR_GAMA = log(R_10lux/R_100lux);

// Reference voltage 5 V or 3.3 V
const float DEFAULT_ADC_REF_VOLT = 5;

// ADC size (1024 for Arduino)
const int MAX_ADC_SIZE = 1024;

// Default sample size to calculate average
const int DEFAULT_SAMPLE_SIZE =	10;  

class LightAverage {
  public:

    /**
     * @param analogPin          	The analog pin where the LDR is connected to.
	 * @param ref_resistor          The value of the reference resistor.
     * @param adc_ref_volt		    The ADC size. With ATMega is 1024.
     * @param ldr_dark_resistence   The LDR dark resistance in Kohm
     * @param ldr_gama  			The LDR gama parameter.
     */
	 
	LightAverage( uint8_t analogPin,
				uint32_t ref_resistor,
				float adc_ref_volt = DEFAULT_ADC_REF_VOLT,
				float ldr_dark_resistence = DEFAULT_LDR_DARK_RESISTENCE,
				float ldr_gama = DEFAULT_LDR_GAMA);
	
    float lux(void);
 
   /**
     * @param samples            The number of samples to take for lux average.
     */
    float lux(uint8_t samples);
	
  private:

     uint8_t  	_analogPin;
 	 uint32_t 	_ref_resistor;
     float 		_adc_ref_volt;
     float 		_ldr_dark_resistence;
	 float 		_ldr_gama;
};

#endif
