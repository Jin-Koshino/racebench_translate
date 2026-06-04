/*
 * racebench2.1_remarks
 * Filename:svp_simple_017_001
 * Template File:svp_simple_017
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [Description]:
 * Main entry:svp_simple_017_001_main
 * Interrupt entry:svp_simple_017_001_isr_1
 * Interrupt priority is determined by interrupt number; a higher interrupt number means a higher priority.
 *
 *
 *
 *
 */

#include "../common.h"

#define MAX_LENGTH 100
#define TRIGGER 50

volatile int svp_simple_017_001_global_var;
volatile int svp_simple_017_001_local_array[MAX_LENGTH];

void svp_simple_017_001_main() {
  init();
  int i = 0;

  for (svp_simple_017_001_global_var = 0; svp_simple_017_001_global_var < MAX_LENGTH;
       svp_simple_017_001_global_var++)
  {
    svp_simple_017_001_local_array[svp_simple_017_001_global_var] = i++;
  }
}

void svp_simple_017_001_isr_1() {
  idlerun();

  svp_simple_017_001_global_var = TRIGGER;

  svp_simple_017_001_local_array[TRIGGER] = 0;
}
// Bug point:
//1.svp_simple_017_001_global_var<R#29>,<W#39>,<R#29>
//2.svp_simple_017_001_global_var<R#29>,<W#39>,<R#32>
//3.svp_simple_017_001_global_var<R#32>,<W#39>,<W#30>
//4.svp_simple_017_001_global_var<W#30>,<W#39>,<R#29>
// False-positive point:
//1.svp_simple_017_001_local_array<R#32>,<W#41>,<R#32>