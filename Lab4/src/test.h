#ifndef TEST.H
#define TEST.H
#include <xc.h>
#include <inttypes.h>

void operation_8(uint8_t operation, uint32_t iterations);
void operation_16(uint8_t operation, uint32_t iterations);
void operation_32(uint8_t operation, uint32_t iterations);
void operation_64(uint8_t operation, uint32_t iterations);
void operation_f(uint8_t operation, uint32_t iterations);
void operation_d(uint8_t operation, uint32_t iterations);



#endif