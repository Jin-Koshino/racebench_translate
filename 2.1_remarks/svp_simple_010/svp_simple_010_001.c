/*
 * racebench2.1_remarks
 * Filename:svp_simple_010_001
 * Template File:svp_simple_010
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [説明]:
 * メインプログラム入口:svp_simple_010_001_main
 * 割り込みハンドラ入口:svp_simple_010_001_isr_1
 * 割り込み番号が大きいほど優先度が高い。
 *
 *
 *
 *
 */

#include "../common.h"

typedef union pack1 {
  unsigned char header;
  unsigned int data;
} svp_simple_010_001_union;

typedef struct pack2 {
  unsigned char header;
  unsigned int data;
} svp_simple_010_001_struct;

volatile svp_simple_010_001_union svp_simple_010_001_global_union;
volatile svp_simple_010_001_struct svp_simple_010_001_global_struct;

void svp_simple_010_001_main() {
  init();
  int svp_simple_010_001_local_var1 = 0x01;
  int svp_simple_010_001_local_var2 = 0x02;

  int svp_simple_010_001_local_var3 = 0x03;
  int svp_simple_010_001_local_var4 = 0x04;

  svp_simple_010_001_global_union.header = svp_simple_010_001_local_var1;
  svp_simple_010_001_global_union.data = svp_simple_010_001_local_var2;

  svp_simple_010_001_global_struct.header = svp_simple_010_001_local_var3;
  svp_simple_010_001_global_struct.data = svp_simple_010_001_local_var4;
}

void svp_simple_010_001_isr_1() {
  idlerun();
  int reader1, reader2;

  reader1 = svp_simple_010_001_global_union.header;

  reader2 = svp_simple_010_001_global_struct.header;
}
// バグ箇所:
//1.svp_simple_010_001_global_union.header<W#40>,<R#51>,<W#41>
// 誤検知箇所:
//1.svp_simple_010_001_global_struct.header<W#43>,<R#53>,<W#44>