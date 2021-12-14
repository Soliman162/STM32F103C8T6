#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\LIB\STM32F103C8.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

u8  LOC_u8Receive_String[20] ;

void UART_voidInit(void)
{
    UART1->CR1_UART &=0;
    SET_BIT(UART1->CR1_UART,13);
    SET_BIT(UART1->CR1_UART,3 );
    SET_BIT(UART1->CR1_UART,2 );
    UART1->CR1_UART |= (WORD_LENGTH <<12);
    UART1->CR1_UART |= (PARITY_CONTROL <<10);
    UART1->CR1_UART |= (PARITY_SELECTION <<9);

    UART1->CR2_UART &=0;
    UART1->CR2_UART |= (LIN_MODE <<14);
    UART1->CR2_UART |= (STOP_BIT <<13);

    UART1->BRR_UART = BAUD_RATE_VALUE;

}
void UART_enumTransmite(u8 Copy_u8Data)
{
    UART1->DR_UART = Copy_u8Data;
    while( GET_BIT(UART1->SR_UART,7) == 0 );
    while( GET_BIT(UART1->SR_UART,6) == 0 );

}
u8 UART_u8Receive(void)
{
    while( GET_BIT(UART1->SR_UART,5) == 0 );
    return (UART1->DR_UART);
}
ERROR_enumSTATE UART_enumTransimite_String(u8 * Copy_u8String)
{
    ERROR_enumSTATE LOC_enumError_STATE = STD_TYPES_OK;
    if( Copy_u8String != NULL )
    {
        u8 LOC_u8Iterator = 0;
        while( Copy_u8String[LOC_u8Iterator] != '\0' )
        {
            UART_enumTransmite(Copy_u8String[LOC_u8Iterator]);
            ++LOC_u8Iterator;
        }
    }else
    {
        LOC_enumError_STATE = STD_TYPES_NOK;
    }
    return LOC_enumError_STATE;
}
u8 * UART_ptrReceive_String(void)
{
    u8 LOC_u8Iterator = 0;
    while( UART_u8Receive() != 13)
    {
        LOC_u8Receive_String[LOC_u8Iterator] = UART_u8Receive();
        ++LOC_u8Iterator;
    }
    return LOC_u8Receive_String;

}
ERROR_enumSTATE UART_enumClearFlag( UART_FLAG_t Copy_enumFlag )
{
    ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
    if(Copy_enumFlag<=CTS_FLAG)
    {
        CLR_BIT(UART1->SR_UART,Copy_enumFlag);
    }else
    {
        LOC_enumError_State = STD_TYPES_NOK;
    }
    return LOC_enumError_State;
}
ERROR_enumSTATE UART_enumEnable_IRQ( UART_IRQ_t Copy_enumIRQ )
{
    ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
    if( Copy_enumIRQ <= PARITY_ERROR_IRQ )
    {
        SET_BIT(UART1->CR1_UART,Copy_enumIRQ);
    }else
    {
        LOC_enumError_State = STD_TYPES_NOK;
    }
    return LOC_enumError_State;
}
