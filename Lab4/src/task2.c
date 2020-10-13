#include <xc.h>
#include <inttypes.h>
#include "uart1.h"
#include "ztimer.h"
#include <stdio.h> // for sprintf
// Module includes here
// Number of iterations for testing. You may need to play with this
// number. If it is too short, you may not get a very accurate measure
// of performance. Too long and you will have to wait forever.
#define NUM_ITERATIONS 100000
// This is the number of times you repeat the operation within the
// loop. You want to repeat enough times that the loop overhead is
// small for the simplest operations.
#define NUM_REPS 10
uint8_t buffer[64];


void main()
{
 uint32_t t1, t2;
 // !!! Add code: Initialize modules and turn on interrupts
 uart1_init();
 zTimerOn();
 zTimerSet(1000);
 uart1_txwrite_str("Performance Summary: Time per operation statistics\r\n\0");
 // Test multiplying bytes
 t1 = zTimerReadms();
 test_uint8_mult();
 t2 = zTimerReadms();
 // Print timing result. Doubles OK here. Not time critical code.
 sprintf(buffer, "UINT8 MULT: %.06f us per operation\r\n",
 (double)(t2-t1)/
 (double)NUM_ITERATIONS /(double)NUM_REPS*1000.0);
 uart1_txwrite_str(buffer);
 // Add code to test other sizes and operators
 // ...
 while (1); // When done, wait forever.
}