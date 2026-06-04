/*
 * case8.c
 * パターン2：複数変数の関連
 * 基本変数 + 割り込みと割り込み + 関数のネスト
 *  Created on: 2013年11月6日
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
