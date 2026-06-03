/*
 * case2.c
 *
 * パターン1：単一変数の複数アクセス間の原子性違反
 *
 * W-W-R union task and interrupt variable read/write
 *
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case2.h"

typedef union pack{
	unsigned long header;
	unsigned char data;
} U_Pack;
volatile U_Pack packet_case2;

void case2_main(){
	unsigned char tmp;
	packet_case2.header = 0x1;
	idlerun();
	tmp = packet_case2.data;
}

void case2_isr(){
	packet_case2.data = 0x2;  /* bug　*/
}


