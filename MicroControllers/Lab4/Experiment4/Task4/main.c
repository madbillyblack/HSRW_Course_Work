/**
	@author ENTER YOUR NAME
	@version 0.1
	@file main.c
	@brief ENTER discription
*/

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Init the microcontroller
*/



void init(void){

	// Init key inputs
	DDRD &=  ~(1 << DDD2);		// PD2 input
	DDRD &=  ~(1 << DDD3);		// PD3 input
	PORTD |= (1 << PD2); // enable Pullup PD2
	PORTD |= (1 << PD3); // enable Pullup PD3

	// Analog input
	DDRC &= ~(1 << DDC0);		// PC0 as Input (ADC0)
	PORTC &= ~( 1 << PC0);		// Pullup PC0 off

	// Init LED outputs
	DDRB |= (1<< PB0);
	DDRB |= (1<< PB1);
	DDRB |= (1<< PB2);
	//TODO
	
	// Enable interrupts
	EICRA |= (1<<ISC11)|(1<<ISC10)|(1<<ISC00)|(1<<ISC01);
	EIMSK |= (1<<INT0) | (1<<INT1);
	TIMSK1 |= (1<<TOIE1)|(1<<OCIE1A);

	TCCR1B |= (1<<CS12);
	
	//TODO
}
/******************************************************************************/




/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
	
	// Init
	init();
	OCR1A=1000;

	// Global interrupt enable
	sei();

	// Loop forever
	while (1)
	{
/*
		if(!(PIND & (1<<PD2)))
		{
			PORTB |= (1<<PB0);
		}
		if(!(PIND & (1<<PD3)))
		{
			PORTB &= ~(1<<PB0);
		}
*/		
		// Your code here

		PORTB |= (1<<PB1);
		_delay_ms(250);
		
		PORTB &= ~(1<<PB1);
		_delay_ms(250);

	}
	
	return 0;
}
/******************************************************************************/

/**
	@brief INT0 interrupt
*/
ISR(INT0_vect)
{
	// Your code here
	PORTB |= (1<<PB0);
}
/******************************************************************************/

/**
	@brief INT1 interrupt
*/
ISR(INT1_vect)
{
	// Your code here
	PORTB &= ~(1<<PB0);
}
/******************************************************************************/

/**
	@brief Timer1 overflow interrupt
*/
ISR(TIMER1_OVF_vect)
{
	// Your code here
	PORTB |= (1<<PB2);
}

ISR(TIMER1_COMPA_vect)
{
	PORTB &= ~(1<<PB2);
}
/******************************************************************************/
