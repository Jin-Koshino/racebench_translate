/*
 * racebench2.1_remarks
 * Filename:svp_simple_009_001
 * Template File:svp_simple_009
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [説明]:
 * メインプログラム入口:svp_simple_009_001_main
 * 割り込みハンドラ入口:svp_simple_009_001_isr_1
 * 割り込み番号が大きいほど優先度が高い。
 *
 *
 *
 *
 */

#include "../common.h"

volatile int *svp_simple_009_001_p;
volatile int *svp_simple_009_001_q;

volatile int *svp_simple_009_001_m;

void svp_simple_009_001_main() {
  init();
  int svp_simple_009_001_local_var1 = 0x01;
  int svp_simple_009_001_local_var2 = 0x09;

  svp_simple_009_001_p = &svp_simple_009_001_local_var1;
  svp_simple_009_001_q = &svp_simple_009_001_local_var1;

  *svp_simple_009_001_p = 0x02;
  *svp_simple_009_001_q = 0x03;

  svp_simple_009_001_m = &svp_simple_009_001_local_var2;

  *svp_simple_009_001_m = 0x06;
  *svp_simple_009_001_m = 0x06;
}

void svp_simple_009_001_isr_1() {
  int reader1, reader2;
  idlerun();
  reader1 = *svp_simple_009_001_p;
  int svp_simple_009_001_local_var3 = 0x08;
  svp_simple_009_001_m = &svp_simple_009_001_local_var3;
  reader2 = *svp_simple_009_001_m;
}
// バグ箇所:
//1.*svp_simple_009_001_p<W#32>,<R#44>,<W#33>
// 誤検知箇所:
//1.*svp_simple_009_001_m<W#37>,<R#47>,<W#38>