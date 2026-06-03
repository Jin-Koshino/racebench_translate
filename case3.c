/*
 * case3.c
 * パターン1：単一変数の複数アクセス間の原子性違反
 *
 * R-W-W struct task and interrupt variable read/write nested function
 *
 *  Created on: 2013年11月6日
 *      Author: chenrui
 */
#include "case3.h"

typedef struct Time{
	int second;
	int misecond;
} Time;

/* 共有変数は構造体型 */
volatile Time star_time_case3;

void case3_main(){
	idlerun();
	if(star_time_case3.misecond==1000){
		star_time_case3.second++;
		star_time_case3.misecond = 0;
	}

}

void case3_isr(){
	idlerun();
	/* ネストされた関数 */
	case3_nestedfunc();

}

void case3_nestedfunc(){
	star_time_case3.second = 1; /* bug */
}
