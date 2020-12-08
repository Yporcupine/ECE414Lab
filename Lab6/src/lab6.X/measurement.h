#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <xc.h>
#include <inttypes.h>
#include "tft_gfx.h"
#include "tft_master.h"
#include <stdlib.h>
#include <string.h>


extern void display_init();
extern void display_line(int current_rpm, int target_rpm, short current_y);
extern void display_plot();
extern void display_rpm(int current_rpm, int target_rpm);
extern void display_command(char *ptr, int pos);
extern void eraseTarget();

#endif

