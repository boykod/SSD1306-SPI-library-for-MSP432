#define SSD1306_WIDTH                                   128
#define SSD1306_HEIGHT                                  64
#define SSD1306_COMMAND_MODE                            0x00
#define SSD1306_DATA_MODE                               0x40

// Command
#define SSD1306_SET_CONTRAST                            0x81
#define SSD1306_ENTIRE_DISPLAY_RESUME                   0xA4
#define SSD1306_ENTIRE_DISPLAY_ON                       0xA5
#define SSD1306_NORMAL_DISPLAY                          0xA6
#define SSD1306_INVERSE_DISPLAY                         0xA7
#define SSD1306_DISPLAY_OFF                             0xAE
#define SSD1306_DISPLAY_ON                              0xAF
#define SSD1306_SET_LCOL_START_ADDRESS                  0x00
#define SSD1306_SET_HCOL_START_ADDRESS                  0x10
#define SSD1306_MEMORY_ADDRESS_MODE                     0x20
#define SSD1306_SET_COLUMN_ADDRESS                      0x21
#define SSD1306_SET_PAGE_ADDRESS                        0x22
#define SSD1306_SET_PAGE_START_ADDRESS                  0xB0
#define SSD1306_SET_START_LINE                          0x40
#define SSD1306_SEGMENT_REMAP                           0xA0
#define SSD1306_SET_MULTIPLEX_RATIO                     0xA8
#define SSD1306_COM_SCAN_NORMAL                         0xC0
#define SSD1306_COM_SCAN_INVERSE                        0xC8
#define SSD1306_SET_DISPLAY_OFFSET                      0xD3
#define SSD1306_SET_COM_PINS_CONFIG                     0xDA
#define SSD1306_SET_DISPLAY_CLOCK_DIV                   0xD5
#define SSD1306_SET_PRECHARGE_PERIOD                    0xD9
#define SSD1306_SET_VCOM_DESELECT_LVL                   0xDB
#define SSD1306_NOP                                     0xE3
#define SSD1306_SET_CHARGE_PUMP                         0x8D

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL                         0x2F
#define SSD1306_DEACTIVATE_SCROLL                       0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA                0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL                 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL                  0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL    0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL     0x2A

