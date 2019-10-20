/**
	@author Thomas Grunenberg
	@version 0.1
	@file main.c
	@brief Main programm for temperature data logger
*/

/**
	@brief The CPU speed in Hz
*/
#define F_CPU 8000000UL


#define TEMPSENOR_OFFSET 1215 // TOCHECK

/**
	@brief I2C Address of the DS1307
*/
#define DS1307_I2C_ADR 0xD0 //Address of the DS1307: 208

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "i2c_master.h"
#include "init.h"
#include "lcd.h"
#include "stdio.h"
/******************************************************************************/


/******************************************************************************/
/* GLOBAL MEMORY                                                              */
/******************************************************************************/
char* dayofweek[8] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun", "Err"};

// Global Time memory
uint8_t second;
uint8_t minute;
uint8_t hour;
uint8_t day;
uint8_t month;
uint8_t year;
uint8_t weekday;

//char spinner = "\\|/-";

/******************************************************************************/



/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Convert from BCD to Binary
	@param in BCD input (00-99)
	@return Binary output
*/
uint8_t ds1307_decodeBcd(uint8_t in){
	return (in>>4)*10 + (in %16);
}
/******************************************************************************/

/**
	@brief Convert from Binary to BCD
	@param in Binary input (0-99)
	@return BCD output
*/
uint8_t ds1307_encodeBcd(uint8_t in){
	return ((in / 10) << 4 ) | (in % 10); 
}
/******************************************************************************/


/**
	@brief Show time/date with the LCD
*/
void display_standby(uint16_t t){
	char str[16];

	// Time and Year
	snprintf(str, 16, "%02d:%02d:%02d  20%02d", hour, minute,
			second, year);
	
	lcd_clear();
	lcd_string(str);
	
	
	// Date and Temperature
	snprintf(str, 16, "%02d.%02d  %d.%d C", day, month, t/10, t%10);
	
	lcd_setcursor(0,2);
	lcd_string(str);

	return;
}
/******************************************************************************/

/**
	@brief Write a row byte to the DS1307
	@param adr address to write
	@param data byte to write
*/
void ds1307_write(uint8_t adr, uint8_t data){
	
	if (i2c_master_open_write(DS1307_I2C_ADR))
		return;
	
	i2c_master_write(adr);
	i2c_master_write(data);
	
	i2c_master_close();
}
/******************************************************************************/

/**
	@brief Read a row byte from the DS1307
	@param adr address to read
	@return the received byte
*/
uint8_t ds1307_read(uint8_t adr){
	uint8_t ret;

	if (i2c_master_open_write(DS1307_I2C_ADR))
		return 0;
	
	i2c_master_write(adr);
	i2c_master_open_read(DS1307_I2C_ADR);
	ret = i2c_master_read_last();
	
	i2c_master_close();

	return ret;

}
/******************************************************************************/

/**
	@brief Start or freeze the clock of the DS1307
	@param run zero for stop, all other for run
*/
void ds1307_rtc(uint8_t run){
	
	uint8_t readout;
	
	// Read current value
	readout = ds1307_read(0x00);
	
	
	// Set CH bit
	if (run)
		readout &= ~(0x80);
	else
		readout |= 0x80;
		
	// Write value back
	ds1307_write(0x00, readout);
}
/******************************************************************************/

/**
	@brief Write the current time to the DS1307
	@return zero for no error, one for communication error
*/
uint8_t ds1307_setTime(void){
	uint8_t chbit = ds1307_read(0x00) & 0x80;

	// Open device for write
	if (i2c_master_open_write(DS1307_I2C_ADR))
		return 1;

	i2c_master_write(0x00);
	if (chbit)
		i2c_master_write(ds1307_encodeBcd(second) | 0x80);
	else
		i2c_master_write(ds1307_encodeBcd(second) & 0x7F);		
	
	i2c_master_write(ds1307_encodeBcd(minute));
	i2c_master_write(ds1307_encodeBcd(hour));
	
	i2c_master_write(weekday);		
	
	i2c_master_write(ds1307_encodeBcd(day));
	i2c_master_write(ds1307_encodeBcd(month));
	i2c_master_write(ds1307_encodeBcd(year));		
	
	
	// Close I2C bus
	i2c_master_close();
	
	return 0;
}
/******************************************************************************/

/**
	@brief Get the current time from the DS1307
	@return zero for no error, one for communication error
*/
uint8_t ds1307_getTime(void){

	// Open device for write
	if (i2c_master_open_write(DS1307_I2C_ADR))
		return 1;
	
	// select reading position (0x00)
	i2c_master_write(0x00);
	
	// (Re-)Open device for read
	i2c_master_open_read(DS1307_I2C_ADR);
	
	// Read value
	second = ds1307_decodeBcd(i2c_master_read_next() & 0x7F);
	minute = ds1307_decodeBcd(i2c_master_read_next() & 0x7F);
	hour = ds1307_decodeBcd(i2c_master_read_next() & 0x7F);
	weekday = ds1307_decodeBcd(i2c_master_read_next() & 0x7F);
	day = ds1307_decodeBcd(i2c_master_read_next() & 0x7F);
	month = ds1307_decodeBcd(i2c_master_read_next() & 0x7F);
	year = ds1307_decodeBcd(i2c_master_read_last() & 0x7F);

	// Close I2C bus
	i2c_master_close();
	
	return 0;
}
/******************************************************************************/


void nexttime(void){
	uint8_t days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Set second to zero (jump is in minutes)
	second = 0;
	
	// Goto next minute
	minute++;
	if (minute >= 60){
		minute = 0;
		hour++;
	} else {
		return;
	}
	
	// Check hour
	if (hour >= 24){
		hour = 0;
		day++;
	} else {
		return;
	}
	
	// Check for gap year
	// TOCHECK
	if(((month==1)||(year %4 == 0)) && (year%100 != 0) && (year%400 == 0)){
		days[month]=29;
	}
	
	// Check day
	if (day > days[month]){
		day= 1;
		month++;
	}
	
	// Check month
	if (month >= 12){
		month = 1;
		year++;
	}
}
/******************************************************************************/


/**
	@brief Load 8 bit value from the EEPROM
	@return loaded value
*/

uint8_t load_value8bit(uint8_t pos){
	uint8_t value;

	/* TOCHECK */
	i2c_master_open_write(160);
	i2c_master_write(pos);
	i2c_master_close();

	i2c_master_open_read(161);
	value = i2c_master_read_last();

	return value;
}
/******************************************************************************/


/**
	@brief Load a 16 bit value from the EEPROM
	@return loaded value
*/

uint16_t load_value16bit(uint8_t pos){
	uint8_t highbyte, lowbyte;

	/* TOCHECK */
	i2c_master_open_write(160);
	i2c_master_write(pos);
	i2c_master_close();

	i2c_master_open_read(161);
	highbyte = i2c_master_read_next();
	lowbyte = i2c_master_read_last();

	
	return highbyte * 256 + lowbyte;
}
/******************************************************************************/

/**
	@brief Save a 8 bit value to the EEPROM
	@param tosave value to save
*/

void save_value8bit(uint8_t tosave, uint8_t pos){

	/* TOCHECK */
	i2c_master_open_write(160);
	i2c_master_write(pos);
	i2c_master_write(tosave);
	i2c_master_close();

	_delay_ms(10); // wait 10ms to make sure that data is written
}
/******************************************************************************/


/**
	@brief Save a 16 bit value to the EEPROM
	@param tosave value to save
*/
void save_value16bit(uint16_t tosave, uint8_t pos){
	uint8_t highbyte, lowbyte;

	/* TOCHECK */	
	highbyte = tosave/256;
	lowbyte = tosave%256;

	i2c_master_open_write(160);
	i2c_master_write(pos);
	i2c_master_write(highbyte);
	i2c_master_write(lowbyte);
	i2c_master_close();

	_delay_ms(10); // wait 10ms to make sure that data is written	
}
/******************************************************************************/


/**
	@brief Read the temperature with the internal analog sensor
	@return temperature in 1/10 deg. Celsius
*/
uint16_t adc_temperature_oversample(void){
	uint8_t i;
	uint32_t sum = 0;
	
	for (i = 0; i < 128; i++){
		ADCSRA |= (1 << ADSC)| (1 << ADEN); // Start ADC
	
		//TOCHECK // wait for ADC complete
		while(!(ADCSRA & (1<<ADIF)));
		ADCSRA|=(1<<ADIF);
	
		sum += ADCW;
	}

	sum /= 32;

	// substract offset
	sum -= TEMPSENOR_OFFSET;
	
	// TOCHECK: Calculate value in 1/10 deg. Celsius
	sum *=1.1;
	
	return sum;
}
/******************************************************************************/


void log_data(void){
	// TOCHECK
	uint8_t setCount = 0;
	uint8_t start = second;
	uint8_t savePos = 6;
	uint16_t temperature;

	char message[16];

	save_value8bit(setCount, 0);
	save_value8bit(year,3);
	save_value8bit(month,2);
	save_value8bit(day,1);
	save_value8bit(hour,4);
	save_value8bit(minute,5);

	while(setCount<125){
		if (( ~PINB & (1 << PB0)) && ( ~PINB & (1 << PB1)) ){
			return;
		} else{
		_delay_ms(1000);

		//DISPLAY "Recording Data " + spinner cursor.
		snprintf(message, 16, "Recording Data " /*+ spinner[second%4]*/);
	
			lcd_clear();
			lcd_string(message);

			snprintf(message, 16, "Entry%3d=%d.%dC",setCount,temperature/10, 				temperature%10);

	
			lcd_setcursor(0,2);
			lcd_string(message);

			if(start==second){

				temperature = adc_temperature_oversample();
				setCount++;
				save_value8bit(setCount, 0);
				save_value16bit(temperature, savePos);
				savePos+=2;
			}
		}
	}

	return;	
}
/******************************************************************************/


void show_data(void){
	// TOCHECK
	char message[16];
	uint8_t saveCount = load_value8bit(0);
	uint8_t dispDay = load_value8bit(1);
	uint8_t dispMonth = load_value8bit(2);
	uint8_t dispYear = load_value8bit(3);
	uint8_t dispHour = load_value8bit(4);
	uint8_t dispMin = load_value8bit(5);
	uint8_t entry = 6;
	uint16_t temperature = 0;

	while(1){
		_delay_ms(100);
		if (( ~PINB & (1 << PB0)) && ( ~PINB & (1 << PB1)) ){
			_delay_ms(500);
			return;
		} else	if(saveCount == 0){
			snprintf(message, 16, "No Saved Data");
	
			lcd_clear();
			lcd_string(message);
		} else {
			uint8_t dispEntry = entry/2-2;	
			

			temperature = load_value16bit(entry);

			snprintf(message, 16, "%02d/%02d/%02d %02d:%02d", dispDay, dispMonth,
			dispYear, dispHour, dispMin);

			lcd_clear();
			lcd_string(message);

			snprintf(message, 16, "%3dof%3d T=%d.%1dc",dispEntry, saveCount, 				temperature/10, temperature%10);
	
			//snprintf(message, 16, "aaaaaaaaaaaaaaas");

			lcd_setcursor(0,2);
			lcd_string(message);

			if ( ~PINB & (1 << PB0)&&(dispEntry<saveCount )){
			//increment loadvalue up by 2 bytes
				_delay_ms(100);
				entry+=2;

				if(dispMin<59){
					dispMin++;
				} else{
					dispMin = 0;
					dispHour++;
				}
				_delay_ms(100);

			} else if(~PINB & (1 << PB1))/*&&entry>7)*/{
			//increment loadvalue down 2 bytes
			/*	_delay_ms(100);
				entry-=2;

				if (dispMin>0){
					dispMin--;
				} else{
					dispMin = 59;
					dispHour--;
				}
				_delay_ms(100);*/
				saveCount = 0;
			}
		}
	}

	return 0;
}
/******************************************************************************/


/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
	uint16_t nowtemp;

	init(); 	// Function to initialise I/Os
	lcd_init(); // Function to initialise LCD display
	i2c_master_init(1, 10); // Init TWI
	//ds1307_rtc(1);

	


	// Analog Input
	ADMUX = (1 << REFS0)| (1 << REFS1) | (1 << MUX3); // 1.1V as reference
	ADCSRA = (1 << ADPS2)| (1 << ADPS1); // ADC Prescale by 64
	ADCSRA |= (1 << ADSC)| (1 << ADEN); // Start first conversion (dummy read)


	

	// Loop forever
	for(;;){
		
		// Short delay
		_delay_ms(100);
		
		
		// Mesure temperature
		nowtemp = adc_temperature_oversample();
		
		
		// Load current time/date from DS1307
		// TOCHECK
		ds1307_getTime();
		
		// Show current time/date
		display_standby(nowtemp);

		// Show recorded data
		if ( ~PINB & (1 << PB0) )
			show_data();
		
		// Start Recording
		if (~PINB & (1 << PB1))
			log_data();

	}

	return 0;
}
/******************************************************************************/
