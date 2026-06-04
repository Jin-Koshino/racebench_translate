/*
 * racebench2.1_remarks
 * Filename:svp_simple_004_001
 * Template File:svp_simple_004
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [Description]:
 * Main entry:svp_simple_004_001_main
 * Interrupt entry:svp_simple_004_001_isr_1,svp_simple_004_001_isr_2
 * Interrupt priority is determined by interrupt number; a higher interrupt number means a higher priority.
 *
 *
 *
 *
 */

#include "../common.h"

#define MAX_LENGTH 10000
#define TRIGGER 9999

volatile int svp_simple_004_001_condition1 = 1;
volatile int svp_simple_004_001_condition2 = 1;
volatile int svp_simple_004_001_condition3 = 1;
volatile int svp_simple_004_001_condition4 = 1;
volatile int svp_simple_004_001_condition5 = 1;
volatile int svp_simple_004_001_condition6 = 1;

volatile int svp_simple_004_001_global_var1 = 0x11;
volatile int svp_simple_004_001_global_var2 = 0x22;
volatile int svp_simple_004_001_global_var3 = 0x33;

void svp_simple_004_001_main() {
  init();
  int reader1, reader2;
  int reader3, reader4;
  int reader5, reader6;
  disable_isr(2);

  if (svp_simple_004_001_condition1 == 1) {
    reader1 = svp_simple_004_001_global_var1;
    reader5 = svp_simple_004_001_global_var3;
  }

  if (svp_simple_004_001_condition2 == 1) {
    reader2 = svp_simple_004_001_global_var1;
    reader6 = svp_simple_004_001_global_var3;
  }

  if (svp_simple_004_001_condition4 == 1) reader3 = svp_simple_004_001_global_var2;

  if (svp_simple_004_001_condition5 == 1) reader4 = svp_simple_004_001_global_var2;
}

void svp_simple_004_001_isr_1() {
  svp_simple_004_001_condition6 = 0;

  if (svp_simple_004_001_condition3 == 1)
    svp_simple_004_001_global_var1 = 0xaa;
  else
    svp_simple_004_001_global_var3 = 0xcc;

  enable_isr(2);
}

void svp_simple_004_001_isr_2() {
  if (svp_simple_004_001_condition6 == 1)
    svp_simple_004_001_global_var2 = 0x22;
}
// Bug point:
//1.svp_simple_004_001_global_var1<R#41>,<W#59>,<R#46>
// False-positive point:
//1.svp_simple_004_001_global_var3<R#42>,<W#61>,<R#47>
//2.svp_simple_004_001_global_var2<R#50>,<W#68>,<<R#52>