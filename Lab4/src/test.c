#include <stdio.h>
#include <inttypes.h>
#include "test.h"



uint8_t a = 15, b = 26 , c = 0;



/**
 * operation:
 *      0: add
 *      1: sub
 *      2: mult
 *      3: divide
 */

void operation_8(uint8_t operation, uint32_t iterations)
{
    uint32_t i;
    uint8_t i1, i2, i3;
    i1 = a;
    i2 = b;
    i3 = c;

    switch(operation){
	
        case 0:
            for (i=0; i<iterations; i++){
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
			
            }
		break;
        case 1:
            for (i=0; i<iterations; i++){
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
            }
            break;
        case 2:
            for (i=0; i<iterations; i++){
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
            }
            break;
        case 3:
            for (i=0; i<iterations; i++){
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
            }
            break;
        default:
            break;
    }
}

void operation_16(uint8_t operation, uint32_t iterations)
{
    uint32_t i;
    uint16_t i1, i2, i3;
    i1 = (uint16_t)a;
    i2 = (uint16_t)b;
    i3 = (uint16_t)c;

    switch(operation){
	
        case 0:
            for (i=0; i<iterations; i++){
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
			
            }
		break;
        case 1:
            for (i=0; i<iterations; i++){
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
            }
            break;
        case 2:
            for (i=0; i<iterations; i++){
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
            }
            break;
        case 3:
            for (i=0; i<iterations; i++){
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
            }
            break;
        default:
            break;
    }
}

void operation_32(uint8_t operation, uint32_t iterations)
{
    uint32_t i;
    uint32_t i1, i2, i3;
    i1 = (uint32_t)a;
    i2 = (uint32_t)b;
    i3 = (uint32_t)c;

    switch(operation){
	
        case 0:
            for (i=0; i<iterations; i++){
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
			
            }
		break;
        case 1:
            for (i=0; i<iterations; i++){
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
            }
            break;
        case 2:
            for (i=0; i<iterations; i++){
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
            }
            break;
        case 3:
            for (i=0; i<iterations; i++){
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
            }
            break;
        default:
            break;
    }
}

void operation_64(uint8_t operation, uint32_t iterations)
{
    uint32_t i;
    uint64_t i1, i2, i3;
    i1 = (uint64_t)a;
    i2 = (uint64_t)b;
    i3 = (uint64_t)c;

    switch(operation){
	
        case 0:
            for (i=0; i<iterations; i++){
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
			
            }
		break;
        case 1:
            for (i=0; i<iterations; i++){
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
            }
            break;
        case 2:
            for (i=0; i<iterations; i++){
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
            }
            break;
        case 3:
            for (i=0; i<iterations; i++){
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
            }
            break;
        default:
            break;
    }
}

void operation_f(uint8_t operation, uint32_t iterations)
{
    uint32_t i;
    float i1, i2, i3;
    i1 = (float)a;
    i2 = (float)b;
    i3 = (float)c;

    switch(operation){
	
        case 0:
            for (i=0; i<iterations; i++){
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
			
            }
		break;
        case 1:
            for (i=0; i<iterations; i++){
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
            }
            break;
        case 2:
            for (i=0; i<iterations; i++){
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
            }
            break;
        case 3:
            for (i=0; i<iterations; i++){
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
            }
            break;
        default:
            break;
    }
}


void operation_d(uint8_t operation, uint32_t iterations)
{
    uint32_t i;
    double i1, i2, i3;
    i1 = (double)a;
    i2 = (double)b;
    i3 = (double)c;

    switch(operation){
	
        case 0:
            for (i=0; i<iterations; i++){
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
                i3 = i2 + i1;
			
            }
		break;
        case 1:
            for (i=0; i<iterations; i++){
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
                i3 = i2 - i1;
            }
            break;
        case 2:
            for (i=0; i<iterations; i++){
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
                i3 = (i2) * (i1);
            }
            break;
        case 3:
            for (i=0; i<iterations; i++){
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
                i3 = (i2) / (i1);
            }
            break;
        default:
            break;
    }
}

