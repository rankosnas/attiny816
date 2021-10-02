/*
 * attiny816_blinky.c
 
 APPEND = 0x00 (valid)
 BODCFG = 0x40 (valid)
 BOOTEND = 0x00 (valid)
 OSCCFG = 0x01 (valid)
 ; 16MHz
 SYSCFG0 = 0xF7 (valid)
 SYSCFG1 = 0x04 (valid)
 TCD0CFG = 0x00 (valid)
 WDTCFG = 0x00 (valid)

 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	// CLK Config 8MHz
	CCP = CCP_IOREG_gc;
	CLKCTRL.MCLKCTRLA = 0;
	CCP = CCP_IOREG_gc;
	CLKCTRL.MCLKCTRLB = 1;
	// Portconfig
	PORTA_DIR |= PIN3_bm;		// PIN_PORTA3 [19] as Output
	PORTA_DIR &= ~(PIN2_bm);	// PIN_PORTA2 [18] as INPUT
	PORTA.PIN2CTRL |=(1<<3);	// PULLUPEN on PIN_PORT2 [18] Pullup resistor on
	
  while (1) 
	{
		if(!(PORTA_IN & PIN2_bm)){
			PORTA_OUT |= PIN3_bm;
			_delay_ms(100);
			PORTA_OUT &= ~(PIN3_bm);
			_delay_ms(900);
		}
	}																	
}

