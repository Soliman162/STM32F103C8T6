/*******************************************************************************/
/******************* Name : Ahmed Elsayed **************************************/
/******************* Date : 6/8/2021      **************************************/
/******************* Version : 1.0v       **************************************/ 
/******************* SWC : NVIC_program.c **************************************/ 
/*******************************************************************************/
#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\LIB\STM32F103C8.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

#define SCB_u8_AIRCR_REG    *((volatile u32 *)(0xE000ED00 + 0x0C) )

ERROR_enumSTATE NVIC_voidEnableIRQ(IRQ_Type IRQn)
{
    ERROR_enumSTATE LOC_enumErrorState = STD_TYPES_OK;
    if( IRQn < MAX_u8_IRQ_NUM )
    {
        u8 LOC_u8Interrurt_REG = IRQn/32 ;
        u8 LOC_u8Interrurt_BIT = IRQn%32 ;

        NVIC->ISER[LOC_u8Interrurt_REG] = 1<<LOC_u8Interrurt_BIT;

    }else
    {
        LOC_enumErrorState = STD_TYPES_NOK;
    }
    return LOC_enumErrorState;

}

ERROR_enumSTATE NVIC_voidDisableIRQ(IRQ_Type IRQn)
{
    ERROR_enumSTATE LOC_enumErrorState = STD_TYPES_OK;
    if( IRQn <= MAX_u8_IRQ_NUM )
    {
        u8 LOC_u8Interrurt_REG = IRQn/32 ;
        u8 LOC_u8Interrurt_BIT = IRQn%32 ;

        NVIC->ICER[LOC_u8Interrurt_REG] = 1<<LOC_u8Interrurt_BIT;
    }else
    {
        LOC_enumErrorState = STD_TYPES_NOK;
    }
    return LOC_enumErrorState;
}

ERROR_enumSTATE NVIC_voidSetPendingIRQ(IRQ_Type IRQn)
{
    ERROR_enumSTATE LOC_enumErrorState = STD_TYPES_OK;
    if( IRQn < MAX_u8_IRQ_NUM )
    {
        u8 LOC_u8Interrurt_REG = IRQn/32 ;
        u8 LOC_u8Interrurt_BIT = IRQn%32 ;

        NVIC->ISPR[LOC_u8Interrurt_REG] = 1<<LOC_u8Interrurt_BIT;
    }else
    {
        LOC_enumErrorState = STD_TYPES_NOK;
    }
    return LOC_enumErrorState;

}

ERROR_enumSTATE NVIC_voidClearPendingIRQ(IRQ_Type IRQn)
{
    ERROR_enumSTATE LOC_enumErrorState = STD_TYPES_OK;
    if( IRQn < MAX_u8_IRQ_NUM )
    {
        u8 LOC_u8Interrurt_REG = IRQn/32 ;
        u8 LOC_u8Interrurt_BIT = IRQn%32 ;

        NVIC->ICPR[LOC_u8Interrurt_REG] = (1<<LOC_u8Interrurt_BIT);

    }else
    {
        LOC_enumErrorState = STD_TYPES_NOK;
    }
    return LOC_enumErrorState;

}

ERROR_enumSTATE NVIC_u8GetPendingIRQ(IRQ_Type IRQn ,u8 *COPY_ptru8DATA)
{
    ERROR_enumSTATE LOC_enumErrorState = STD_TYPES_OK;
    if( COPY_ptru8DATA != NULL )
    {
        if( IRQn < MAX_u8_IRQ_NUM )
        {    
            u8 LOC_u8Interrurt_REG = IRQn/32 ; 
            u8 LOC_u8Interrurt_BIT = IRQn%32 ; 

            *COPY_ptru8DATA = GET_BIT( NVIC->ICPR[LOC_u8Interrurt_REG] ,LOC_u8Interrurt_BIT );

        }else
        {
            LOC_enumErrorState = STD_TYPES_NOK;
        }
    }else
    {
        LOC_enumErrorState = STD_TYPES_NOK;
    }
    return LOC_enumErrorState;
}

ERROR_enumSTATE NVIC_u8GetActiveIRQ( IRQ_Type IRQn ,u8 *COPY_ptru8DATA)
{

    ERROR_enumSTATE LOC_enumErrorState = STD_TYPES_OK;
    if( IRQn <  MAX_u8_IRQ_NUM )
    {
        u8 LOC_u8Interrurt_REG = IRQn/32 ;
        u8 LOC_u8Interrurt_BIT = IRQn%32 ;

        *COPY_ptru8DATA = GET_BIT( NVIC->IABR[LOC_u8Interrurt_REG] ,LOC_u8Interrurt_BIT );

    }else
    {
        LOC_enumErrorState = STD_TYPES_NOK;
    }
    return LOC_enumErrorState;
}

ERROR_enumSTATE NVIC_SetPriority(IRQ_Type IRQn, Group_priority_t GROUP_u8priority, SUB_Priority_t SUB_u8priority)
{
    ERROR_enumSTATE LOC_enumErrorState = STD_TYPES_OK;
    if( IRQn <  MAX_u8_IRQ_NUM )
    {
        NVIC->IPR[IRQn] = ( ( GROUP_u8priority << 6 ) | ( SUB_u8priority << 4) );

    }else
    {
        LOC_enumErrorState = STD_TYPES_NOK;
    }

    return LOC_enumErrorState;
}
ERROR_enumSTATE NVIC_GetPriority(IRQ_Type IRQn,u8 *COPY_ptru8DATA)
{
    ERROR_enumSTATE LOC_enumErrorState = STD_TYPES_OK;
    if( IRQn <  MAX_u8_IRQ_NUM )
    {
        *COPY_ptru8DATA =   ( 0 | (NVIC->IPR[IRQn]) );
    }else
    {
        LOC_enumErrorState = STD_TYPES_NOK;
    }

    return LOC_enumErrorState;
}

void Init_priority_field(void)
{
    
    SCB_u8_AIRCR_REG = 0x05FA0500;
}
