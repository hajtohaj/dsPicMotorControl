My first microchip project based on stuff found in the garage
Goal is to learn microchip programming for home use by implementing gradual
- blinking diode
- Read quadrature encoder signal from pololu 37D brushed DC motor; [probably this](https://www.pololu.com/product/4691)
- Drive motor with PWM using [Dual Serial Motor Controller](https://www.pololu.com/product/2078)
- Communicate over CAN with older [BeagleBone® Black](https://www.beagleboard.org/boards/beaglebone-black). CAN description on [Microchip Developer Help](https://developerhelp.microchip.com/xwiki/bin/view/applications/can/)
- PLC1602JHW-FWLW LCD Display [spec](https://www.openhacks.com/uploadsproductos/eone-1602a1.pdf) or [spec](https://www.micros.com.pl/mediaserver/O_LCM162-wfpc_0001.pdf)

Microcontroller: dsPIC33FJ64MC802

Breadboard is used for setup

Programmer/Debugger: MPLAB ICD 3 (considering upgrade to PICkit™ 5: PG164150)

Readings: 
- dsPIC33FJ64MC802 [Datasheet](https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/70291G.pdf)
- dsPIC33F/PIC24H Family Reference Manual, published as separate chapters, e.g.
  - [Section 7. Oscillator](https://ww1.microchip.com/downloads/en/DeviceDoc/70186E.pdf)
  - [Section 10. I/O Ports](https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/ReferenceManuals/70193D.pdf)
  - [Quadrature Encoder Interface (QEI)](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU16/ProductDocuments/ReferenceManuals/dsPIC33-PIC24-FRM-Quadrature-Encoder-Interface-QEI-DS70000601D.pdf)
- [dsPIC33A Programmer's Reference Manual](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU16/ProductDocuments/ReferenceManuals/dsPIC33A-Programmers-Reference-Manual-DS70005540.pdf)
- [MPLAB XC-DSC C Compiler User's Guide](https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/UserGuides/MPLAB-XC-DSC-C-Compiler-User-Guide-DS50003589.pdf)
- [MPLAB XC-DSC Libraries Reference Manual](https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/ReferenceManuals/MPLAB-XC-DSC-Libraries-Reference-Manual-DS50003591.pdf)
- [MPLAB XC-DSC Assembler, Linker and Utilities User's Guide](https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/UserGuides/MPLAB-XC-DSC-Assembler-Linker-and-Utilities-User-Guide-DS50003590.pdf)
- [Developer Help](https://developerhelp.microchip.com/xwiki/bin/view/Main/)

Video:
 - [Create! - 01 Setting up the PIC Microcontroller (Quick and Easy)](https://www.youtube.com/watch?v=CSCDfCr5kDo&t=996s)

Notes:
- To push to github from MPLAB X "you must create a personal access token to use as a password when authenticating to GitHub" [ref](https://microchip.my.site.com/s/article/Github-2-factor-authentification-in-MPLAB-X)
- Order PCB on https://www.pcbway.com (Using KiCad plugin)
