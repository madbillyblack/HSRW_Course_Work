/**
	@author ENTER YOUR NAME
	@version 0.1
	@file main.c
	@brief ENTER discription
*/

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Init the microcontroller
*/
void init(void){
	// Digital I/O init----------------------------------------------------
	DDRB &= ~(1 << DDB0);		// PB0 as Input (key 1)
	PORTB |= ( 1 << PB0);		// Pullup PB0

	DDRB |=  (1 << DDB1);		// PB1 as Output (LED red)
	DDRB |=  (1 << DDB2);		// PB2 as Output (LED yellow)
	DDRB |=  (1 << DDB3);		// PB3 as Output (LED green)


	// ADC init------------------------------------------------------------
	DDRC &= ~(1 << DDC3);		// PC3 as Input (Poti)
	PORTC &= ~(1 << DDC3);		// Pullup PC3 OFF	
	
	// ADMUX
	ADMUX = 0;
	ADMUX |= (1 << REFS0); // AVCC as reference
	//TODO Use the datasheet  // Select Channel ADC3
	ADMUX |= (1 << MUX0)|(1 << MUX1); // Select Channel ADC3

	// ADCSRA
	ADCSRA = (1 << ADPS2)|(1 << ADPS1); // Set ADC Prescale to 64

	// Start conversion, Free running, Enalbe ADC
	ADCSRA |= (1 << ADSC)|(1 << ADATE)|(1 << ADEN); 

}
/******************************************************************************/




/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void)
{
	// Init
	init();


//TASK 3

	while(1)
	{ 
		if(~PINB & (1<<PB0))
		{
			PORTB &= ~(1 << PB1);
			_delay_ms(50);
			PORTB |= (1 << PB1);
			_delay_ms(50);			
		}
		else
		{
			PORTB |= (1 << PB1);
		}
	}
	return 0;
}
/******************************************************************************/



