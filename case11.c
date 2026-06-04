/*
 * case11.c
 * パターン3：単一変数の単一アクセスにおける原子性違反
 *
 * 共用体 割り込みと割り込み 変数の読み書き
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case11.h"

typedef union pack{
	unsigned long header;
	unsigned char data;
} U_Pack;
volatile U_Pack packet_case11;

void case11_isr_low(){
	unsigned char tmp;
	packet_case11.header = 0x1;
	idlerun();
	tmp = packet_case11.data;
}

void case11_isr_high(){
	packet_case11.data = 0x2;  /* bug　*/
}


