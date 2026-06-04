/*
 * racebench2.1_remarks
 * Filename:svp_simple_023_001
 * Template File:svp_simple_023
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [Description]:
 * Main entry:svp_simple_023_001_main
 * Interrupt entry:svp_simple_023_001_isr_1
 * Interrupt priority is determined by interrupt number; a higher interrupt number means a higher priority.
 *
 *
 *
 *
 */

#include "../common.h"

volatile int svp_simple_023_001_global_var;
void svp_simple_023_001_func_1(int x);
void svp_simple_023_001_init();

void svp_simple_023_001_main() {
  svp_simple_023_001_init();
  svp_simple_023_001_func_1(svp_simple_023_001_global_var);  
}
void svp_simple_023_001_init() {
  svp_simple_023_001_global_var = rand();

  init();
}

void svp_simple_023_001_func_1(int var) {
  if (var > 0 && var < 12) {
    svp_simple_023_001_global_var = svp_simple_023_001_global_var + 1;  
  }
}
void svp_simple_023_001_isr_1() {
  svp_simple_023_001_global_var = 0; 
}

// Bug point:
// 1.svp_simple_023_001_global_var <R, #25>, <W, #39>, <R, #35> 
// 2.svp_simple_023_001_global_var <R, #35>, <W, #39>, <W, #35> 