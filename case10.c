/*
 * case10.c
 * パターン3：単一変数の単一アクセスにおける原子性違反
 *
 * 基本型 タスクと割り込み 変数の読み書き
 *
 *  Created on: 2013年11月6日
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
