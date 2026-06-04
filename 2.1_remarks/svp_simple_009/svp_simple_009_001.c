/*
 * racebench2.1_remarks
 * Filename:svp_simple_009_001
 * Template File:svp_simple_009
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [Description]:
 * Main entry:svp_simple_009_001_main
 * Interrupt entry:svp_simple_009_001_isr_1
 * Interrupt priority is determined by interrupt number; a higher interrupt number means a higher priority.
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
// Bug point:
//1.*svp_simple_009_001_p<W#32>,<R#44>,<W#33>
// False-positive point:
//1.*svp_simple_009_001_m<W#37>,<R#47>,<W#38>