#ifndef SPI1_CONFIG_H
#define SPI1_CONFIG_H

/*
    options:-
    *UNIDIRECTIONAL_DATA_2_LINE
    *BIDIRECTIONAL_DATA_1_LINE
*/
#define BIDIRECTIONAL_DATA_MODE     UNIDIRECTIONAL_DATA_2_LINE
/*
    options:-
    *OUTPUT_DISABLED    (receive-only mode)
    *OUTPUT_ENABLED     (transmit-only mode)
*/
#define OUTPUT_BIDIERCTIONAL_MODE     OUTPUT_DISABLED
/*
    options:-
    *CRC_DISABLED
    *CRC_ENABLED
*/
#define  CRC_CALCULATION    CRC_DISABLED
/*
    options:-
    *DATA_PHASE            (no CRC phase)
    *NEXT_TRANSFER_IS_CRC  (CRC phase)
*/
#define  CRC_TRANSFER_NEXT     DATA_PHASE
/*
    options:-
    *DATA_FRAME_8_BIT
    *DATA_FRAME_16_BIT
*/
#define  DATA_FRAME   DATA_FRAME_8_BIT

/*
    options:-
    *FULL_DUPLEX            (Transmit and receive)
    *OUTPUT_DISABLED_RX        (Receive-only mode)
*/
#define  RXONLY     FULL_DUPLEX
/*
    options:-
    *ENABLED
    *DISABLED
*/
#define     SOFTWARE_SLAVE_MANAGEMENT   ENABLED
/*
    options:-
    *MSB
    *LSB
*/
#define LSBFIRST    LSB   
/*
    options:-
    * DIVIDED_BY_2
    * DIVIDED_BY_4
    * DIVIDED_BY_8
    * DIVIDED_BY_16
    * DIVIDED_BY_32
    * DIVIDED_BY_64
    * DIVIDED_BY_128
    * DIVIDED_BY_256
*/
#define     BUAD_RATE_CONTROL       DIVIDED_BY_2
/*
    options:-
    *MASTER 
    *SLAVE 
*/
#define MASTR_CONFIGRATION    MASTER        
/*
    options:-
    *CPOL_FALLING_EADGE 
    *CPOL_RISSING_EADGE 
    
*/   
#define CPOL        CPOL_FALLING_EADGE
/*
    options:-
    *CPHA_WRITE 
    *CPHA_READ    
*/
#define CPHA        CPHA_WRITE
#endif
