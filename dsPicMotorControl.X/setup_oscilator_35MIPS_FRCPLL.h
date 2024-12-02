/* 
 * File:   setup_oscilator_40MIPS_FRCPLL.h
 * Author: tomas
 *
 * Created on 1 grudnia 2024, 13:38
 */

#ifndef SETUP_OSCILATOR_35MIPS_FRCPLL_H
#define	SETUP_OSCILATOR_35MIPS_FRCPLL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "xc.h"

#ifndef FCY
#define FCY 35007500UL
#include <libpic30.h>   //to use __delay_us, FCY must be defined before include
#endif
    
void setup_oscilator_35MIPS_FRCPLL(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SETUP_OSCILATOR_35MIPS_FRCPLL_H */

