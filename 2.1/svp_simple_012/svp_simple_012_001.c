/*
 * racebench2.0
 * Filename:svp_simple_012_001
 * Template File:svp_simple_012
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [説明]:
 * メインプログラム入口:svp_simple_012_001_main
 * 割り込みハンドラ入口:svp_simple_012_001_isr_1
 * 割り込み番号が大きいほど優先度が高い。
 *
 *
 *
 *
 */

#include "../common.h"

int svp_simple_012_001_global_var;

int svp_simple_012_001_global_pointer;

void svp_simple_012_001_main() {
  init();
  int *p = &svp_simple_012_001_global_var;

  svp_simple_012_001_global_var = 0x01;

  *p = 0x02;
}

void svp_simple_012_001_isr_1() {
  int reader1;
  reader1 = svp_simple_012_001_global_var;
}