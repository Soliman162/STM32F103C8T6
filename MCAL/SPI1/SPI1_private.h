#ifndef SPI1_PRIVATE_H
#define SPI1_PRIVATE_H
/********************************CR1_REG_PIN*******************************************/
/*BIDIRECTIONAL_DATA_MODE*/
#define UNIDIRECTIONAL_DATA_2_LINE  0b0000000000000000
#define BIDIRECTIONAL_DATA_1_LINE   0b1000000000000000
/*OUTPUT_BIDIERCTIONAL_MODE*/
#define OUTPUT_DISABLED             0b0000000000000000
#define OUTPUT_ENABLED              0b0100000000000000
/*CRC_CALCULATION*/
#define CRC_DISABLED                0b0000000000000000
#define CRC_ENABLED                 0b0010000000000000
/*CRC_TRANSFER_NEXT*/
#define DATA_PHASE                  0b0000000000000000   
#define NEXT_TRANSFER_IS_CRC        0b0001000000000000
/*DATA_FRAME*/
#define DATA_FRAME_8_BIT            0b0000000000000000
#define DATA_FRAME_16_BIT           0b0000100000000000
/*RXONLY*/
#define FULL_DUPLEX                 0b0000000000000000
#define OUTPUT_DISABLED_RX          0b0000010000000000
/*SOFTWARE_SLAVE_MANAGEMENT*/
#define DISABLED                    0b0000000000000000
#define ENABLED                     0b0000001000000000
/*LSBFIRST*/
#define MSB                         0b0000000000000000
#define LSB                         0b0000000010000000
/*BUAD_RATE_CONTROL*/
#define DIVIDED_BY_2                0b0000000000000000     
#define DIVIDED_BY_4                0b0000000000001000
#define DIVIDED_BY_8                0b0000000000010000
#define DIVIDED_BY_16               0b0000000000011000     
#define DIVIDED_BY_32               0b0000000000100000     
#define DIVIDED_BY_64               0b0000000000101000     
#define DIVIDED_BY_128              0b0000000000110000      
#define DIVIDED_BY_256              0b0000000000111000 
/*MASTR_CONFIGRATION*/
#define MASTER                      0b0000000000000100
#define SLAVE                       0b0000000000000000
/*CPOL*/
#define CPOL_FALLING_EADGE          0b0000000000000010
#define CPOL_RISSING_EADGE          0b0000000000000000
/*CPHA*/
#define CPHA_WRITE                  0b0000000000000001
#define CPHA_READ                   0b0000000000000000
/******************************************************************************************/
/******************************************************************************************/













/******************************************************************************************/

#endif
