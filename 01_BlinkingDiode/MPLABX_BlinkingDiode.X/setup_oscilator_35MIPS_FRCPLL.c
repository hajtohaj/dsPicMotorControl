#include "setup_oscilator_35MIPS_FRCPLL.h"
void setup_oscilator_35MIPS_FRCPLL(void){
    
    //set PLL to have Fosc=80MHz -> Fcy=35MIPS (FRC/N1/N2*M: 7.37/4/2*76=~70))
    _PLLPRE = 2; //N1=2+2=4
    _PLLPOST = 0; //N2=2+0=2
    _PLLDIV = 73; //M=3+73=76
}