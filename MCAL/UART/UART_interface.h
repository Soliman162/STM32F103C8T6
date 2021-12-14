#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

typedef enum{

    PARITY_ERROR=0,
    FRAMING_ERROR,
    NOISE_ERROR,
    OVERRUN_ERROR,
    IDLE_LINE_DETECTED,
    READ_DATA_REGISTER,
    TRANSMISSION_COMPLETE,
    TRANSMIT_DATA,
    LIN_BREAK_DETECTION,
    CTS_FLAG

}UART_FLAG_t;

typedef  enum{

    PARITY_ERROR_IRQ=8,
    TX_IRQ=7,
    TC_IRQ=6,
    RX_IRQ=5,
    IDIL_IRQ=4,

}UART_IRQ_t;

void UART_voidInit(void);
void UART_enumTransmite(u8 Copy_u8Data);
u8 UART_u8Receive(void);
ERROR_enumSTATE UART_enumTransimite_String(u8 *Copy_u8String);
u8 * UART_ptrReceive_String(void);
ERROR_enumSTATE UART_enumClearFlag( UART_FLAG_t Copy_enumFlag );
ERROR_enumSTATE UART_enumEnable_IRQ( UART_IRQ_t Copy_enumIRQ );


#endif