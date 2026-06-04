/*
 * racebench2.1_remarks
 * Filename:svp_simple_025_001
 * Template File:svp_simple_025
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [説明]:
 * メインプログラム入口:svp_simple_025_001_main
 * 割り込みハンドラ入口:svp_simple_025_001_isr_1
 * 割り込み番号が大きいほど優先度が高い。
 *
 *
 *
 *
 */

#include "../common.h"

volatile int svp_simple_025_001_global_var;
volatile int *svp_simple_025_001_global_array[100];
void svp_simple_025_001_func_1(int *array);
void svp_simple_025_001_init();

void svp_simple_025_001_main() {
  svp_simple_025_001_init();
  svp_simple_025_001_func_1(&svp_simple_025_001_global_var);
}
void svp_simple_025_001_init() {
  svp_simple_025_001_global_var = rand();

  init();
}

void svp_simple_025_001_func_1(int *ptr_var) {
  *ptr_var = *ptr_var + 1;  
}
void svp_simple_025_001_isr_1() {
  svp_simple_025_001_global_var = 0;  
}

// バグ箇所:
// 1.svp_simple_025_001_global_var <R,#35>, <W, #38>, <W, #35>