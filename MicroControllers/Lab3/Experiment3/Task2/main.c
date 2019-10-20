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
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Init the microcontroller
*/
void init(void){

	// Example set data direction PC1 to output
	 DDRB |=  (1 << DDB0);		// Pbo output

         TCCR1B |= (1<< CS10);

}
/******************************************************************************/




/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
	
	// Init
	init();

	// Loop forever
	while (1)
	{
		if (TCNT1 >= 13333)
		{
			TCNT1 = 0;
			PORTB ^= (1 << PB0);
		} // task 2
		
	}
	
	return 0;
}
/******************************************************************************/
