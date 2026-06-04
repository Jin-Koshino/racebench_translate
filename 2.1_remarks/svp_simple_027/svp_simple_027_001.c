/*
 * racebench2.1_remarks
 * Filename:svp_simple_027_001
 * Template File:svp_simple_027
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [説明]:
 * メインプログラム入口:svp_simple_027_001_main
 * 割り込みハンドラ入口:svp_simple_027_001_isr_1,svp_simple_027_001_isr_2,svp_simple_027_001_isr_3
 * 割り込み番号が大きいほど優先度が高い。
 *
 *
 *
 *
 */

#include "../common.h"

void svp_simple_027_001_init();

volatile int svp_simple_027_001_gloable_var;
int svp_simple_027_001_main() {
  svp_simple_027_001_init();

  disable_isr(-1);
  enable_isr(1);
  if (svp_simple_027_001_gloable_var > 12) {  
    svp_simple_027_001_gloable_var = 0;       
  }

  return 0;
}

void svp_simple_027_001_init() {
  svp_simple_027_001_gloable_var = rand();

  init();
}

void svp_simple_027_001_isr_1() {
  svp_simple_027_001_gloable_var++;  
  enable_isr(2);
}
void svp_simple_027_001_isr_2() {
  svp_simple_027_001_gloable_var += 2;  
}
void svp_simple_027_001_isr_3() {
  svp_simple_027_001_gloable_var += 3;  
}

// バグ箇所:
// 1.svp_simple_027_001_gloable_var <R, #27>, <W, 41>, <W, #28>
// 2.svp_simple_027_001_gloable_var <R, #27>, <W, 45>, <W, #28>

// 誤検知箇所:
// 1.svp_simple_027_001_gloable_var <R, #27>, <W, 48>, <W, #28>