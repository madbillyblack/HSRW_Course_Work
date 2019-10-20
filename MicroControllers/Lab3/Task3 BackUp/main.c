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

    	TCCR0B |= (1<< CS10);
	TCCR0B |= (1<< CS11);
	TCCR1B |= (1<< CS12);

}
/******************************************************************************/


void pitch(int tone_ct, int delay_ms)
{
	TCNT0 = 0;
	int delay_converted = delay_ms*125;

	while(TCNT0 < delay_converted)
	{
		if(TCNT1 >= tone_ct)
		{
			TCNT1 = 0;
			PORTB ^= (1 << PB0);
		}
	}
	//return 0;
}



/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void)
{
	
	// Init
	init();

	uint8_t note_A = 36;
	uint8_t note_B = 32;
	uint8_t note_C = 30;
	uint8_t note_E = 47;
	uint8_t note_G = 40;
	uint8_t note_G1 = 20;
	uint8_t note_END = 1;

/* 	//TEST TONE	
		if (TCNT1 >= 36)
		{
			TCNT1 = 0;
			PORTB ^= (1 << PB0);
		}
*/

	pitch(note_G, 344);
	pitch(note_A, 94);
	pitch(note_G, 219);
	pitch(note_E, 719);
	pitch(note_G, 344);
	pitch(note_A, 94);
	pitch(note_G, 219);
	pitch(note_E, 719);
	pitch(note_G1, 469);
	pitch(note_G1, 219);
	pitch(note_B, 719);
	pitch(note_C, 469);
	pitch(note_C, 219);
	pitch(note_G, 719);
	pitch(note_END, 719);
		
	return 0;
}



/******************************************************************************/
