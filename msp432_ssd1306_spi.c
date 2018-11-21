#include "ti/devices/msp432p4xx/inc/msp.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "ssd1306_lib.h"
#include "ssd1306_spi_lib.h"

char printNum[80];
unsigned char num = 5;

const unsigned char ti_logo[] = {
//   0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x80, 0x00, 0x00, 0x80, 0x98, 0x08, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00,
//  28    29    30    31    32    33    34    35    36    37    38    39    40    41    42    43    44    45    46    47    48    49    50    51    52    53    54    55
  0x00, 0x10, 0x30, 0x70, 0xF0, 0xF0, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x61, 0x01, 0x00, 0xF0, 0x3F, 0x01, 0x00, 0xE0, 0xE1, 0xF9, 0xFF, 0xFF, 0xFF, 0xF0, 0x00,
//  56    57    58    59    60    61    62    63    64    65    66    67    68    69    70    71    72    73    74    75    76    77    78    79    80    81    82    83
  0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x07, 0x03, 0x03, 0x03, 0x07, 0x1F, 0x60, 0xE0, 0xE0, 0xE1, 0xE0, 0xE0, 0x61, 0x31, 0x1F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x00,
//  84    85    86    87    88    89    90    91    92    93    94    95    96    97    98    99   100   101   102   103   104   105   106   107   108   109   110   111
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

int main(void) {
    volatile uint32_t i;

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
//*******************************************************************************************************************************************
    spi_init();

    ssd1306Init();

    fillDisplay (0x00);

//    draw6x8Str(0, 0, "/* CC1352P */", 0, 0);
//    draw6x8Str(0, 1, "/* Wohoooooo */", 1, 0);
//    draw6x8Str(0, 3, "/* :D */", 1, 0);
//    draw6x8Str(0, 6, "/* MSP432P401R */", 0, 0);
//    drawImage(100, 30, 28, 28, ti_logo, 1);

    while (1) {

        for (num = 0; num < 10; num++){
            sprintf (printNum, "%d", num);
            draw12x16Str(0,  0, printNum, 1);
            draw12x16Str(115,  0, printNum, 1);
            draw6x8Str(40, 5, printNum, 1, 0);
            draw6x8Str(45, 6, printNum, 1, 0);
            draw6x8Str(55, 6, printNum, 1, 0);
            draw6x8Str(65, 6, printNum, 1, 0);
            draw6x8Str(75, 6, printNum, 1, 0);
            draw6x8Str(80, 5, printNum, 1, 0);
            for (i = 300000; i > 0; i--);
        }
        num = 0;

    }
}
