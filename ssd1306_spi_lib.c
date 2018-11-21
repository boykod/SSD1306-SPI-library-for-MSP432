#include "ti/devices/msp432p4xx/inc/msp.h"
#include <stdio.h>
#include <stdint.h>

unsigned char *TI_transmit_field;

//******************************************************************************************************************************************
void spi_init() {
    spi_port_init();

    P1->SEL0 |= BIT5 | BIT6 | BIT7;                                     // set 4-SPI pin as second function

    EUSCI_B0->CTLW0 |= EUSCI_B_CTLW0_SWRST;                             // Put state machine in reset

    EUSCI_B0->CTLW0 = EUSCI_B_CTLW0_SWRST |                             // Remain in reset state
            EUSCI_B_CTLW0_MST |                                         // SPI master
            EUSCI_B_CTLW0_SYNC |                                        // Synchronous mode
            EUSCI_B_CTLW0_CKPL |                                        // Clock polarity high
            EUSCI_B_CTLW0_MSB |                                         // MSB first
            EUSCI_B_CTLW0_MODE_0 |                                      // 3-pin mode
            EUSCI_B_CTLW0_STEM |                                        // STE mode select
            EUSCI_B_CTLW0_SSEL__ACLK;                                   // ACLK

    EUSCI_B0->BRW = 0x01;                                               // /2,fBitClock = fBRCLK/(UCBRx+1).
    EUSCI_B0->CTLW0 &= ~EUSCI_B_CTLW0_SWRST;                            // **Initialize USCI state machine**

    // RST setup
    P3->OUT |= BIT3;                                                    // RST - 1
}
//******************************************************************************************************************************************
void spi_port_init() {
    //LED 1
    P1->OUT &= ~BIT0;
    P1->DIR |= BIT0;

    //SPI CS
    P3->OUT &= ~BIT0;
    P3->DIR |= BIT0;

    //SPI DC
    P3->OUT &= ~BIT2;
    P3->DIR |= BIT2;

    //SPI RST
    P3->OUT &= ~BIT3;
    P3->DIR |= BIT3;
}
//******************************************************************************************************************************************
void spi_transmit(unsigned char *params, unsigned char flag, unsigned char isData) {
    volatile uint32_t i;
    uint32_t flag_counter = 0;
    TI_transmit_field = params;

    /* Toggle user LED, indicating a SPI transfer is in progress */
    P1->OUT ^= BIT0;

    if (isData == 0) {
        P3->OUT &= ~BIT2;
    } else {
        P3->OUT |= BIT2;
    }

    P3->OUT &= ~BIT0;

    for (flag_counter = 0; flag_counter < flag; flag_counter ++) {

        while (!(EUSCI_B0->IFG & EUSCI_B_IFG_TXIFG));       //flag
        EUSCI_B0->TXBUF = *TI_transmit_field;

        // Decrement TX byte counter
        TI_transmit_field++;
    }

    for (i = 150; i > 0; i--);                          //delay
    P3->OUT |= BIT0;
}
//******************************************************************************************************************************************
