/*
 * case12.c
 * Pattern 3: atomicity violation in a single access to a single variable
 *
 * pointer dereference interrupt and interrupt variable read/write
 *  Created on: 2013/11/6
 *      Author: chenrui
 */
#include "case12.h"
volatile unsigned long g1_case12;

typedef union pack{
	unsigned long header;
	unsigned char data;
} U_Pack_12;
volatile U_Pack_12 packet_case12;


void case12_isr_low(){
	volatile unsigned long* tmp = &g1_case12;
	*tmp = 1;;
	packet_case12.header = 0x1;
	idlerun();
}

void case12_isr_high(){
	g1_case12 = 0x2;  /* bug　*/
	packet_case12.data = 0x2;  /* bug　*/
}

