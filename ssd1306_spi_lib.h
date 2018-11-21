#ifndef SSD1306_SPI_LIB_H_
#define SSD1306_SPI_LIB_H_

void spi_init();
void spi_port_init();
void spi_transmit(unsigned char *params, unsigned char flag, unsigned char isData);

#endif /* SSD1306_SPI_LIB_H_ */
