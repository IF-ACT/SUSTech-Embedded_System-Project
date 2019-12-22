#include "Random.h"

#include "main.h"

unsigned Srandx ;
unsigned SrandK = 1103515245;//0x41C64E6D;
unsigned SrandB = 12345;//0x3039; 

void os_srand(unsigned seek)
{
    Srandx =seek;
}

unsigned os_rand (void)
{
    Srandx = Srandx *SrandK +SrandB ;
    return (Srandx>>1);
}
