/*
 * case8.c
 * Pattern 2: multivariable association
 * basic variable + nested interrupts + nested function
 *  Created on: 2013/11/6
 *      Author: chenrui
 */

#include "case8.h"



volatile unsigned char g1_case8;
volatile unsigned char g2_case8;

void case8_isr_low(){
	int result;

	idlerun();

	if(g1_case8 > 10){
		result = g1_case8 + g2_case8;
	}

}

void case8_isr_high(){
	case8_nestedfunc();
}

void case8_nestedfunc(){
	g1_case8=0;  /* bug */
	g2_case8=1;  /* bug */
}
