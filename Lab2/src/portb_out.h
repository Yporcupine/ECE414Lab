/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef PORTB_OUT_H
#define PORTB_OUT_H
#include <inttypes.h>
extern void portb_out_init();
extern void portb_out_write(uint16_t val);
#endif