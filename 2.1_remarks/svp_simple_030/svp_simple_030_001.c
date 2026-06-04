/*
 * racebench2.1_remarks
 * Filename:svp_simple_030_001
 * Template File:svp_simple_030
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [説明]:
 * メインプログラム入口:svp_simple_030_001_main
 * 割り込みハンドラ入口:svp_simple_030_001_isr_1,svp_simple_030_001_isr_2,svp_simple_030_001_isr_3
 * 割り込み番号が大きいほど優先度が高い。
 *
 *
 *
 *
 */

#include "../common.h"

void svp_simple_030_001_init();
void addData();
volatile int svp_simple_030_001_isr_1_flag;
volatile int svp_simple_030_001_gloable_var;

int svp_simple_030_001__main() {
  svp_simple_030_001_init();

  disable_isr(-1);
  enable_isr(1);
  if (svp_simple_030_001_gloable_var > 12) {  
    svp_simple_030_001_gloable_var = 0;       
  }
  return 0;
}

void svp_simple_030_001_init() {
  svp_simple_030_001_gloable_var = rand();
  svp_simple_030_001_isr_1_flag = rand();

  init();
}

void addData() {
  svp_simple_030_001_gloable_var++;  
}
void svp_simple_030_001_isr_1() {
  addData(); 
  svp_simple_030_001_isr_1_flag = 0;
  enable_isr(2);
}
void svp_simple_030_001_isr_2() {
  if (svp_simple_030_001_isr_1_flag) {
    svp_simple_030_001_gloable_var++;  
  }
}
void svp_simple_030_001_isr_3() {
  svp_simple_030_001_gloable_var++;  
}

// バグ箇所:
// 1.svp_simple_030_001_gloable_var <R, #29>, <W, #43>, <W, #30>

// 誤検知箇所:
// 1.svp_simple_030_001_gloable_var <R, #29>, <W, #52>, <W, #30>
// 2.svp_simple_030_001_gloable_var <R, #29>, <W, #56>, <W, #30>