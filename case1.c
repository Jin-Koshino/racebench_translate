/*
 * case1.c
 * パターン1：単一変数の複数アクセス間の原子性違反
 *
 * R-W-R basic type task and interrupt variable read/write
 *
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case1.h"

volatile unsigned char shared1_uchar;


void case1_main(){

	unsigned char tmp;
	/*  R-W-R */
	if(shared1_uchar > 0){
		tmp = shared1_uchar;
	}
}

void case1_isr(){

	idlerun();
	shared1_uchar = 1;  /* bug */
	idlerun();
}
