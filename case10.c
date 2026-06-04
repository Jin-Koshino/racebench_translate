/*
 * case10.c
 * Pattern 3: atomicity violation in a single access to a single variable
 *
 * basic type task and interrupt variable read/write
 *
 *  Created on: 2013/11/6
 *      Author: chenrui
 */
#include "case10.h"

volatile unsigned long shared1_case10;


void case10_main(){
	unsigned char tmp;

	tmp = shared1_case10;
}

void case10_isr(){

	idlerun();
	shared1_case10 = 1;  /* bug */
	idlerun();
}
