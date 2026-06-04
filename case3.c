/*
 * case3.c
 * Pattern 1: atomicity violation between multiple accesses to a single variable
 *
 * R-W-W structure task and interrupt variable read/write nested function
 *
 *  Created on: 2013/11/6
 *      Author: chenrui
 */
#include "case3.h"

typedef struct Time{
	int second;
	int misecond;
} Time;

/* Shared variable is a structure type */
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
	/* Nested function  */
	case3_nestedfunc();

}

void case3_nestedfunc(){
	star_time_case3.second = 1; /* bug */
}
