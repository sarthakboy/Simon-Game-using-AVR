/*
 * SIMON_PROJECT.cpp
 *
 * Created: 10/6/2026 8:53:04 PM
 * Author : 91989
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

void startGameLedBlinking(void);
uint8_t genNextStep(uint8_t sequencelength, uint8_t sequence[]);
uint8_t loseGame(void);
int main(void)
{

    DDRD = 0b00000000;
	PORTD = 0x0F;
	DDRB  = 0b00001111;
	startGameLedBlinking();
	//PORTB = 0b11110000;
	uint8_t sequence[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	uint8_t sequencelength = 1;
	sequence[sequencelength-1] = rand()%4;
    while (1) 
    {
		//GENERATING SEQUENCE
		uint8_t curr_sequencelength = genNextStep(sequencelength, sequence);
		_delay_ms(50);
		for(int i = 0; i < curr_sequencelength;i++){
			if(sequence[i] == 0){
				PORTB |= (1<<PB0);
				_delay_ms(30);
				PORTB &= ~(1<<PB0);
				_delay_ms(30);
			}
			else if(sequence[i] == 1){
				PORTB |= (1<<PB1);
				_delay_ms(30);
				PORTB &= ~(1<<PB1);
				_delay_ms(30);
			}
			else if(sequence[i] == 2){
				PORTB |= (1<<PB2);
				_delay_ms(30);
				PORTB &= ~(1<<PB2);
				_delay_ms(30);
			}
			else if(sequence[i] == 3){
				PORTB |= (1<<PB3);
				_delay_ms(30);
				PORTB &= ~(1<<PB3);
				_delay_ms(30);
			}	
			
		}
		PORTB = 0b00001111;
		_delay_ms(40);
		PORTB = 0b11110000;
		sequencelength = curr_sequencelength;
		
		  //GENERATING SEQUENCE CODE ENDS
		  int buttonlength = 0;
		  uint8_t previousb0 = 1, previousb1 = 1, previousb2 = 1, previousb3 = 1;
		  uint8_t buttonarr[sequencelength+1];
		  while(buttonlength<sequencelength){
			  uint8_t currb0 = (PIND & (1<<PD0)) ? 1 : 0;
			  uint8_t currb1 = (PIND & (1<<PD1)) ? 1 : 0;
			  uint8_t currb2 = (PIND & (1<<PD2)) ? 1 : 0;
			  uint8_t currb3 = (PIND & (1<<PD3)) ? 1 : 0;
			  if(previousb0==1 && currb0==0){
				  buttonarr[buttonlength] = 0;
				  if(sequence[buttonlength] != buttonarr[buttonlength]){
					  PORTB = 0b00001111;
					  _delay_ms(500);
					  sequencelength = loseGame();
					  
					  break;
				  }
				  buttonlength++;
			  }
			  else if(previousb1==1 && currb1==0){
				  buttonarr[buttonlength] = 1;
				  if(sequence[buttonlength] != buttonarr[buttonlength]){
					  PORTB = 0b00001111;
					  _delay_ms(500);
					  sequencelength = loseGame();
					  break;
				  }
				  buttonlength++;
			  }
			  else if(previousb2==1 && currb2==0){
				  buttonarr[buttonlength] = 2;
				  if(sequence[buttonlength] != buttonarr[buttonlength]){
					  PORTB = 0b00001111;
					  _delay_ms(500);
					  sequencelength = loseGame();
					  break;
				  }
				  buttonlength++;
			  }
			  else if(previousb3==1 && currb3==0){
				  buttonarr[buttonlength] = 3;
				  if(sequence[buttonlength] != buttonarr[buttonlength]){
					  PORTB = 0b00001111;
					  _delay_ms(500);
					  sequencelength = loseGame();
					  break;
				  }
				  buttonlength++;
			  }
			  previousb0 = currb0;
			  previousb1 = currb1;
			  previousb2 = currb2;
			  previousb3 = currb3;
			 			  
		  }
		}
				   
}

void startGameLedBlinking(void){
	for(int i = 0;i<2;i++){
		PORTB = 0b00001111;
		_delay_ms(20);
		PORTB = 0b11110000;
		_delay_ms(20);
		}
}

uint8_t genNextStep(uint8_t sequencelength, uint8_t sequence[]){
	sequencelength = sequencelength+1;
	sequence[sequencelength-1] = rand()%4;
	return sequencelength;
}

uint8_t loseGame(void){
	PORTB = 0b11110000;
	uint8_t sequencelength = 1;
	return sequencelength;
}