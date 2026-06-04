/*
 * case7.c
 * パターン2：複数変数の関連
 * 構造体 + タスクと割り込み
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */

#include "case7.h"

typedef struct Time{
	int second;
	int misecond;
} S_Time;

volatile S_Time time_case7;

void case7_main(){
	float starTime;
	int f1, f2;

	/* struct member access */
	idlerun();

	f1 = time_case7.second;
	f2 = time_case7.misecond;

	starTime = f1 + f2*0.001;
}

void case7_isr(){
	time_case7.second = 0x1;
	time_case7.misecond = 0xff;  /* bug */
}
