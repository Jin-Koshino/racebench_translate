/*
 * racebench2.1_remarks
 * Filename:svp_simple_016_001
 * Template File:svp_simple_016
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [説明]:
 * メインプログラム入口:svp_simple_016_001_main
 * 割り込みハンドラ入口:svp_simple_016_001_isr_1
 * 割り込み番号が大きいほど優先度が高い。
 *
 *
 *
 *
 */

#include "../common.h"

volatile int svp_simple_016_001_global_var1;

void svp_simple_016_001_main() {
  init();
  int reader1;
  svp_simple_016_001_global_var1 = 0x01;
  reader1 = svp_simple_016_001_global_var1 +
            svp_simple_016_001_global_var1 +
            svp_simple_016_001_global_var1;

}

void svp_simple_016_001_isr_1() {
  idlerun();
  svp_simple_016_001_global_var1 = 0x09;
}
// バグ箇所:
//1.svp_simple_016_001_global_var1<W#24>,<R#33>,<R#25>
//2.svp_simple_016_001_global_var1<R#25>,<W#33,<R#26>
//3.svp_simple_016_001_global_var1<R#26>,<W#33>,<R#27>